//           Problem Number - 802
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int>indegree(n,0),topo;
        vector<vector<int>> adj(n, vector<int>{});
        for(int  i=0;i<n;i++){
           for(auto it: graph[i]){
               indegree[i]++;
               adj[it].push_back(i);
           }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
           if(indegree[i]==0)
             q.push(i);
        vector<int> ans;
        while(!q.empty()){
            int node = q.front(); q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
               if(--indegree[it]==0)q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};