class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {

        map<int,bool> visited ; 

        queue<pair<int,int>> q ;

        vector<vector<int>> list(edges.size()); 

        for(int i = 0 ; i<edges.size() ; i++){
            if(edges[i]!=-1) list[i].push_back(edges[i]) ;
        }

        map<int,int> dist ;

        dist[node1] = 0 ;

        q.push({node1,0}) ;

        visited[node1] = true;

        while(!q.empty()){

            pair<int,int> p = q.front() ;
            q.pop() ;

            for(int nd : list[p.first]){

                if(visited[nd]) continue;

                q.push({nd,p.second + 1}) ;

                dist[nd] = p.second + 1 ;

                visited[nd] = true;

            }

        }

        visited.clear() ;

        map<int,int> dist2 ;

        dist2[node2] = 0 ;

        visited[node2] = true;

        q.push({node2,0}) ;

        while(!q.empty()){

            pair<int,int> p = q.front() ;
            q.pop() ;

            for(int nd : list[p.first]){

                if(visited[nd]) continue;

                q.push({nd,p.second + 1}) ;

                dist2[nd] = p.second + 1 ;

                visited[nd] = true;

            }

        }

    

        int ans = -1;
        int minDist = INT_MAX;

        for(int i = 0 ; i < edges.size() ; i++){
            if(dist.find(i) != dist.end() && dist2.find(i) != dist2.end()){ 
                int maxDist = max(dist[i], dist2[i]);
                if(maxDist < minDist){
                    minDist = maxDist;
                    ans = i;
                }
            }
        }

        return ans;  
    }
};