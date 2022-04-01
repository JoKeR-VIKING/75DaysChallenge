class Details
{
public:
    string name, time, cost, city;
};

class Solution 
{
public:
    vector<string> invalidTransactions(vector<string>& transactions) 
    {
        vector<string> invalid;
        vector<Details> vect;
        
        for (auto& it : transactions)
        {
            stringstream ss(it);
            string word;
            vector<string> temp;
            
            while (ss.good())
            {
                getline(ss, word, ',');
                temp.push_back(word);
            }
            
            vect.push_back({temp[0], temp[1], temp[2], temp[3]});
        }
        
        for (int i=0;i<vect.size();i++)
        {
            if (stoi(vect[i].cost) > 1000)
            {
                invalid.push_back(transactions[i]);
                continue;
            }
            
            for (int j=0;j<vect.size();j++)
            {
                if (i == j)
                    continue;
                if (vect[j].city == vect[i].city || vect[i].name != vect[j].name)
                    continue;
                if (abs(stoi(vect[j].time) - stoi(vect[i].time)) > 60)
                    continue;
                
                invalid.push_back(transactions[i]);
                break;
            }
        }
        
        return invalid;
    }
};
