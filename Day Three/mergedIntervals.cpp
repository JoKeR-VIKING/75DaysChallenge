class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> mergedIntervals;
        sort(intervals.begin(), intervals.end());
        
        vector<int> latestInterval = intervals[0];
        
        for (int i=1;i<intervals.size();i++)
        {
            if (intervals[i][0] >= latestInterval[0] && intervals[i][0] <= latestInterval[1])
                latestInterval[1] = max(latestInterval[1], intervals[i][1]);
            else
            {
                mergedIntervals.push_back(latestInterval);
                latestInterval = intervals[i];
            }
        }
        
        mergedIntervals.push_back(latestInterval);
        
        return mergedIntervals;
    }
};
