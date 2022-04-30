class MedianFinder
{
private:
    priority_queue<int> maxPriority;
    priority_queue<int, vector<int>, greater<int>> minPriority;
public:
    /** initialize your data structure here. */
    MedianFinder() 
    {}
    
    void addNum(int num)
    {
        if (maxPriority.empty() || num > maxPriority.top())
            minPriority.push(num);
        else
            maxPriority.push(num);
        
        if (minPriority.size() > maxPriority.size() && minPriority.size() - maxPriority.size() == 2)
        {
            maxPriority.push(minPriority.top());
            minPriority.pop();
        }
        else if (maxPriority.size() > minPriority.size() && maxPriority.size() - minPriority.size() == 2)
        {
            minPriority.push(maxPriority.top());
            maxPriority.pop();
        }
    }
    
    double findMedian() 
    {
        if (minPriority.size() == maxPriority.size())
            return (minPriority.top() + maxPriority.top())/2.00;
        else
        {
            if (minPriority.size() > maxPriority.size())
                return minPriority.top();
            else
                return maxPriority.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
