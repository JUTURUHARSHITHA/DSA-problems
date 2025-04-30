class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        bool g = 0;
        int n = arr.size();
        if(n == 1) return 1;
        if(n == 2) {
            return 1 + (arr[0] != arr[1]);
        }
        if(arr[0] > arr[1]) g = 1;
        int ans = 1;
        int cnt = 1;
        for(int i=1;i<n-1;i++){
            if(g){
                if(arr[i] < arr[i+1]){
                    cnt++;
                    g = 0;
                }
                else if(arr[i] == arr[i+1]) cnt = 0;
                else{
                    cnt = 1;
                }
            }
            else{
                if(arr[i] > arr[i+1]){
                    g = 1;
                    cnt++;
                }
                else if(arr[i] == arr[i+1]) cnt = 0;
                else cnt = 1;
            }
            ans = max(ans, cnt+1);
        }
        return ans;
    }
};