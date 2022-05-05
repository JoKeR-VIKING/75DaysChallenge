class Solution {
public:
    void combinationSum(vector<int>& candidates, int target, vector<vector<int>>& allPossibleCombinations, vector<int>& temp, int index)
    {
        if (target == 0)
        {
            allPossibleCombinations.push_back(temp);
            return;
        }
        
        for (int i=index;i<candidates.size();i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                continue;
            
            temp.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], allPossibleCombinations, temp, i + 1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> allPossibleCombinations;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        
        combinationSum(candidates, target, allPossibleCombinations, temp, 0);
        return allPossibleCombinations;
    }
};
