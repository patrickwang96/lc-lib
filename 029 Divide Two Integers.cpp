
// https://leetcode.com/problems/divide-two-integers/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (dividend == divisor) return 1;
        if (divisor == 2) return dividend >> 1;
        bool sign1 = dividend > 0;
        bool sign2 = divisor > 0;
        
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (divisor == INT_MIN) return 0;
        
        bool overflow = dividend == INT_MIN ? true : false;
        int dd;
        if (overflow) dd = abs(dividend + 1);
        else dd = abs(dividend);
        int ds = abs(divisor);
        
        dd -= ds;
        if (overflow) dd++;
        int result = 0;
        while (dd >= 0) {
            dd -= ds;
            result ++;
        }
        if (sign1 ^ sign2) return -1 * result;
        else return result;
    }
};