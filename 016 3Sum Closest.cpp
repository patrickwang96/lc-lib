
// https://leetcode.com/problems/3sum-closest/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = INT_MIN;
        int a, b;
        int delta;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            a = i + 1;
            b = nums.size() - 1;
            while (a < b) {
                if (result == INT_MIN) result = nums[i] + nums[a] + nums[b];
                delta = abs(target - (nums[i] + nums[a] + nums[b]));
                if (delta < abs(target - result)) {
                    result  = nums[i] + nums[a] + nums[b];
                }
                
                if (nums[i] + nums[a] + nums[b] > target) b--;
                else if(nums[i] + nums[a] + nums[b] < target) a++;
                else break;
            }
        }
        return result;
    }
};