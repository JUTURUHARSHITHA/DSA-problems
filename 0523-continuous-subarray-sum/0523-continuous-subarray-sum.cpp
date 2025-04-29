class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2)
            return false;

        unordered_map<int, int> mp;
        mp[0] = -1;
        int running_sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            running_sum += nums[i];
            if (k != 0)
                running_sum %= k;

            if (mp.find(running_sum) != mp.end()) {
                if (i - mp[running_sum] >= 2)
                    return true;
            } else {
                mp[running_sum] = i;
            }
        }
        return false;
    }
};
