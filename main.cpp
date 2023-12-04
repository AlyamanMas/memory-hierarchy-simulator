#include <iostream>

#include "MemoryCacheUnit.h"

using namespace std;

int main() {
    const auto l1_cache = make_unique<MemoryCacheUnit>(4, 1024, 10);
//    l1_cache->access(0);
//    l1_cache->access(4);
//    l1_cache->access(8);
//    l1_cache->access(12);
//    l1_cache->access(16);
//    l1_cache->access(0x1000);
    const auto cache_from_slides = make_unique<MemoryCacheUnit>(1, 8, 10);
    cache_from_slides->access(22);
    cache_from_slides->access(26);
    cache_from_slides->access(22);
    cache_from_slides->access(26);
    cache_from_slides->access(16);
    cache_from_slides->access(3);
    cache_from_slides->access(16);
    cache_from_slides->access(18);
    return 0;
}
