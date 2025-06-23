#include "MemoryCache.h"
#include <stdexcept>

MemoryCache* MemoryCache::instance = nullptr;

MemoryCache* MemoryCache::getInstance() {
    if (!instance) {
        instance = new MemoryCache();
    }
    return instance;
}

void MemoryCache::put(const std::string& key, const std::string& value) {
    if (cache.size() >= maxSize) {
        throw std::overflow_error("Cache is full");
    }
    cache[key] = value;
}

std::string MemoryCache::get(const std::string& key) {
    if (!contains(key)) {
        throw std::out_of_range("Key not found");
    }
    return cache[key];
}

void MemoryCache::remove(const std::string& key) {
    cache.erase(key);
}

void MemoryCache::clear() {
    cache.clear();
}

int MemoryCache::size() {
    return cache.size();
}

bool MemoryCache::contains(const std::string& key) {
    return cache.find(key) != cache.end();
}

void MemoryCache::setMaxSize(int size) {
    maxSize = size;
}
