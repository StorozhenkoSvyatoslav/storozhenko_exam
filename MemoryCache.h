#ifndef MEMORYCACHE_H
#define MEMORYCACHE_H

#include <string>
#include <map>

class MemoryCache {
private:
    static MemoryCache* instance;
    std::map<std::string, std::string> cache;
    int maxSize = 100;

    MemoryCache() {}
    MemoryCache(const MemoryCache&) = delete;
    MemoryCache& operator=(const MemoryCache&) = delete;

public:
    static MemoryCache* getInstance();

    void put(const std::string& key, const std::string& value);
    std::string get(const std::string& key);
    void remove(const std::string& key);
    void clear();
    int size();
    bool contains(const std::string& key);
    void setMaxSize(int size);
};

#endif
