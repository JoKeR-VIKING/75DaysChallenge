class RandomizedSet 
{
private:
    set<int> s;
public:
    RandomizedSet() 
    {}
    
    bool insert(int val) 
    {
        int size = s.size();
        s.insert(val);
        
        return s.size() != size;
    }
    
    bool remove(int val)
    {
        int size = s.size();
        s.erase(val);
        
        return s.size() != size;
    }
    
    int getRandom() 
    {
        int index = rand() % s.size();
        
        for (auto& it : s)
        {
            if (index == 0)
                return it;
            
            index--;
        }
        
        return -1;
    }
};
