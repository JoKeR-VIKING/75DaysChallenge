class Solution {
public:
    void subset(vector<int> &input, int n, int index, vector<vector<int>>& output, vector<int> res)
    {
        if (index == n)
        {
            output.push_back(res);
            return;
        }
        
        subset(input, n, index + 1, output, res);
        res.push_back(input[index]);
        subset(input, n, index + 1, output, res);
    }
    
    vector<vector<int>> subsets(vector<int>& input)
    {
        int n = input.size();
        vector<vector<int>> output;
        vector<int> res;
        subset(input, n, 0, output, res);
        return output;
    }
};
