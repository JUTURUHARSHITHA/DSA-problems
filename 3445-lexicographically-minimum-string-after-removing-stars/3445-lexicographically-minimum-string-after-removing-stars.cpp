class Solution {
public:
    class cmp {
    public:
        bool operator()(pair<char, int> &a, pair<char, int> &b) {
            if (a.first > b.first) return true;
            else if (a.first == b.first && a.second < b.second) return true;
            return false;
        }
    };

    string clearStars(string s) {
        int n = s.size();
        map<int, char> mp;
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;

        for (int i = 0; i < n; i++) {
            if (s[i] != '*')
                mp[i] = s[i];
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                char ch = pq.top().first;
                int index = pq.top().second;
                pq.pop();
                mp.erase(index);
            }
            else
                pq.push({s[i], i});
        }

        string ans = "";
        for (auto it : mp) {
            ans += it.second;
        }

        return ans;
    }
};