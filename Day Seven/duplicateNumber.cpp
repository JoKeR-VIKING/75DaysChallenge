class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        for (int i=0;i<nums.size();i++)
        {
            int curr = nums[i] > 0 ? nums[i] : -nums[i];
            
            if (nums[curr - 1] < 0)
                return curr;
            
            nums[curr - 1] *= -1;
        }
        
        return -1;
    }
};
