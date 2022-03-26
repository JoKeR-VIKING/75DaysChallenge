class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allCombinations;
        
        for (int i=0;i<nums.size();i++)
        {
            int j = i + 1, k = nums.size() - 1;
            
            while (j < k)
            {
                if (nums[j] + nums[k] == -nums[i])
                {
                    allCombinations.push_back({nums[i], nums[j], nums[k]});
                    
                    while (j < nums.size() - 1 && nums[j] == nums[j + 1])
                        j++;
                    
                    while (k > i && nums[k] == nums[k - 1])
                        k--;
                    
                    j++;
                    k--;
                }
                else if (nums[j] + nums[k] > -nums[i])
                    k--;
                else
                    j++;
            }
            
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                i++;
        }
        
        return allCombinations;
    }
};
