class Solution {
public:

    void get_odd_even(vector<vector<int>> &adj,int node,int &cntOdd,int&  cntEven,vector<int> &parity){
        queue<int> q;
        bool flag = true;
        q.push(node);
        int size = adj.size();

        vector<int> visited(size,0);

        while(!q.empty()){
            int elem = q.size();
            if(flag){
                cntEven +=elem;
            }
            else cntOdd += elem;
            while(elem--){
                int temp = q.front();
                if(flag){
                    parity[temp] = 0;
                }
                else parity[temp] = 1; 
                q.pop();
                for(auto nodes : adj[temp]){
                    if(!visited[nodes]){
                        visited[nodes] = 1;
                        q.push(nodes);
                    }
                }
            }

            flag = !flag;
        }


    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(m);

        for(int i=0;i<m-1;i++){
            int u = edges2[i][0];
            int v = edges2[i][1];

            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        for(int i=0;i<n-1;i++){
            int u = edges1[i][0];
            int v = edges1[i][1];

            adj1[u].push_back(v);
            adj1[v].push_back(u);

        }

        vector<int> ans;

        int cntOdd_1 = 0;
        int cntEven_1 = -1;
        vector<int> parity1(n,-1);
        vector<int> parity2(m,-1);  // 0 for even and 1 for odd

        get_odd_even(adj1,0,cntOdd_1,cntEven_1,parity1);

        int cntEven_2 = -1;
        int cntOdd_2 = 0;
    
        get_odd_even(adj2,0,cntOdd_2,cntEven_2,parity2);
        int add = max(cntOdd_2,cntEven_2);

        // cout<<cntOdd_1<<" "<<cntEven_1 <<endl;
        // cout<<cntOdd_2<< " "<<cntEven_2 << endl;

        // for(int i=0;i<n;i++){
        //     cout<<parity1[i]<<" ";
        // }cout<<endl;

        // for(int i=0;i<m;i++){
        //     cout<<parity2[i]<<" ";
        // }cout<<endl;

        for(int i=0;i<n;i++){
            if(parity1[i]== 0){
                ans.push_back(cntEven_1 + add);
            }
            else ans.push_back(cntOdd_1 + add);
        }

        return ans;
    }
};