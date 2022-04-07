class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int start = 0, end = matrix.size() - 1, row = -1;
        
        while (start <= end)
        {
            int mid = start + (end - start)/2;
            
            if (matrix[mid][matrix[0].size()-1] == target)
                return true;
            
            if (matrix[mid][matrix[0].size()-1] > target)
            {
                row = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        
        if (row == -1)
            return false;
        
        start = 0, end = matrix[0].size()-1;
        
        while (start <= end)
        {
            int mid = start + (end - start)/2;
            
            if (matrix[row][mid] == target)
                return true;
            
            if (matrix[row][mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        
        return false;
    }
};
