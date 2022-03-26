class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int j = 1;
        
        for (int i=1;i<nums.size();)
        {
            while (i < nums.size() && nums[i] == nums[i - 1])
                i++;
            
            if (i == nums.size())
                return j++;
            
            if (i >= j)
            {
                swap(nums[i++], nums[j]);
                while (i < nums.size() && nums[i] == nums[j])
                    i++;
                
                j++;
            }
            else
                j = i++;
        }
        
        return j;
    }
};
