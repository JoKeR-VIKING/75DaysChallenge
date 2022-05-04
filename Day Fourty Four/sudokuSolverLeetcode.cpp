class Solution 
{
private:
    const int position[9] = {0, 0, 0, 3, 3, 3, 6, 6, 6};
public:
    bool isValid(vector<vector<char>>& board, int r, int c, int no)
    {
        for (int i=0;i<9;i++)
        {
            if (board[i][c] - '0' == no)
                return false;
        }
        
        for (int i=0;i<9;i++)
        {
            if (board[r][i] - '0' == no)
                return false;
        }
        
        for (int i=position[r];i<position[r] + 3;i++)
        {
            for (int j=position[c];j<position[c] + 3;j++)
            {
                if (board[i][j] - '0' == no)
                    return false;
            }
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>>& board, int r, int c)
    {
        if (r == 9 && c == 0)
            return true;
        
        if (board[r][c] != '.')
        {
            if (c < 8)
                return solve(board, r, c + 1);
            else
                return solve(board, r + 1, 0);
        }
        
        for (int i=1;i<=9;i++)
        {
            if (isValid(board, r, c, i))
            {
                board[r][c] = '0' + i;

                if (c == 8)
                {
                    if (solve(board, r + 1, 0))
                        return true;
                }
                else
                {
                    if (solve(board, r, c + 1))
                        return true;                    
                }
                
                board[r][c] = '.';
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) 
    {
        solve(board, 0, 0);
    }
};
