class Solution {
public:
    int solve(string str) {
        int count = 0;
        for (char ch : str) {
            if (ch == '1') count++;
        }
        return count;
    }

    int numberOfBeams(vector<string>& bank) {
        int prev = 0;  
        int curr = 0; 
        int n = bank.size();
        int ans = 0;  

        for (int i = 0; i < n; i++) {
            curr = solve(bank[i]);
            ans += (curr * prev);
            if (curr) prev = curr;
        }

        return ans;
    }
};