class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
         vector<string>res;
        int n= words.size();

        if(n==0)
         return res;

          int lastGroup=-1;
       for( int i=0;i<n;++i){
         if(res.empty()){
             res.push_back(words[i]);
              lastGroup=groups[i];
         }else{
             if(groups[i]!=lastGroup){
                 res.push_back(words[i]);
                  lastGroup=groups[i];
             }
         }
       }
        return res;
    }
     
};