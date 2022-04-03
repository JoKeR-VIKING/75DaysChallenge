class RandomizedCollection 
{
private:
    unordered_map<int, unordered_set<int>> col;
    vector<int> vect;
public:
    RandomizedCollection() 
    {}
    
    bool insert(int val)
    {
        bool isPresent = col[val].size() != 0;
        col[val].insert(vect.size());
        vect.push_back(val);
        return !isPresent;
    }
    
    bool remove(int val)
    {
        bool isPresent = col[val].size() != 0;

        if (!isPresent)
            return false;
        
        int index1 = *(col[val].begin());
        col[val].erase(index1);
        
        if (index1 == vect.size() - 1)
        {
            vect.pop_back();
            return true;
        }
        
        col[vect.back()].erase(vect.size() - 1);
        col[vect.back()].insert(index1);
        swap(vect.back(), vect[index1]);
        vect.pop_back();

        return true;
    }
    
    int getRandom()
    {
        int index = rand() % vect.size();
        return vect[index];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
