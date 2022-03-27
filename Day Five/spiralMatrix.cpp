class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> ans;
        int rs = 0, re = matrix.size() - 1, cs = 0, ce = matrix[0].size() - 1, maxSize = matrix.size() * matrix[0].size();
        
        while (ans.size() < maxSize)
        {
            for (int i=cs;i<=ce && ans.size() < maxSize;i++)
                ans.push_back(matrix[rs][i]);
            
            rs++;
            
            for (int i=rs;i<=re && ans.size() < maxSize;i++)
                ans.push_back(matrix[i][ce]);
            
            ce--;
            
            for (int i=ce;i>=cs && ans.size() < maxSize;i--)
                ans.push_back(matrix[re][i]);
            
            re--;
            
            for (int i=re;i>=rs && ans.size() < maxSize;i--)
                ans.push_back(matrix[i][cs]);
            
            cs++;
        }
        
        return ans;
    }
};
