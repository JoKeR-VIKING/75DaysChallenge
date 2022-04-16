class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        stack<int> stk;
        unordered_map<int, int> um;
        stk.push(nums2.back());
        um[nums2.back()] = -1;
        
        for (int i=nums2.size()-2;i>=0;i--)
        {
            if (nums2[i] > stk.top())
            {
                while (!stk.empty() && stk.top() < nums2[i])
                    stk.pop();
                
                if (stk.empty())
                    um[nums2[i]] = -1;
                else
                   um[nums2[i]] = stk.top(); 
            }
            else
                um[nums2[i]] = stk.top();
            
            stk.push(nums2[i]);
        }
        
        vector<int> ans;
        
        for (int i=0;i<nums1.size();i++)
            ans.push_back(um[nums1[i]]);
        
        return ans;
    }
};
