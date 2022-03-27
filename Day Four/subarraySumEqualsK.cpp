class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int subarrays = 0, sum = 0;
        unordered_map<int, int> um;
        
        for (auto& it : nums)
        {
            sum += it;
            
            if (sum == k)
                subarrays++;
            
            subarrays += um[sum - k];
            um[sum]++;
        }
        
        return subarrays;
    }
};
