class Node
{
public:
    int key, val;
    Node* prev;
    Node* next;
    
    Node(int key, int val)
    {
        this -> key = key;
        this -> val = val;
        prev = next = NULL;
    }
};

class LRUCache
{
private:
    Node* head, *tail;
    unordered_map<int, Node*> cache;
    int capacity;
public:
    LRUCache(int capacity) 
    {
        this -> capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) 
    {
        if (cache.count(key))
        {
            Node* temp = cache[key];
            temp -> prev -> next = temp -> next;
            temp -> next -> prev = temp -> prev;
            
            temp -> next = head -> next;
            head -> next -> prev = temp;
            head -> next = temp;
            temp -> prev = head;
            
            return temp -> val;
        }
        
        return -1;
    }
    
    void put(int key, int value) 
    {
        if (cache.count(key))
        {
            get(key);
            cache[key] -> val = value;
            return;
        }
        
        if (cache.size() == capacity)
        {
            Node* temp = tail -> prev;
            temp -> prev -> next = tail;
            temp -> next -> prev = temp -> prev;
            
            cache.erase(temp -> key);
            delete temp;
        }
        
        Node* temp = new Node(key, value);
        
        temp -> next = head -> next;
        temp -> next -> prev = temp;
        head -> next = temp;
        temp -> prev = head;
        
        cache[key] = temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
