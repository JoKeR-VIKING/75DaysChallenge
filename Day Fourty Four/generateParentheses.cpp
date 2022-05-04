class Solution {
public:
    void getAllCombinations(int n, int open, int balance, vector<string>& allCombinations, string currPath)
    {
        if (currPath.size() == 2 * n)
        {
            allCombinations.push_back(currPath);
            return;
        }
        
        if (open > 0 && balance > 0)
            getAllCombinations(n, open, balance - 1, allCombinations, currPath + ')');
        if (open != n)
            getAllCombinations(n, open + 1, balance + 1, allCombinations, currPath + '(');
    }
    
    vector<string> generateParenthesis(int n) 
    {
        vector<string> allCombinations;
        
        getAllCombinations(n, 0, 0, allCombinations, "");
        
        return allCombinations;
    }
};
