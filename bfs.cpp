class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int visitedArray[V]={0};
        vector<int>bfs;
        queue<int> q;
        q.push(0);
        visitedArray[0]=1;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            
            for(auto it:adj[node]){
                if(!visitedArray[it]){
                    visitedArray[it]=1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};