class Solution {
public:
    void combinationSum(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& temp, int sum, int target, int index)
    {
        if (sum == target)
        {
            ans.push_back(temp);
            return;
        }
        if (index == candidates.size() || sum > target)
            return;
        
        combinationSum(ans, candidates, temp, sum, target, index + 1);
        
        temp.push_back(candidates[index]);
        combinationSum(ans, candidates, temp, sum + candidates[index], target, index);
        temp.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        combinationSum(ans, candidates, temp, 0, target, 0);
        
        return ans;
    }
};
