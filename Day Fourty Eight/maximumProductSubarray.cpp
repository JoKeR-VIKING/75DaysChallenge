class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int max_ending = nums[0], min_ending = nums[0], overall_max = nums[0];
        
        for (int i=1;i<nums.size();i++)
        {
            int temp = max_ending;
            max_ending = max(nums[i], max(nums[i] * max_ending, nums[i] * min_ending));
            min_ending = min(nums[i], min(nums[i] * temp, nums[i] * min_ending));
            
            overall_max = max(overall_max, max_ending);
        }
        
        return overall_max;
    }
};
