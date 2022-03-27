class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int index_one = nums.size() - 2, index_two = nums.size() - 1;
        
        for (;index_one>=0;index_one--)
        {
            if (nums[index_one] < nums[index_one + 1])
                break;
        }
        
        if (index_one >= 0)
        {
            for (;index_two>=0;index_two--)
            {
                if (nums[index_one] < nums[index_two])
                    break;
            }
            
            swap(nums[index_one], nums[index_two]);
            reverse(nums.begin() + index_one + 1, nums.end());
        }
        else
            reverse(nums.begin(), nums.end());
    }
};
