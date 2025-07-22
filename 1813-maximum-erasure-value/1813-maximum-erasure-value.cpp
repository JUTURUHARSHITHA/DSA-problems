class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       unordered_set<int>seen;
       int left=0;
       int right=0;
       int  sum=0;
       int currsum=0;
       while( right<nums.size()){
         if(seen.find(nums[right])==seen.end()){
             seen.insert(nums[right]);
             currsum+=nums[right];
              sum = max(sum, currsum);
             right++;
         }
         else{
            seen.erase(nums[left]);
            currsum-=nums[left];
            left++;
         }
       }
        return sum;    
    }
};