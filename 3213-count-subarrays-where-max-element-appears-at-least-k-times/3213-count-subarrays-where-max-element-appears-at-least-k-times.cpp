class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long maxi=*max_element(nums.begin(),nums.end());
        
        int l=0,s=0;
         long long count_m=0,result=0;
         for(s=0;s<nums.size();s++){
            if(nums[s]==maxi){
                count_m++;
            }
            while(count_m>=k){
                if(nums[l]==maxi){
                    count_m--;
                }
                l++;
                
            }
          result+=l;

         }
         return result;


    }
};