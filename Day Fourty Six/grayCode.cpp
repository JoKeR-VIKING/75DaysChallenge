class Solution {
public:
    vector<string> getBitNums(int n)
    {
        if (n == 1)
            return {"0", "1"};
        
        vector<string> bitNums = getBitNums(n - 1);
        vector<string> ans;
        
        for (int i=0;i<bitNums.size();i++)
            ans.push_back("0" + bitNums[i]);
        
        for (int i=bitNums.size() - 1;i>=0;i--)
            ans.push_back("1" + bitNums[i]);
        
        return ans;
    }
    
    vector<int> grayCode(int n)
    {
        vector<string> bitNums = getBitNums(n);
        vector<int> ans;
        
        for (auto& it : bitNums)
            ans.push_back(stoi(it, 0, 2));
        
        return ans;
    }
};
