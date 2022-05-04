class Solution 
{
private:
    const int position[9] = {0, 0, 0, 3, 3, 3, 6, 6, 6};
public:
    //Function to find a solved Sudoku. 
    bool canPlace(int grid[N][N], int i, int j)
    {
        for (int k=0;k<N;k++)
        {
            if (k == i)
                continue;
            if (grid[k][j] == grid[i][j])
                return false;
        }
        
        for (int k=0;k<N;k++)
        {
            if (k == j)
                continue;
            if (grid[i][k] == grid[i][j])
                return false;
        }
        
        for (int k=position[i];k<position[i] + 3;k++)
        {
            for (int l=position[j];l<position[j] + 3;l++)
            {
                if (i == k && l == j)
                    continue;
                if (grid[k][l] == grid[i][j])
                    return false;
            }
        }
        
        return true;
    }
    
    bool SolveSudoku(int grid[N][N], int i, int j)
    {
        if (j == N)
        {
            j = 0;
            i++;
        }
        if (i == N)
        {
            return true;
        }
        
        if (grid[i][j] == 0)
        {
            for (int k=1;k<=9;k++)
            {
                grid[i][j] = k;
                
                if (canPlace(grid, i, j) && SolveSudoku(grid, i, j + 1))
                    return true;
                
                grid[i][j] = 0;
            }
            
            return false;
        }
        else
            return SolveSudoku(grid, i, j + 1);
            
    }
    
    bool SolveSudoku(int grid[N][N])  
    {
        return SolveSudoku(grid, 0, 0);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for (int i=0;i<N;i++)
        {
            for (int j=0;j<N;j++)
            {
                cout<<grid[i][j]<<" ";
            }
        }
    }
};
