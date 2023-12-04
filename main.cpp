#include <iostream>

#include "MemoryCacheUnit.h"

using namespace std;

int main() {
    const auto l1_cache = make_unique<MemoryCacheUnit>(4, 1024, 10);
    l1_cache->access(0);
    l1_cache->access(4);
    l1_cache->access(8);
    l1_cache->access(12);
    l1_cache->access(16);
    l1_cache->access(0x1000);
    return 0;
}
