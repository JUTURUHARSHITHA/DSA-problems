class Solution {
    void generating(int n, int open, int closed, vector<string> &ans, string &temp) {
        if (open == n && closed == n) {
            ans.push_back(temp);
            return;
        }
        if (open < n) { 
            temp.push_back('(');
            generating(n, open + 1, closed, ans, temp);
            temp.pop_back(); 
        }
        if (closed < open) {
            temp.push_back(')');
            generating(n, open, closed + 1, ans, temp);
            temp.pop_back();
        }
    } 
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        generating(n, 0, 0, ans, temp); 
        return ans;
    }
};