class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int cadi, cnt=0,n=nums.size();
          
        for(int i=0;i<n;i++){
             if(cnt==0) cadi=nums[i];
             if(nums[i]==cadi) cnt++;
             else cnt--;
        }
        return cadi;
    }
};