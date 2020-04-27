#include "header.h"
class LRUCache {
private:
    int cap;
    list<pair<int, int>> dl;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    
public:
    LRUCache(int capacity): cap(capacity) {
    }
    
    int get(int key) {
        auto iter = map.find(key);
        if (iter == map.end()) return -1;
        dl.splice(dl.begin(), dl, iter->second);
        return iter->second->second;
        
    }
    
    void put(int key, int value) {
        
        if (map.count(key) != 0) {
            map[key]->second = value;
            dl.splice(dl.begin(), dl, map[key]);
            return ;
        }
        
        if (dl.size() == cap) {
            map.erase(dl.rbegin()->first);
            dl.pop_back();
        }
        dl.push_front({key, value});
        map[key] = dl.begin();
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */