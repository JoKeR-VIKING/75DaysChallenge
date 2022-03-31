class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int> ans;
        
        for (int i=0;i<nums.size();i++)
        {
            int currNum = nums[i] % nums.size() == 0 ? nums.size() : nums[i] % nums.size();
            nums[currNum - 1] += nums.size();
        }
        
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i] / nums.size() > 1)
            {
                if (nums[i] % nums.size() == 0 && nums[i] / nums.size() < 3)
                    continue;
                
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};
