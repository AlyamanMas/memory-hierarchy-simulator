#ifndef MEMORY_HIERARCHY_SIMULATOR_UTILS_H
#define MEMORY_HIERARCHY_SIMULATOR_UTILS_H

#include <vector>
#include <cstdint>

#include "MemoryCacheUnit.h"

void access_sequence(MemoryCacheUnit &cache, std::vector<uint32_t> &addresses_sequence);

std::vector<uint32_t> read_seq(const std::string& file_name, uint8_t base = 10);

#endif //MEMORY_HIERARCHY_SIMULATOR_UTILS_H
