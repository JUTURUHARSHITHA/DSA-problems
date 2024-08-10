class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int>ans;
        int asum=0,bsum=0;
        for(auto x:aliceSizes)
            asum+=x;
        for(auto x:bobSizes)
            bsum+=x;
        int diff=(bsum-asum)/2;
        unordered_set<int> s(bobSizes.begin(),bobSizes.end());
        for(auto x : aliceSizes) {
              if(s.find(x + diff) != s.end()){
                  ans.push_back(x);
                  ans.push_back(x+diff);
                  break;
              }
        }
        return ans;
    }
};