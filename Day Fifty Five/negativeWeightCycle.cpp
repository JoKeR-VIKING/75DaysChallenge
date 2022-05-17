int isNegativeWeightCycle(int n, vector<vector<int>>& edges)
	{
	    vector<int> weights(n, INT_MAX);
	    weights[0] = 0;
	    
	    for (int i=0;i<n-1;i++)
	    {
	        for (int j=0;j<edges.size();j++)
	        {
	            if (weights[edges[j][0]] != INT_MAX && weights[edges[j][1]] > weights[edges[j][0]] + edges[j][2])
	            {
	                weights[edges[j][1]] = weights[edges[j][0]] + edges[j][2];
	            }
	        }
	    }
	    
	    for (int i=0;i<edges.size();i++)
	    {
	        if (weights[edges[i][1]] > weights[edges[i][0]] + edges[i][2])
	            return 1;
	    }
	    
	    return 0;
	}
