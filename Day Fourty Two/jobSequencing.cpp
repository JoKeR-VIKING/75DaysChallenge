class Solution 
{
public:
    static bool sortFunc(Job& j1, Job& j2)
    {
        return j1.profit > j2.profit;
    }

    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, sortFunc);
        
        int maxDead = 0;
        for (int i=0;i<n;i++)
            maxDead = max(maxDead, arr[i].dead);
        
        vector<int> deadlines(maxDead + 1, -1);
        vector<int> ans(2);
        
        for (int i=0;i<n;i++)
        {
            int currDead = arr[i].dead;
            
            while (currDead != 0 && deadlines[currDead] != -1)
                currDead--;
                
            if (currDead == 0)
                continue;
                
            deadlines[currDead] = arr[i].profit;
        }
        
        for (auto& it : deadlines)
        {
            if (it != -1)
            {
                ans[0]++;
                ans[1] += it;
            }
        }
        
        return ans;
    } 
};
