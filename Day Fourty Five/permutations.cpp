class Solution {
public:
    vector<vector<int>> permute(int start, vector<int>& nums)
    {
        if (start == nums.size())
            return {nums};
        
        vector<vector<int>> ans;
        
        for (int i=start;i<nums.size();i++)
        {
            swap(nums[start], nums[i]);
            
            vector<vector<int>> temp = permute(start+1, nums);
            for (int i=0;i<temp.size();i++)
                ans.push_back(temp[i]);
            
            swap(nums[start], nums[i]);
        }
        
        return ans;
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        return permute(0, nums);
    }
};
