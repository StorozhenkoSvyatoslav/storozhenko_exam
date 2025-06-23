#include <iostream>
#include "MemoryCache.h"

int main() {
    MemoryCache* cache = MemoryCache::getInstance();

    cache->put("key1", "value1");
    cache->put("key2", "value2");

    std::cout << "Size: " << cache->size() << std::endl;
    std::cout << "key1: " << cache->get("key1") << std::endl;

    cache->remove("key1");
    std::cout << "Contains key1: " << cache->contains("key1") << std::endl;

    cache->clear();
    std::cout << "Size after clear: " << cache->size() << std::endl;

    return 0;
}
