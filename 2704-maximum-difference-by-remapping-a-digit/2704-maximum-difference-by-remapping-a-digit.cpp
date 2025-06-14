class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        bool key = true;
        char replace = ' ', with = '9';
        string max, min;
        char c = s[0];

        for (int i = 0 ; i < s.length() ; i++) {
            if (s[i] != '9' && key) {
                replace = s[i];
                key = false;
            }
            if (s[i] == replace) {
                max += '9';
            } else {
                max += s[i];
            }
            if (s[i] == c) {
                min += '0';
            } else {
                min += s[i];
            }
        }
        return stoi(max) - stoi(min);
    }
};