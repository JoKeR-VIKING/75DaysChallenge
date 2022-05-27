class Solution
{
public:
    //Function to merge two nodes a and b.
    int findPar(int node, int par[])
    {
        if (par[node] == node)
            return node;
            
        return par[node] = findPar(par[node], par);
    }
    
    void union_( int a, int b, int par[], int rank1[]) 
    {
        int p1 = findPar(a, par);
        int p2 = findPar(b, par);
        
        if (p1 != p2)
        {
            int r1 = rank1[a];
            int r2 = rank1[b];
            
            if (r1 < r2)
            {
                par[p1] = p2;
                rank1[p2]++;
            }
            else
            {
                par[p2] = p1;
                rank1[p1]++;
            }
        }
        else
        {
            par[p2] = p1;
            rank1[p1]++;
        }
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank1[])
    {
        while (x != par[x])
            x = par[x];
            
        while (y != par[y])
            y = par[y];
            
        return x == y;
    }
};
