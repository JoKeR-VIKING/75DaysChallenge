class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> triangle(numRows);
        triangle[0] = {1};
        
        for (int i=1;i<numRows;i++)
        {
            triangle[i] = vector<int>(i + 1);
            
            for (int j=0;j<i+1;j++)
            {
                if (j == 0 || j == i)
                    triangle[i][j] = 1;
                else
                    triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
        
        return triangle;
    }
};
