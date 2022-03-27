class Solution 
{
private:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
public:
    bool startSearch(vector<vector<char>>& board, string word, int i, int j, vector<vector<bool>>& visited)
    {
        if (word == "")
            return true;
        
        visited[i][j] = true;
        
        for (int k=0;k<4;k++)
        {
            int nx = i + dx[k], ny = j + dy[k];
            
            if (nx == board.size() || ny == board[0].size() || nx < 0 || ny < 0 || board[nx][ny] != word[0] || visited[nx][ny])
                continue;
            
            if (startSearch(board, word.substr(1), nx, ny, visited))
                return true;
        }
        
        visited[i][j] = false;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
        
        for (int i=0;i<board.size();i++)
        {
            for (int j=0;j<board[0].size();j++)
            {
                if (board[i][j] == word[0])
                {
                    if (startSearch(board, word.substr(1), i, j, visited))
                        return true;
                }
            }
        }
        
        return false;
    }
};
