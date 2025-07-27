class Solution {
public:
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis, vector<int>& order) {
        vis[node] = 1;
        pathVis[node] = 1;
        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                if (dfs(neigh, adj, vis, pathVis, order))
                    return true;
            } else if (pathVis[neigh]) {
                return true;
            }
        }
        pathVis[node] = 0;
        order.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        vector<int> vis(numCourses, 0), pathVis(numCourses, 0), order;
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis, order)) {
                    return {};
                }
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
};
