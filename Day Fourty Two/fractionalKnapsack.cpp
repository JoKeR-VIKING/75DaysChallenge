class Items
{
public:
    int value, weight;
    double ratio;
};

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    void mergeTwoSortedArrays(Items* items, int start, int mid, int end)
    {
    	Items* temp = new Items[end - start + 1];
    	int i = start, j = mid + 1, k = 0;
    
    	while (i <= mid && j <= end)
    	{
    		if (items[i].ratio > items[j].ratio)
    		{
    			temp[k] = items[i];
    			i++;
    		}
    		else
    		{
    			temp[k] = items[j];
    			j++;
    		}
    
    		k++;
    	}
    
    	while (i <= mid)
    		temp[k++] = items[i++];
    
    	while (j <= end)
    		temp[k++] = items[j++];
    
    	for (k=start;k<=end;k++)
    		items[k] = temp[k - start];
    }
    
    void sortByRatio(Items* items, int start, int end)
    {
    	if (start >= end)
    		return;
    
    	int mid = start + (end - start) / 2;
    	sortByRatio(items, start, mid);
    	sortByRatio(items, mid + 1, end);
    
    	mergeTwoSortedArrays(items, start, mid, end);
    }
    
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        Items* items = new Items[n];
        
        for (int i=0;i<n;i++)
        {
            items[i].weight = arr[i].weight;
            items[i].value = arr[i].value;
            items[i].ratio = (double)arr[i].value / arr[i].weight;
        }
        
        sortByRatio(items, 0, n - 1);
        
    	int i = 0;
    	double profit = 0;
    
    	while (i != n && w - items[i].weight >= 0)
    	{
    		w -= items[i].weight;
    		profit += items[i].value;
    		i++;
    	}
    
        if (i != n)
    	    profit += (double)items[i].value / items[i].weight * w;
    	
    	return profit;
    }
};
