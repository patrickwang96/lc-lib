#include "header.h"
class Vector2D {
private:
    vector<int> ary;
    int len;
    int cur;
public:
    Vector2D(vector<vector<int>>& v) {
        int n = v.size();
        cur = 0;
        len = 0;
        for (auto vec:v) len += vec.size();
        
        ary.reserve(len);
        auto ptr = ary.data();
        
        for (auto vec: v) {
            if (vec.size()){
                memcpy(ptr, vec.data(), sizeof(int) * vec.size());
                ptr += vec.size();
            }
        }
        
    }
    
    int next() {
        return ary[cur++];  
    }
    
    bool hasNext() {
        return cur < len;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */