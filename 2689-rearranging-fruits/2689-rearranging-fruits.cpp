class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
         map<int, int> t_cnt;
         for(int fruit : basket1)t_cnt[fruit]++;
         for(int fruit : basket2)t_cnt[fruit]++;
          long long min_val=LLONG_MAX;
          for(auto const&[fruit,cnt]:t_cnt){
            if(cnt%2!=0)
             return -1;
              min_val=min(min_val,(long long)fruit);
          }
          vector<long long>fruits_to_swap;
          map<int,int>count1;
          for(int fruit:basket1)count1[fruit]++;
          for(auto const&[fruit,t_cnt]:t_cnt){
            int diff=count1[fruit]-(t_cnt/2);
           for(int i=0;i<abs(diff);++i){
            fruits_to_swap.push_back(fruit);
           } 
          }
           sort(fruits_to_swap.begin(),fruits_to_swap.end());
            long long t_cost=0;
            int swap_to_make=fruits_to_swap.size()/2;
            for(int i=0;i<swap_to_make;++i){
                 t_cost+=min(fruits_to_swap[i],2*min_val);
            }
              return t_cost;
    }
};