class Solution {
public:
    bool canFinish(vector<vector<int>>& adjList, int start, vector<bool>& visited, vector<bool>& completed)
    {
        int able = true;
        visited[start] = true;
        
        for (auto& it : adjList[start])
        {
            if (completed[it])
                continue;
            if (visited[it])
                return false;
            
            able = able && canFinish(adjList, it, visited, completed);
        }
        
        completed[start] = able;
        visited[start] = false;
        return able;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adjList(numCourses);
        vector<bool> visited(numCourses), completed(numCourses);
        
        for (auto& it : prerequisites)
            adjList[it[0]].push_back(it[1]);
        
        int able = true;
        for (int i=0;i<numCourses;i++)
            if (!visited[i])
                able = able && canFinish(adjList, i, visited, completed);
        
        return able;
    }
};
