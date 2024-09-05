class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>>v;
          v.push_back(vector<int>());
            for(int num : nums){
                 int size=v.size();
                 for(int i=0;i<size;i++){
                     vector<int>temp=v[i];
                      temp.push_back(num);
                       v.push_back(temp);
                 }
            }
             return v;
    }
};