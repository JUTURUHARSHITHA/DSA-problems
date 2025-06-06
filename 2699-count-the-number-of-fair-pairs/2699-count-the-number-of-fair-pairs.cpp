class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = 0;
        long long res = 0;

        for (int i = n - 1; i > 0; --i) {
            if (nums[i] + nums[i - 1] < lower) break;
            if (nums[i] + nums[l] > upper) continue;

            while (r < i && nums[r] + nums[i] <= upper) ++r;
            if (r == i || nums[r] + nums[i] > upper) --r;
            while (l <= r && nums[l] + nums[i] < lower) ++l;

            if (l <= r) res += (r - l + 1);
        }

        return res;
    }
};