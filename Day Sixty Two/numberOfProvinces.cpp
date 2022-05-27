class Solution {
public:
    void dfs(int start, vector<vector<int>>& isConnected, vector<bool>& visited, int n)
    {
        visited[start] = true;
        
        for (int i=0;i<n;i++)
        {
            if (!visited[i] && isConnected[start][i])
                dfs(i, isConnected, visited, n);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int provinces = 0, n = isConnected.size();
        vector<bool> visited(n);
        
        for (int i=0;i<n;i++)
        {
            if (!visited[i])
            {
                dfs(i, isConnected, visited, n);
                provinces++;
            }
        }
        
        return provinces;
    }
};
