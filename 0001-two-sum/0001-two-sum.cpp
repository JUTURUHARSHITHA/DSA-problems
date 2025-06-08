// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
        // //brute force 
        //  int n= nums.size();
        //   for(int i=0;i<n-1;i++){
        //       for(int j=i+1;j<n;j++){
        //           if(nums[i]+ nums[j]== target){
        //               return{i,j};
        //           }
        //       }
        //   }
        //     return {};
//     }
// };
// optimal approach:
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        sort(a.begin(), a.end());

        int left = 0, right = n - 1;
        while (left < right) {
            int sum = a[left].first + a[right].first;
            if (sum == target) {
                int idx1 = a[left].second;
                int idx2 = a[right].second;
                if (idx1 > idx2) swap(idx1, idx2);
                return {idx1, idx2};  
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {}; 
    }
};