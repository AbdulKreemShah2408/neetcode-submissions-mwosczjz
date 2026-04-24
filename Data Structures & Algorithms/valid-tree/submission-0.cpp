class Solution {
public:
   void dfs(int node,vector<vector<int>> &adj,vector<bool>&visited,int& count){
    visited[node]=true;
    count++;
    for(int neighbor:adj[node]){
        if(!visited[neighbor]){
            dfs(neighbor,adj,visited,count);
        }
    }
   }
    bool validTree(int n, vector<vector<int>>& edges) {
      if(edges.size() !=n-1) return false;
      vector<vector<int>>adj(n);
      for(auto& e:edges){
        adj[e[0]].push_back(e[1]);
         adj[e[1]].push_back(e[0]);
      }
      vector<bool>visited(n,false);
      int count=0;
      dfs(0,adj,visited,count);
      return count==n;
    }
};
