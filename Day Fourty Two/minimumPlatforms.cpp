int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int i = 0, j = 1, collisions = 1;

    while (j < n)
    {
        if (arr[j] <= dep[i])
            collisions++;
        else
            i++;

        j++;
    }

    return collisions;
}
