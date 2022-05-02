class Solution {
public:
    int findMinVertex(vector<int>& weight, vector<bool>& visited)
    {
        int minVertex = -1;
        
        for (int i=0;i<weight.size();i++)
        {
            if (!visited[i] && (minVertex == -1 || weight[minVertex] > weight[i]))
                minVertex = i;
        }
        
        return minVertex;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<int>> adjMatrix(n, vector<int>(n + 1, -1));
        
        for (auto& it : times)
            adjMatrix[it[0] - 1][it[1] - 1] = it[2];
        
        vector<int> weight(n, INT_MAX);
        vector<bool> visited(n);
        weight[k - 1] = 0;
        
        for (int i=0;i<n;i++)
        {
            int minVertex = findMinVertex(weight, visited);
            visited[minVertex] = true;
            
            if (weight[minVertex] == INT_MAX)
                break;
            
            for (int j=0;j<n;j++)
            {
                if (adjMatrix[minVertex][j] != -1 && weight[j] > weight[minVertex] + adjMatrix[minVertex][j])
                    weight[j] = weight[minVertex] + adjMatrix[minVertex][j];
            }
        }
        
        if (count(weight.begin(), weight.end(), INT_MAX))
            return -1;
        
        return *(max_element(weight.begin(), weight.end()));
    }
};
