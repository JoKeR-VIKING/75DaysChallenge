class Node
{
public:
    string key;
    double val;
    
    Node(string key, double val)
    {
        this -> key = key;
        this -> val = val;
    }
};

class Solution {
public:
    double bfs(string start, string end, unordered_map<string, vector<Node*>>& equationMap)
    {
        if (!equationMap.count(start))
            return -1;
        
        queue<pair<Node*, double>> pendingNodes;
        pendingNodes.push({new Node(start, 0), 1.0});
        unordered_map<Node*, bool> visited;
        
        while (!pendingNodes.empty())
        {
            pair<Node*, double> frontNode = pendingNodes.front();
            pendingNodes.pop();
            
            if (frontNode.first -> key == end)
                return frontNode.second;
            
            visited[frontNode.first] = true;
            
            for (auto& it : equationMap[frontNode.first -> key])
            {
                if (!visited[it])
                {
                    pendingNodes.push({it, frontNode.second * it -> val});
                    visited[it] = true;
                }
            }
        }
        
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        unordered_map<string, vector<Node*>> equationMap;
        vector<double> ans;
        
        for (int i=0;i<equations.size();i++)
        {
            equationMap[equations[i][0]].push_back(new Node(equations[i][1], values[i]));
            equationMap[equations[i][1]].push_back(new Node(equations[i][0], 1 / values[i]));
        }
        
        for (int i=0;i<queries.size();i++)
            ans.push_back(bfs(queries[i][0], queries[i][1], equationMap));
        
        return ans;
    }
};
