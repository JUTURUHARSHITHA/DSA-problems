typedef long long ll;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll ans = 0;
        ll cur = 0, l = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            while (cur * (i - l + 1) >= k) {
                cur -= nums[l];
                l += 1;
            }
            ans += i - l + 1;
        }
        return ans;
    }
};