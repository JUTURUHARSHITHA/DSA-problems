class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        
        string result = "";
        stack<char> st;
        char minChar = 'a';
        
        for (char c : s) {
            st.push(c);
            freq[c - 'a']--;
            
            while (minChar <= 'z' && freq[minChar - 'a'] == 0)
                minChar++;
            
            while (!st.empty() && st.top() <= minChar) {
                result += st.top();
                st.pop();
            }
        }
        
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        return result;
    }
};