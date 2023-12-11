#ifndef MEMORY_HIERARCHY_SIMULATOR_CACHEENTRY_H
#define MEMORY_HIERARCHY_SIMULATOR_CACHEENTRY_H

#include <cstdint>

class CacheEntry {
private:
    bool valid;
    uint32_t tag;
public:
    explicit CacheEntry() : valid(false), tag(0) {};

    void set_tag(uint32_t tag);

    void set_valid(bool valid);

    [[nodiscard]] bool is_valid() const;

    [[nodiscard]] uint32_t get_tag() const;
};

#endif //MEMORY_HIERARCHY_SIMULATOR_CACHEENTRY_H
