#include "header.h"

// TODO there is also a state transition solution. 
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        if (K == 0) return 1;
        
        vector<vector<double>> dp (N, vector<double>(N, 1));
        vector<pair<int, int>> moves{{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
        
        for (int round = 0; round < K; round++) {
            vector<vector<double>> tmp(N, vector<double>(N, 0));
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    for (auto move: moves) {
                        auto a = i + move.first;
                        auto b = j + move.second;
                        
                        if (a < 0 || a >= N || b < 0 || b >= N) continue;
                        tmp[i][j] += dp[a][b];
                    }
                }
            }
            dp = tmp;
        }
        // bit overflowed
        // unsigned long long base = (unsigned long long)1 << (3 * K);
        
        return dp[r][c] / pow(8, K);
           
        
    }
};