class Solution {
public:
    int maxDifference(string s) {
         vector<int>freq(26,0);
          for(char c:s){
             freq[c-'a']++;
          }
           int maxodd=INT_MIN;
           int mineven=INT_MAX;
            for(int fre:freq){
                 if(fre>0){
                 if(fre%2==0){
                     if(fre<mineven){
                         mineven=fre;
                     }
                 } else {
                     if(fre>maxodd){
                        maxodd=fre;
                     }
                   }
                 }
              }
               if(maxodd==INT_MIN || mineven==INT_MAX){
                return 0;
               }
                return maxodd-mineven;
    }
};