vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dis(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // store distance and node
        dis[S] = 0;
        pq.push({0, S});
        while(!pq.empty()) {
            int node = pq.top().second;
            int dis_curr = pq.top().first;
            pq.pop();
            for(auto& it: adj[node]) {
                int nxt_dis = dis_curr + it[1];
                if(dis[it[0]]>nxt_dis) {
                    dis[it[0]] = nxt_dis;
                    pq.push({nxt_dis, it[0]});
                }
            }
            
        }
        return dis;
    }
