class Solution {
public:
   const  int MOD=1e9+7;
     void generatestates(int m,vector<vector<int>>& states, vector<int>&curr){
         if(curr.size()==m){
             states.push_back(curr);
              return;
         }
          for(int color=0;color<3;++color){
              if(!curr.empty()&&curr.back()==color)
               continue;
                curr.push_back(color);
                 generatestates(m,states,curr);
                  curr.pop_back();
          }
     }
       bool isValidTransition(const vector<int>&a,const vector<int>&b){
           for( int i=0;i<a.size();++i)
            if(a[i]==b[i])
             return false;
               return  true;
       }

    int colorTheGrid(int m, int n) {
        vector<vector<int>>states;
         vector<int> curr;
          generatestates(m,states,curr);

           int S=states.size();
            vector<vector<int>>transition(S);
             for( int i=0;i<S;++i){
                for( int j=0;j<S;++j){
                     if(isValidTransition(states[i],states[j])){
                         transition[i].push_back(j);
                     }
                }
             }
              vector<int>dp(S,1);
               for(int col=1;col<n;++col){
                 vector<int>new_dp(S,0);
                  for(int i=0;i<S;++i){
                     for( int j:transition[i]){
                         new_dp[j]= (new_dp[j]+dp[i])%MOD;
                     }
                  }
                   dp=new_dp;
               }
        
         int res=0;
          for( int val:dp) res=(res+val)%MOD;
           return res;
    }
};