class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int total = 0;
        int n = g.size();
        int m = s.size();

        if(m == 0){
            return total;
        }
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            if(g[i] <= s[j]){
                total++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return total;
    }
};