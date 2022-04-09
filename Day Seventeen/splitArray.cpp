class Solution {
public:
    bool isArrangement(vector<int>& nums, int m, int maxPages)
    {
        int sum = 0;

        for (int i=0;i<nums.size();i++)
        {
            if (sum + nums[i] > maxPages)
            {
                if (sum == 0)
                    return false;
                
                m--;
                if (m == 0)
                    return false;

                sum = nums[i];
            }
            else
            {
                sum += nums[i];
            }
        }

        return true;
    }
    
    int splitArray(vector<int>& nums, int m)
    {
        int ans = INT_MAX;
        int start = *(max_element(nums.begin(), nums.end()));
        int end = accumulate(nums.begin(), nums.end(), 0);

        while (start <= end)
        {
            int mid = start + (end - start)/2;

            bool isPossible = isArrangement(nums, m, mid);

            if (isPossible)
            {
                ans = min(mid, ans);
                end = mid - 1;
            }
            else
                start = mid + 1;
        }

        return ans;
    }
};
