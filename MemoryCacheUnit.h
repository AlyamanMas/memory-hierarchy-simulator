#ifndef MEMORY_HIERARCHY_SIMULATOR_MEMORYCACHEUNIT_H
#define MEMORY_HIERARCHY_SIMULATOR_MEMORYCACHEUNIT_H

#define MEMORY_ADDRESS_BITS 24
#define MAIN_MEMORY_CYCLES_TO_ACCESS 120
#define PRINT_AFTER_ACCESS 1

#include <vector>
#include <cstdint>
#include <optional>
#include <memory>

#include "MemoryCacheEntry.h"

class MemoryCacheUnit {
private:
    std::vector<MemoryCacheEntry> cache_entries;
    uint32_t block_size;
    uint32_t num_of_blocks;
    uint32_t cycles_if_hit;
    uint32_t num_of_hits;
    uint32_t num_of_misses;
public:
    MemoryCacheUnit(uint32_t block_size, uint32_t cache_size, uint32_t cycles_to_access);

    [[nodiscard]] uint32_t get_block_size() const;

    [[nodiscard]] uint32_t get_num_of_blocks() const;

    [[nodiscard]] uint32_t get_cycles_if_hit() const;

    [[nodiscard]] uint32_t get_num_of_hits() const;

    [[nodiscard]] uint32_t get_num_of_misses() const;

    [[nodiscard]] uint32_t get_num_of_accesses() const;

    bool access(uint32_t address);

    void print_cache();
};

#endif //MEMORY_HIERARCHY_SIMULATOR_MEMORYCACHEUNIT_H
