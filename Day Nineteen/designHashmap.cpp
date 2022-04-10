class Node
{
public:
    int data;
    Node* next;
    
    Node(int data)
    {
        this -> data = data;
        next = NULL;
    }
};

class MyHashMap
{
    Node* key;
    Node* value;
public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
        key = NULL;
        value = NULL;
    }
    
    /** value will always be non-negative. */
    void put(int k, int v)
    {
        if (key != NULL)
        {
            Node* tempKey = key;
            Node* tempValue = value;
            
            if (key -> data == k)
            {
                value -> data = v;
                return;
            }
            
            while (tempKey -> next != NULL && tempKey -> data != k)
            {
                tempKey = tempKey -> next;
                tempValue = tempValue -> next;
            }   
            
            if (tempKey -> next != NULL)
            {
                tempValue -> data = v;
                return;
            }
        }
        
        Node* newKey = new Node(k);
        Node* newValue = new Node(v);
        
        newKey -> next = key;
        key = newKey;
        
        newValue -> next = value;
        value = newValue;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int k)
    {
        if (key == NULL)
            return -1;
        
        Node* tempKey = key;
        Node* tempValue = value;
        
        while (tempKey != NULL && tempKey -> data != k)
        {
            tempKey = tempKey -> next;
            tempValue = tempValue -> next;
        }
        
        if (tempKey == NULL)
            return -1;
        
        return tempValue -> data;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int k)
    {
        if (key == NULL)
            return;
        
        if (key -> data == k)
        {
            key = key -> next;
            value = value -> next;
            return;
        }
        
        Node* tempKey = key;
        Node* tempValue = value;
        
        while (tempKey -> next != NULL && tempKey -> next -> data != k)
        {
            tempKey = tempKey -> next;
            tempValue = tempValue -> next;
        }
        
        if (tempKey -> next == NULL)
            return;
        
        tempKey -> next = tempKey -> next -> next;
        tempValue -> next = tempValue -> next -> next;
    }
};
