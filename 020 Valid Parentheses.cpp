
// https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        string left_char = "({[";
        string right_char = ")}]";
        
        for (auto c: s) {
            if (left_char.find(c) != string::npos) {
                stack.push(c);
            }
            else {
                if (stack.empty() || stack.top() != left_char[right_char.find(c)]) return false;
                else stack.pop();
            }
        }
        if (stack.empty()) return true;
        else return false;
    }
};