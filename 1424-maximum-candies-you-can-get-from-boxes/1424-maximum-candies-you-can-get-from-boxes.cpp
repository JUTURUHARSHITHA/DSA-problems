class Solution {
public:
    int maxCandies(vector<int>& stat,
                   vector<int>& choco,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& curBoxes)
    {
        int n = stat.size();
        deque<int> dq;
        vector<int> vis(n, 0);
        for (int b : curBoxes) {
            if (!vis[b]) {
                vis[b] = 1;
                if (stat[b] == 0)    dq.push_back(b);
                else                 dq.push_front(b);
            }
        }

        int ans = 0;
        bool madeProgress = true;
        while (madeProgress) {
            madeProgress = false;
            int sz = dq.size();
            for (int i = 0; i < sz; i++) {
                int box = dq.front();
                dq.pop_front();

                if (stat[box] == 0) {
                    dq.push_back(box);
                    continue;
                }
                madeProgress = true;
                ans += choco[box];
                for (int k : keys[box]) {
                    stat[k] = 1;
                }
                for (int nb : containedBoxes[box]) {
                    if (!vis[nb]) {
                        vis[nb] = 1;
                        if (stat[nb] == 0)    dq.push_back(nb);
                        else                  dq.push_front(nb);
                    }
                }
            }
        }

        return ans;
    }
};