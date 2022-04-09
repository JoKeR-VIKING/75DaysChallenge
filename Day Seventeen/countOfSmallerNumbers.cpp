class Solution {
public:
    void mergeSort(vector<pair<int, int>>& nums, int start, int end, vector<int>& smallerMap)
    {
        if (start >= end)
            return;

        int mid = start + (end - start) / 2;

        mergeSort(nums, start, mid, smallerMap);
        mergeSort(nums, mid + 1, end, smallerMap);

        vector<pair<int, int>> temp;
        int i = start, j = mid + 1;

        while (i <= mid && j <= end)
        {
            if (nums[i].first <= nums[j].first)
            {
                temp.push_back(nums[j]);
                j++;
            }
            else
            {
                smallerMap[nums[i].second] += end - j + 1;
                temp.push_back(nums[i]);
                i++;
            }
        }

        while (i <= mid)
        {
            temp.push_back(nums[i]);
            i++;
        }

        while (j <= end)
        {
            temp.push_back(nums[j]);
            j++;
        }

        for (int k=start;k<=end;k++)
            nums[k] = temp[k - start];
    }
    
    vector<int> countSmaller(vector<int>& nums) 
    {
        vector<pair<int, int>> newNums;
        vector<int> temp(nums.size());
        
        for (int i=0;i<nums.size();i++)
            newNums.push_back({nums[i], i});
        
        mergeSort(newNums, 0, newNums.size() - 1, temp);
        
        return temp;
    }
};
