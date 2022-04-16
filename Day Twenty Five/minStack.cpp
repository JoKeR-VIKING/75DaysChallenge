class MinStack 
{
private:
    stack<int> orignal, min;
public:
    MinStack() 
    {}
    
    void push(int val) 
    {
        orignal.push(val);
        if (min.empty() || min.top() > val)
            min.push(val);
        else
            min.push(min.top());
    }
    
    void pop() 
    {
        orignal.pop();
        min.pop();
    }
    
    int top() 
    {
        return orignal.top();
    }
    
    int getMin()
    {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
