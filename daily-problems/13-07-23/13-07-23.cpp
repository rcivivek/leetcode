//  Problem Number -207

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<int> topo, indegree(n,0);
        vector<vector<int>>adj(n,vector<int>{});
        for(auto it: edges){
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            topo.push_back(node);
            q.pop();
            for(auto it: adj[node]){
                if(--indegree[it]==0)q.push(it);
            }
        }
      return topo.size()==n;
    }
};