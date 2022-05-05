class Solution {
public:
    void combine(int start, int n, int k, vector<vector<int>>& ans, vector<int> temp)
    {
        if (k == 0)
        {
            ans.push_back(temp);
            return;
        }
        
        for (int i=start;i<=n;i++)
        {
            temp.push_back(i);
            combine(i+1, n, k-1, ans, temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> temp;
        vector<vector<int>> ans;
        
        combine(1, n, k, ans, temp);
        
        return ans;
    }
};
