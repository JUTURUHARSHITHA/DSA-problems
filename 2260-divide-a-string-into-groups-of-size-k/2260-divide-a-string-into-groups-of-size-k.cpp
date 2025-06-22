class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
      vector<string>res;
       int n=s.length();
       for( int i=0;i<n;i+=k){
         string group =s.substr(i,k);
         if(group.length()<k){
             group.append(k-group.length(),fill);
         }
         res.push_back(group);
       }
       return res;
    }
};