class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color) {
        for (int neigh : graph[node]) {
            if (color[neigh] == -1) {
                color[neigh] = 1 - color[node];
                if (!dfs(neigh, graph, color))
                    return false;
            } else if (color[neigh] == color[node]) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);  
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                if (!dfs(i, graph, color))
                    return false;
            }
        }
        return true;
    }
};
