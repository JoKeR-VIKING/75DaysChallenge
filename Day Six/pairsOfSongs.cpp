class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        unordered_map<int, int> um;
        int pairs = 0;
        
        for (int i=0;i<time.size();i++)
        {
            if (time[i] % 60 == 0)
                pairs += um[0];
            else if (um.count(60 - time[i] % 60))
                pairs += um[60 - time[i] % 60];
            
            um[time[i] % 60]++;
        }
        
        return pairs;
    }
};
