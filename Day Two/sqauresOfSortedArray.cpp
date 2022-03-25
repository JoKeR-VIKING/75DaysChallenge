class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        vector<int> sortedArray(nums.size());
        int index = nums.size() - 1, i = 0, j = nums.size() - 1;
        
        while (i <= j)
        {
            if (nums[i] * nums[i] > nums[j] * nums[j])
                sortedArray[index--] = nums[i] * nums[i++];
            else
                sortedArray[index--] = nums[j] * nums[j--];
        }
        
        return sortedArray;
    }
};
