class Solution {
public:
    bool dfs(int start, vector<vector<int>>& graph, set<int>& safeNodes, unordered_map<int, bool>& visited)
    {
        if (safeNodes.find(start) != safeNodes.end())
            return true;
        if (visited[start])
            return false;
        
        visited[start] = true;
        
        for (auto& it : graph[start])
        {
            if (!dfs(it, graph, safeNodes, visited))
                return false;
        }
        
        safeNodes.insert(start);
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        set<int> safeNodes;
        unordered_map<int, bool> visited;
        
        for (int i=0;i<graph.size();i++)
        {
            if (!visited[i])
                dfs(i, graph, safeNodes, visited);
        }
        
        vector<int> vect(safeNodes.begin(), safeNodes.end());
        return vect;
    }
};
