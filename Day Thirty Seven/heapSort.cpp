class Solution
{
public:
    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        for (int i=1;i<n;i++)
        {
            int childIndex = i;
            
            while (childIndex > 0)
            {
                int parentIndex = (childIndex - 1) / 2;
                
                if (arr[childIndex] > arr[parentIndex])
                    swap(arr[childIndex], arr[parentIndex]);
                else
                    break;
                
                childIndex = parentIndex;
            }
        }
        
        while (n > 0)
        {
            swap(arr[0], arr[--n]);
            int parentIndex = 0;
            
            while (true)
            {
                int left = 2 * parentIndex + 1, right = 2 * parentIndex + 2;
                
                if (right < n)
                {
                    if (arr[parentIndex] < arr[left] && arr[left] >= arr[right])
                    {
                        swap(arr[parentIndex], arr[left]);
                        parentIndex = left;
                    }
                    else if (arr[parentIndex] < arr[right])
                    {
                        swap(arr[parentIndex], arr[right]);
                        parentIndex = right;
                    }
                    else
                        break;
                }
                else if (left < n)
                {
                    if (arr[parentIndex] < arr[left])
                    {
                        swap(arr[parentIndex], arr[left]);
                        parentIndex = left;
                    }
                    else
                        break;
                }
                else
                    break;
            }
        }
    }
};
