#ifndef MEMORY_HIERARCHY_SIMULATOR_MEMORYCACHEENTRY_H
#define MEMORY_HIERARCHY_SIMULATOR_MEMORYCACHEENTRY_H

#include <cstdint>

class MemoryCacheEntry {
private:
    bool valid;
    uint32_t tag;
public:
    explicit MemoryCacheEntry(uint32_t block_size) : valid(false), tag(0) {};

    void set_tag(uint32_t tag);

    void set_valid(bool valid);

    [[nodiscard]] bool is_valid() const;

    [[nodiscard]] uint32_t get_tag() const;
};

#endif //MEMORY_HIERARCHY_SIMULATOR_MEMORYCACHEENTRY_H
