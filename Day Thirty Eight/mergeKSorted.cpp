class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ans;
        
        for (auto& it1 : arr)
        {
            for (auto& it2 : it1)
            {
                pq.push(it2);
            }
        }
        
        while (!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};
