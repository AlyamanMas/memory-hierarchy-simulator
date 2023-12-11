#include "CacheEntry.h"

bool CacheEntry::is_valid() const {
    return this->valid;
}

uint32_t CacheEntry::get_tag() const {
    return this->tag;
}

void CacheEntry::set_tag(uint32_t tag) {
    this->tag = tag;
    this->valid = true;
}

void CacheEntry::set_valid(bool valid) {
    this->valid = valid;
}
