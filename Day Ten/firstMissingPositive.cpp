class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        bool hasOne = false;
        
        for (auto& it : nums)
        {
            if (it == 1)
                hasOne = true;
            
            if (it > nums.size() || it <= 0)
                it = 1;
        }
        
        if (!hasOne)
            return 1;
        
        for (int i=0;i<nums.size();i++)
        {
            int index = abs(nums[i]);
            
            if (nums[index - 1] > 0)
                nums[index - 1] *= -1;
        }
        
        for (int i=0;i<nums.size();i++)
            if (nums[i] > 0)
                return i + 1;
        
        return nums.size() + 1;
    }
};
