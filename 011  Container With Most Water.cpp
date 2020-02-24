
// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int start_bar = 0;
        int end_bar = len - 1;
        int result = 0;
        while (start_bar != end_bar) {
            result = max(result, calWater(start_bar, end_bar, height));
            if (height[start_bar] < height[end_bar]) start_bar++;
            else end_bar--;
        }
        return result;
    }
private:
    int calWater(int a, int b, vector<int>& height) {
        // a and b are 0 indexed
        int delta = abs(a - b);
        int min_height = min(height[a], height[b]);
        return delta * min_height;
    }
};