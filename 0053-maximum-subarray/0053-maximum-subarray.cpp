class Solution {
public:
    int maxSubArray(vector<int>& nums){
         int maxsum=INT_MIN;
         int curr=0;

         for( int num:nums){
             curr=max(num,curr+num);
             maxsum=max(maxsum,curr);
         }
          return maxsum;
    }
};
  