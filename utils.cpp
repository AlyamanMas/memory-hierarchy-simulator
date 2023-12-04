#include "utils.h"

#include <fstream>
#include <cstdint>

void access_sequence(MemoryCacheUnit &cache, std::vector <uint32_t> &addresses_sequence) {
    for (const auto &address : addresses_sequence) {
        cache.access(address);
    }
}

std::vector<uint32_t> read_seq(const std::string& file_name, uint8_t base) {
    std::vector<uint32_t> addresses_sequence;
    std::ifstream file(file_name);
    std::string line;
    while (std::getline(file, line, ',')) {
        addresses_sequence.push_back(std::stoul(line, nullptr, base));
    }
    return addresses_sequence;
}
