class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        long sum = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for (int i=0;i<nums.size();i++)
        {
            int j = i + 1, k = nums.size() - 1;
            
            while (j < k)
            {
                int curr = nums[i] + nums[j] + nums[k];
                
                if (abs(target - curr) < abs(sum - target))
                    sum = curr;
                
                if (curr < target)
                    j++;
                else
                    k--;
            }
        }
        
        return sum;
    }
};
