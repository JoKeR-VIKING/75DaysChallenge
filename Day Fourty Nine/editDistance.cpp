class Solution {
public:
    int minDistance(string word1, string word2)
    {
        if (word1 == "" || word2 == "")
            return max(word1.length(), word2.length());
        
        int m = word1.length();
        int n = word2.length();
        
        int** arr = new int*[m+1];
        for (int i=0;i<=m;i++)
            arr[i] = new int[n+1];
        
        for (int i=0;i<=m;i++)
            arr[i][0] = i;
        
        for (int i=0;i<=n;i++)
            arr[0][i] = i;
        
        for (int i=1;i<=m;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (word1[m-i] == word2[n-j])
                    arr[i][j] = arr[i-1][j-1];
                else
                {
                    arr[i][j] = 1 + min(arr[i-1][j-1], min(arr[i-1][j], arr[i][j-1]));
                }
            }
        }
        
        return arr[m][n];
    }
};
