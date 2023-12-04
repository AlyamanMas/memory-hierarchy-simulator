#include "MemoryCacheEntry.h"

bool MemoryCacheEntry::is_valid() const {
    return this->valid;
}

uint32_t MemoryCacheEntry::get_tag() const {
    return this->tag;
}

void MemoryCacheEntry::set_tag(uint32_t tag) {
    this->tag = tag;
    this->valid = true;
}

void MemoryCacheEntry::set_valid(bool valid) {
    this->valid = valid;
}
