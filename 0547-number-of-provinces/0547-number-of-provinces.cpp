class Solution {
public:
  void dfs(vector<vector<int>>&isconnected,vector<bool>& visited,int city){
     visited[city]=true;
       for(int i=0;i<isconnected.size();i++){
         if(isconnected[city][i]== 1&&!visited[i]){
             dfs(isconnected,visited,i);
         }
       }
  }
    int findCircleNum(vector<vector<int>>& isconnected) {
          int n = isconnected.size();
           vector<bool>visited(n,false);
            int provinces=0;
             for(int i=0;i<n;i++){
                 if(!visited[i]){
                     dfs(isconnected,visited,i);
                     provinces++;
                 }
             }
              return provinces;
    }
};