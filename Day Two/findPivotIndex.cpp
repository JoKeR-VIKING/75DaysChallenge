class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        vector<int> leftPrefix(nums.size()), rightPrefix(nums.size());
        
        leftPrefix[0] = nums[0];
        rightPrefix.back() = nums.back();
        
        for (int i=1;i<nums.size();i++)
            leftPrefix[i] = leftPrefix[i - 1] + nums[i];
        
        for (int i=nums.size() - 2;i>=0;i--)
            rightPrefix[i] = rightPrefix[i + 1] + nums[i];
        
        for (int i=0;i<nums.size();i++)
        {
            if (i == 0)
            {
                if (rightPrefix[1] == 0)
                    return 0;
                
                continue;
            }
            
            if (i == nums.size() - 1)
            {
                if (leftPrefix[i - 1] == 0)
                    return i;
                
                continue;
            }
            
            if (leftPrefix[i - 1] == rightPrefix[i + 1])
                return i;
        }
        
        return -1;
    }
};
