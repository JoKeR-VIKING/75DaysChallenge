class Solution
{
private:
    vector<int> dx = {0, -1, 0, 1};
    vector<int> dy = {1, 0, -1, 0};
public:
    void getAllPaths(vector<vector<int>>& m, string currPath, vector<string>& allPaths, int i, int j, vector<vector<bool>>& visited)
    {
        if (i == m.size() - 1 && j == m.size() - 1)
        {
            allPaths.push_back(currPath);
            return;
        }
        
        visited[i][j] = true;
        
        for (int k=0;k<4;k++)
        {
            int nx = i + dx[k], ny = j + dy[k];
            if (nx < 0 || ny < 0 || nx == m.size() || ny == m.size() || visited[nx][ny] || m[nx][ny] == 0)
                continue;
            
            char ch;
            if (k == 0)
                ch = 'R';
            else if (k == 1)
                ch = 'U';
            else if (k == 2)
                ch = 'L';
            else
                ch = 'D';
            
            getAllPaths(m, currPath + ch, allPaths, nx, ny, visited);
        }
        
        visited[i][j] = false;
    }

    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        if (m[0][0] == 0)
            return {};
        
        vector<string> allPaths;
        vector<vector<bool>> visited(m.size(), vector<bool>(m.size()));
        
        getAllPaths(m, "", allPaths, 0, 0, visited);
        
        return allPaths;
    }
};
