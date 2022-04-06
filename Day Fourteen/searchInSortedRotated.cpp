class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int pivotIndex = 0, start = 0, end = nums.size() - 1;

        while (start <= end)
        {
            if (nums[start] <= nums[end])
            {
                pivotIndex = start;
                break;
            }

            int mid = start + (end - start)/2;

            int prev = (mid - 1 + nums.size()) % nums.size();
            int next = (mid + 1) % nums.size();

            if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
            {
                pivotIndex = mid;
                break;
            }

            if (nums[start] <= nums[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }

        start = 0, end = pivotIndex - 1;

        while (start <= end)
        {
            int mid = start + (end - start)/2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }

        start = pivotIndex, end = nums.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start)/2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }

        return -1;
    }
};
