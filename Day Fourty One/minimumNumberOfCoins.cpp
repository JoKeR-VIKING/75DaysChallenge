const vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> ans;
        
        for (int i=denominations.size()-1;i>=0;)
        {
            if (denominations[i] > N)
            {
                i--;
                continue;
            }
                
            ans.push_back(denominations[i]);
            N -= denominations[i];
        }
        
        return ans;
    }
};
