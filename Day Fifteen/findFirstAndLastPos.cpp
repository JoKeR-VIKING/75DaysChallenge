class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int start = 0, end = nums.size() - 1, firstPos = -1, secondPos = -1;
        
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            
            if (nums[mid] >= target)
            {
                if (nums[mid] == target)
                    firstPos = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        
        start = 0, end = nums.size() - 1;
        
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            
            if (nums[mid] <= target)
            {
                if (nums[mid] == target)
                    secondPos = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        
        return {firstPos, secondPos};
    }
};
