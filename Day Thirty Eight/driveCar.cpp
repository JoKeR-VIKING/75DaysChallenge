class Solution
{
public:
    long long required(long long arr[], long long n, long long k) 
    {
        long long ans = *(max_element(arr, arr + n)) - k;
        return ans <= 0 ? -1 : ans;
    }
};
