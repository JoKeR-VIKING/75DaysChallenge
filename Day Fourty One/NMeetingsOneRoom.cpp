class Solution
{
public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    class Activity
    {
    public:
        int start, end;
    };
    
    static bool sortFunc(Activity& a1, Activity& a2)
    {
        return a1.end < a2.end;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<Activity> vect;
        int canPerform = 1;
        
        for (int i=0;i<n;i++)
            vect.push_back({start[i], end[i]});
        
        sort(vect.begin(), vect.end(), sortFunc);
        int j = 0;
        
        for (int i=1;i<vect.size();i++)
        {
            if (vect[i].start > vect[j].end)
            {
                canPerform++;
                j = i;
            }
        }
        
        return canPerform;
    }
};
