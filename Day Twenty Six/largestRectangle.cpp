class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        vector<int> nsl(heights.size()), nsr(heights.size());
        stack<int> stk;
        nsl[0] = -1;
        nsr.back() = heights.size();
        
        stk.push(0);
        
        for (int i=1;i<heights.size();i++)
        {
            while (!stk.empty() && heights[i] <= heights[stk.top()])
                stk.pop();
            
            if (stk.empty())
                nsl[i] = -1;
            else
                nsl[i] = stk.top();
            
            stk.push(i);
        }
        
        while (!stk.empty())
            stk.pop();
            
        stk.push(heights.size() - 1);
        
        for (int i=heights.size()-2;i>=0;i--)
        {
            while (!stk.empty() && heights[i] <= heights[stk.top()])
                stk.pop();
            
            if (stk.empty())
                nsr[i] = heights.size();
            else
                nsr[i] = stk.top();
            
            stk.push(i);
        }
        
        int maxArea = 0;
        
        for (int i=0;i<heights.size();i++)
        {
            int left = nsl[i] + 1;
            int right = nsr[i] - 1;
            
            maxArea = max(maxArea, (right - left + 1) * heights[i]);
        }
        
        return maxArea;
    }
};
