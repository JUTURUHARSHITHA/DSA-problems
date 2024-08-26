class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int c = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = 0;
        int i = 0;
        while(i <  g.size() && j < s.size()){
            if(g[i] <= s[j]){
                c++;
                i++;
                j++;
            } else{
                j++;
            }
        }
        return c;
    }
};