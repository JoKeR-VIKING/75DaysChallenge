class Node
{
public:
    int key, value;
    Node* next, *prev;
    
    Node(int key, int value)
    {
        this -> key = key;
        this -> value = value;
        next = prev = NULL;
    }
};

class LFUCache 
{
private:
    int capacity;
    unordered_map<int, pair<int, Node*>> cache;
    map<int, pair<Node*, Node*>> freq;
public:
    LFUCache(int capacity) 
    {
        this -> capacity = capacity;
    }
    
    int get(int key) 
    {
        if (!cache.count(key))
            return -1;
        
        Node* temp = cache[key].second;
        int currFreq = cache[key].first;
        
        if (temp -> prev -> key == -1 && temp -> next -> key == -1)
            freq.erase(currFreq);
        else
        {
            temp -> next -> prev = temp -> prev;
            temp -> prev -> next = temp -> next;   
        }
        
        if (!freq.count(currFreq + 1))
        {
            freq[currFreq + 1] = {new Node(-1, -1), new Node(-1, -1)};
            freq[currFreq + 1].first -> next = freq[currFreq + 1].second;
            freq[currFreq + 1].second -> prev = freq[currFreq + 1].first;
        }
        
        Node* head = freq[currFreq + 1].first, *tail = freq[currFreq + 1].second;
        
        temp -> next = head -> next;
        head -> next = temp;
        temp -> prev = head;
        temp -> next -> prev = temp;
        
        cache[key].first++;
        return temp -> value;
    }
    
    void put(int key, int value) 
    {
        if (capacity == 0)
            return;
        
        if (cache.count(key))
        {
            get(key);
            cache[key].second -> value = value;
            return;
        }
        
        if (cache.size() == capacity)
        {
            Node* head = freq.begin() -> second.first, *tail = freq.begin() -> second.second;
            Node* temp = tail -> prev;
            
            if (temp -> prev -> key == -1 && temp -> next -> key == -1)
                freq.erase(freq.begin() -> first);
            else
            {
                temp -> prev -> next = temp -> next;
                temp -> next -> prev = temp -> prev;
            }
            
            cache.erase(temp -> key);
            delete temp;
        }
        
        if (!freq.count(1))
        {
            freq[1] = {new Node(-1, -1), new Node(-1, -1)};
            freq[1].first -> next = freq[1].second;
            freq[1].second -> prev = freq[1].first;
        }
        
        Node* head = freq[1].first, *tail = freq[1].second;
        Node* temp = new Node(key, value);
        
        temp -> next = head -> next;
        head -> next = temp;
        temp -> prev = head;
        temp -> next -> prev = temp;
        
        cache[key] = {1, temp};
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
