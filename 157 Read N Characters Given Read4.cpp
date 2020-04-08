#include "header.h"
// https://leetcode.com/problems/read-n-characters-given-read4/
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int result = 0, cur = 0;
        while (result < n) {
            cur = read4(buf+result);
            if (cur == 0) break;
            result += cur;
             
        }
        return min(result, n);
    }
};