class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int> pq;
        for (auto& it : stones)
            pq.push(it);
        
        while (pq.size() > 1)
        {
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            
            if (top1 == top2)
                continue;
            
            pq.push(abs(top1 - top2));
        }
        
        return pq.empty() ? 0 : pq.top();
    }
};
