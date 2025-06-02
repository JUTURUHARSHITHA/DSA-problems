class Solution {
public:
    int candy(vector<int>& height) {
        int n = height.size();
        vector<int> choco(n);
        for(int i=0;i<n;i++){
            choco[i] = 1;
        }
        for(int i = 1; i < n; i++) {
            if(height[i - 1] < height[i]) {
                choco[i] = choco[i - 1] + 1;
            }
        }

        for(int i = n - 2; i >= 0; i--) {
            if(height[i] > height[i + 1]) {
                choco[i] = max(choco[i], choco[i + 1] + 1);
            }
        }
        int ans = accumulate(choco.begin(), choco.end(), 0);

        return ans;
    }
};