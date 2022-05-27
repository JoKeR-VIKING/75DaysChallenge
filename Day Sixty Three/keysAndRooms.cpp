class Solution {
public:
    void visitAll(int start, vector<vector<int>>& rooms, unordered_map<int, bool>& visited)
    {
        for (int i=0;i<rooms[start].size();i++)
        {
            if (!visited[rooms[start][i]])
            {
                visited[rooms[start][i]] = true;
                visitAll(rooms[start][i], rooms, visited);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        unordered_map<int, bool> visited;
        visited[0] = true;
            
        visitAll(0, rooms, visited);
        
        for (int i=0;i<rooms.size();i++)
        {
            if (!visited[i])
                return false;
        }
        
        return true;
    }
};
