class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int size = nums.size();
        for (int i=0;i<size;i++)
            nums.push_back(nums[i]);
        
        stack<int> ngr;
        ngr.push(nums.back());
        vector<int> ans(size);
        
        for (int i=nums.size()-2;i>=size;i--)
        {
            while (!ngr.empty() && ngr.top() <= nums[i])
                ngr.pop();
            
            ngr.push(nums[i]);
        }
        
        for (int i=size - 1;i>=0;i--)
        {
            while (!ngr.empty() && ngr.top() <= nums[i])
                ngr.pop();
            
            if (ngr.empty())
                ans[i] = -1;
            else
                ans[i] = ngr.top();
            
            ngr.push(nums[i]);
        }
        
        return ans;
    }
};
