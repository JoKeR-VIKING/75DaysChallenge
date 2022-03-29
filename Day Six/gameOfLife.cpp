class Solution {
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int dx[] = {1, 0, 0, -1, 1, -1, 1, -1};
        int dy[] = {0, -1, 1, 0, 1, -1, -1, 1};
        vector<vector<int>> newBoard = board;

        for (int i=0;i<board.size();i++)
        {
            for (int j=0;j<board[0].size();j++)
            {
                int live = 0;

                for (int k=0;k<8;k++)
                {
                    int nx = i + dx[k], ny = j + dy[k];

                    if (nx < 0 || ny < 0 || nx == board.size() || ny == board[0].size())
                        continue;

                    live += board[nx][ny] == 1;
                }

                if (board[i][j])
                {
                    if (live > 3 || live < 2)
                        newBoard[i][j] = 0;
                }
                else
                {
                    if (live == 3)
                        newBoard[i][j] = 1;
                }
            }
        }

        board = newBoard;
    }
};
