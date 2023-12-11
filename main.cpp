#include <iostream>

#include "CacheUnit.h"
#include "utils.h"

using namespace std;

int main() {
    cout << "Please enter the total cache size in bytes: ";
    uint32_t cache_size;
    cin >> cache_size;

    cout << "Please enter the cache line/block size in bytes: ";
    uint32_t block_size;
    cin >> block_size;

    cout << "Please enter the number of cycles to access the cache: ";
    uint32_t cycles_to_access;
    cin >> cycles_to_access;

    const auto cache_from_slides = make_unique<CacheUnit>(block_size, cache_size, cycles_to_access);

    cout << "Please enter the full path of the file you want to get the sequence from: ";
    string file_name;
    cin >> file_name;

    cout << "Please enter the base of the addresses in the file: ";
    // Make the base 16 bits because if it's 8 bits, cin treats it as a character
    uint16_t base;
    cin >> base;

    auto addresses_sequence = read_seq(file_name, base);
    access_sequence(*cache_from_slides, addresses_sequence);
    return 0;
}
