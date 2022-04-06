class Solution {
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        int count = 0;
        
        for (int i=0;i<grid.size();i++)
        {
            int start = 0, end = grid[0].size() - 1, ans = 0;
            
            while (start <= end)
            {
                int mid = start + (end - start) / 2;
                
                if (grid[i][mid] < 0)
                {
                    ans = grid[0].size() - mid;
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            
            count += ans;
        }
        
        return count;
    }
};
