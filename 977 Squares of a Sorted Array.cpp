#include "header.h"
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        
        int firstPos = 0;
        while (firstPos < A.size()) {
            if (A[firstPos] <= 0) firstPos++;
            else break;
        }
        vector<int> negVec(A.rbegin() + A.size() - firstPos, A.rend());
        vector<int> posVec(A.begin() + firstPos, A.end());
        
        for (int i = 0; i < negVec.size(); i++) negVec[i] = negVec[i] * negVec[i];
        for (int i = 0; i < posVec.size(); i++) posVec[i] = posVec[i] * posVec[i];
        
        
        int p1 = 0;
        int p2 = 0;
        int counter = 0;
        
        while (p1 < negVec.size() && p2 < posVec.size()) {
            if (negVec[p1] < posVec[p2]) A[counter++] = negVec[p1++];
            else A[counter++] = posVec[p2++];
        }
        while (p1 < negVec.size()) A[counter++] = negVec[p1++];
        while (p2 < posVec.size()) A[counter++] = posVec[p2++];
        
        return A;
    }
};