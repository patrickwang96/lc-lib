#include "header.h"
// https://leetcode.com/problems/word-search/
class Solution {
private:
    bool dfs(string word, int x, int y, int m, int n, vector<vector<char>>& board) {
        if (x < 0 || y < 0) return false;
        if (x >= m || y >= n) return false;
        if (word[0] != board[x][y]) return false;
        if (word.size() == 1) return true;
        char tmp = board[x][y];
        board[x][y] = '.';
        
        if (dfs(word.substr(1), x-1,y,m,n,board)) return true;
        else if (dfs(word.substr(1), x+1,y,m,n,board)) return true;
        else if (dfs(word.substr(1), x,y-1,m,n,board)) return true;
        else if (dfs(word.substr(1), x,y+1,m,n,board)) return true;
        
        else {
            board[x][y] = tmp;
            return false;
        }
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
    
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(word, i, j, m, n, board)) return true;
            }
        }
        return false;
        
    }
};