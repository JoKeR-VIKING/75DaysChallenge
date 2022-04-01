class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k)
    {
        unordered_map<int, int> isOccured;
        isOccured.insert({0, 1});
        int sum = 0, subarrayCount = 0;
        
        for (int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            subarrayCount += isOccured[sum % k < 0 ? sum % k + k : sum % k];
            isOccured[sum % k < 0 ? sum % k + k : sum % k]++;
        }
        
        return subarrayCount;
    }
};
