class Solution 
{
private:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, -1, 0, 1};
public:
    int exploreIsland(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j)
    {
        visited[i][j] = true;
        int area = 1;
        
        for (int k=0;k<4;k++)
        {
            int nx = i + dx[k], ny = j + dy[k];
            
            if (nx < 0 || ny < 0 || nx == grid.size() || ny == grid[0].size() || grid[nx][ny] == 0 || visited[nx][ny])
                continue;
            
            area += exploreIsland(grid, visited, nx, ny);
        }
        
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int maxArea = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        
        for (int i=0;i<grid.size();i++)
        {
            for (int j=0;j<grid[0].size();j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    maxArea = max(maxArea, exploreIsland(grid, visited, i, j));
                }
            }
        }
        
        return maxArea;
    }
};
