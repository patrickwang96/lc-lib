#include "header.h"
// https://leetcode.com/problems/valid-sudoku/
class Solution {
private:
    int atoi(char c) {
        if (c == '.') return -1;
        else return (c - '0');
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int checker[9];
        memset(checker, 0, 9 * sizeof(int));
        int current;
        
        // Check each row
        for (int i = 0; i < 9; i++) {
            memset(checker, 0, 9 * sizeof(int));
            for (int j = 0; j < 9; j++) {
                current = atoi(board[i][j]);
                if (current < 0) continue;
                else if (checker[current - 1] == 0) checker[current - 1] = 1;
                else return false;
            } 
        }
        
        
        // Check each col
        for (int i = 0; i < 9; i++) {
            memset(checker, 0, 9 * sizeof(int));
            for (int j = 0; j < 9; j++) {
                current = atoi(board[j][i]);
                if (current < 0) continue;
                else if (checker[current - 1] == 0) checker[current - 1] = 1;
                else return false;
            } 
        }
        
        
        // Check each sub-boxes
         for (int i = 0; i < 9; i++) {
             memset(checker, 0, 9 * sizeof(int));
             int sub_row = i / 3;
             int sub_col = i % 3;
             for (int a = 0; a < 3; a++) {
                 for (int b = 0; b < 3; b++) {
                     current = atoi(board[sub_row * 3 + a][sub_col * 3 + b]);
                     if (current < 0) continue;
                     else if (checker[current - 1] == 0) checker[current - 1] = 1;
                     else return false;
                 }
             }
        }
        
        return true;
        
        
    }
};