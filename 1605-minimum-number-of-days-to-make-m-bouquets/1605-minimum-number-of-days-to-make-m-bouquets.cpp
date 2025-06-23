class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long) m*k>bloomDay.size())
        return -1;
         int low=*min_element(bloomDay.begin(),bloomDay.end());
         int high=*max_element(bloomDay.begin(),bloomDay.end());
         while(low<=high){
             int mid=low+(high-low)/2;
             if(isValid(bloomDay,m,k,mid)){
                   high=mid-1;
             }else{
                low=mid+1;
             }
         }
         return low;
    }
     bool isValid(vector<int>&bloomDay,int m,int k,int mid){
         int bouquets=0;
         int flowers=0;
         for(int day:bloomDay){
             if(day<=mid){
                flowers++;
                if(flowers==k){
                    bouquets++;
              flowers=0;
              if(bouquets>=m)
               return true;      
                }
             }else{
                flowers=0;
             }
         }
         return false;
     }
};