class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        if(n <= 1)
            return n == 0 ? vector<int>{} : vector<int>{0};
        
        vector<int> indegree(n, 0);
        int min_degree = INT_MAX;
        
        // create a graph
        vector<vector<int>> g(n);
        for(auto &edge: edges) {
            g[edge[0]].emplace_back(edge[1]);
            g[edge[1]].emplace_back(edge[0]);
            ++indegree[edge[0]], ++indegree[edge[1]];
        }
        
        vector<int> result;
        queue<int> q;
        unordered_set<int> visited;
        
        // add leaf nodes(indegree 1)
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 1) {
                q.emplace(i);
                visited.emplace(i);
            }
        }
        
        int n_nodes = q.size();
        
        // we return the nodes in the last level
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            --n_nodes;
            // add node of current level
            result.emplace_back(curr);
            
            // remove the connection count for each neighbor
            for(auto v: g[curr]) {
                if(!visited.count(v)) {
                    --indegree[v];
                    // it has become a leaf node, add and mark visited
                    if(indegree[v] == 1) {
                        q.emplace(v);
                        visited.emplace(v);
                    }
                }
            }
            
            // end of level
            if(n_nodes == 0) {
                // not the last level
                if(!q.empty())
                    result.clear();
                n_nodes = q.size();
            }
        }
        
        return result;
    }
};
