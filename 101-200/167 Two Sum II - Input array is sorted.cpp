#include "header.h"
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
class Solution {
public:
    
    int findIndex(vector<int>&numbers, int target, int index){
        if((numbers.size() - index)>10){
            int result = (numbers.size() - index)/2 + index;
        int tmp = (numbers.size()-result)/2 + result;
        if(target > numbers[result] && target > tmp)
            findIndex(numbers, target, result);
        else if(target > numbers[result]) return result;
        else return index;
        }
        return index;
    }
    bool unsolved(vector<int>&numbers,int checker){
        for(int i = 0; i<numbers.size(); i++)
            if(numbers[i] == checker) return true;
        return false;
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        int diff=0,a,b;
        bool find = false;
        vector<int> unsolve;
        for(int i=0; i<numbers.size(); i++){
            a=i;
            if(i>1 &&numbers[i] == numbers[i-1]) continue;
            if(unsolved(unsolve,numbers[i])) continue;
            diff = target - numbers[i];
            for(int j=findIndex(numbers,diff,i+1); j < numbers.size(); j++){
                if(numbers[i] + numbers[j] == target){
                    find = true;
                    b=j;
                    break;
                }
                if(j == numbers.size()) unsolve.push_back(numbers[i]);
            }
            if(find) break;
        }
        a++;b++;
        vector<int> result;
        result.push_back(a);
        result.push_back(b);
        return result;
    }
};