class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> numswithindices;
        for (int i = 0; i < n; i++) {
            numswithindices.push_back({nums[i], i});
        }
        sort(numswithindices.begin(), numswithindices.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        vector<pair<int, int>> topk(numswithindices.begin(), numswithindices.begin() + k);
        sort(topk.begin(), topk.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        vector<int> res;
        for (auto& p : topk) {
            res.push_back(p.first);
        }
        return res;
    }
};
