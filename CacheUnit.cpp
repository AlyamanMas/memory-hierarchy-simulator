#include "CacheUnit.h"

#include <memory>
#include <cmath>
#include <iostream>

using namespace std;

CacheUnit::CacheUnit(uint32_t block_size, uint32_t cache_size, uint32_t cycles_to_access)
        : block_size(block_size),
          num_of_blocks(cache_size / block_size),
          cycles_if_hit(cycles_to_access),
          num_of_hits(0),
          num_of_misses(0) {
    for (int i = 0; i < this->num_of_blocks; ++i) {
        this->cache_entries.emplace_back();
    }
}

uint32_t CacheUnit::get_block_size() const {
    return this->block_size;
}

uint32_t CacheUnit::get_num_of_blocks() const {
    return this->num_of_blocks;
}

uint32_t CacheUnit::get_cycles_if_hit() const {
    return this->cycles_if_hit;
}

uint32_t CacheUnit::get_num_of_hits() const {
    return this->num_of_hits;
}

uint32_t CacheUnit::get_num_of_misses() const {
    return this->num_of_misses;
}

uint32_t CacheUnit::get_num_of_accesses() const {
    return this->num_of_hits + this->num_of_misses;
}

bool CacheUnit::access(uint32_t address) {
    uint8_t display_width = floor(log2(this->block_size));
    uint8_t index_width = floor(log2(this->num_of_blocks));

    uint32_t tag = address >> (index_width + display_width);
    uint32_t index = (address >> display_width) & ((1 << index_width) - 1);

    if (this->cache_entries[index].is_valid() && this->cache_entries[index].get_tag() == tag) {
        // case hit
        this->num_of_hits++;
#ifdef PRINT_AFTER_ACCESS
        printf("Address: %#08x/%u: Hit!\n", address, address);
        this->print_cache();
#endif
        return true;
    } else {
        // case miss
        this->num_of_misses++;
        this->cache_entries[index].set_tag(tag);
        this->cache_entries[index].set_valid(true);
#ifdef PRINT_AFTER_ACCESS
        printf("Address: %#08x/%u: Miss!\n", address, address);
        this->print_cache();
#endif
        return false;
    }
}

void CacheUnit::print_cache() {
    // Print some info
    cout << "Total number of accesses: " << this->get_num_of_accesses() << endl;
    cout << "Number of hits: " << this->get_num_of_hits() << endl;
    cout << "Number of misses: " << this->get_num_of_misses() << endl;
    cout << "Hit ratio: " << (double) this->get_num_of_hits() / this->get_num_of_accesses() << endl;
    cout << "Miss ratio: " << (double) this->get_num_of_misses() / this->get_num_of_accesses() << endl;
    cout << "Average memory access time (AMAT) in cycles: " <<
         (this->get_cycles_if_hit() * this->get_num_of_hits() +
          this->get_num_of_misses() * MAIN_MEMORY_CYCLES_TO_ACCESS) /
         this->get_num_of_accesses() << endl;

    // Print table
    printf("|------------|------------|--------|\n"
           "| Index      | Tag        | Valid  |\n"
           "|------------|------------|--------|\n");
    for (int index = 0; index < this->get_num_of_blocks(); ++index) {
        printf(
                "|%#11x |%#11x | %-7s|\n",
                index,
                this->cache_entries[index].get_tag(),
                this->cache_entries[index].is_valid() ? "true" : "false"
        );
    }
    printf("|------------|------------|--------|\n\n");
}
