class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        for (int i=0;i<nums.size();i++)
        {
            for (int j=i+1;j<nums.size();j++)
            {
                int k = j + 1, l = nums.size() - 1;
                
                while (k < l)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (k < nums.size() - 1 && nums[k] == nums[k + 1])
                            k++;

                        k++;

                        while (l > 0 && nums[l] == nums[l - 1])
                            l--;

                        l--;
                    }
                    else if (sum > target)
                        l--;
                    else
                        k++;
                }
                
                while (j < nums.size() - 1 && nums[j] == nums[j + 1])
                    j++;
            }
            
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                    i++;
        }
        
        return ans;
    }
};
