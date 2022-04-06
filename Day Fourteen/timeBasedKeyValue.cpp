class TimeMap
{
private:
    unordered_map<string, map<int, string>> timePair;
public:
    TimeMap()
    {}
    
    void set(string key, string value, int timestamp)
    {
        timePair[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) 
    {
        auto it = timePair[key].upper_bound(timestamp);
        
        if (it == timePair[key].begin())
            return "";
        
        it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
