class Solution {
public:
    bool bfs(vector<vector<int>>& graph, unordered_map<int, bool>& visited, int start)
    {
        set<int> s1, s2;
        queue<int> pendingNodes;
        pendingNodes.push(start);
        
        while (!pendingNodes.empty())
        {
            int frontNode = pendingNodes.front();
            pendingNodes.pop();

            visited[frontNode] = true;
            int whichSet = s2.find(frontNode) == s2.end() ? 1 : 2;

            for (auto& it : graph[frontNode])
            {
                if (whichSet == 1)
                {
                    if (s1.find(it) != s1.end())
                        return false;

                    if (!visited[it])
                    {
                        s2.insert(it);
                        pendingNodes.push(it);
                    }
                }
                else
                {
                    if (s2.find(it) != s2.end())
                        return false;

                    if (!visited[it])
                    {
                        s1.insert(it);
                        pendingNodes.push(it);
                    }
                }
                
                visited[it] = true;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) 
    {
        unordered_map<int, bool> visited;
        
        for (int i=0;i<graph.size();i++)
        {
            if (!visited[i])
                if (!bfs(graph, visited, i))
                    return false;
        }
        
        return true;
    }
};
