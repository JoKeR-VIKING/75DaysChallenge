class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    {
        vector<int> ans(n);
        stack<int> stk;
        
        ans.back() = -1;
        stk.push(arr.back());
        
        for (int i=arr.size() - 2;i>=0;i--)
        {
            while (!stk.empty() && stk.top() >= arr[i])
                stk.pop();
            
            if (stk.empty())
                ans[i] = -1;
            else
                ans[i] = stk.top();
                
            stk.push(arr[i]);
        }
        
        return ans;
    } 
};
