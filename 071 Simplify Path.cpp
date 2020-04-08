#include "header.h"
// https://leetcode.com/problems/simplify-path/
class Solution {
public:
    string simplifyPath(string path) {
        
        vector<string> dirs;
        stringstream ss(path.substr(1));
        string tmp;
        while(getline(ss, tmp, '/')) {
            if (tmp == ".." && dirs.size()) dirs.pop_back();
            else if (tmp == "..") continue;
            else if(tmp.size() == 0 || tmp == ".") continue;
            else dirs.push_back(tmp);
        }
        string result;
        for (auto s: dirs) {
            result += "/";
            result += s;
        }
        if (!result.size()) result = "/";
        return result;
    }
};