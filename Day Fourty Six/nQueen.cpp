class Solution {
public:
    bool arr[10][10];
    vector<vector<int>> result;
    bool check(int x, int y, int n) {
        for (int k = 0; k < n; k++)
            if (arr[x][k] || arr[k][y])
                return false;
        for (int k = 0; x - k >= 0 || y - k >= 0 || x + k < n || y + k < n; k++) {
            if (x - k >= 0 && y - k >= 0 && arr[x - k][y - k])
                return false;
            if (x - k >= 0 && y + k < n && arr[x - k][y + k])
                return false;
            if (x + k < n && y - k >= 0 && arr[x + k][y - k])
                return false;
            if (x + k < n && y + k < n && arr[x + k][y + k])
                return false;
        }
        return true;
    }
    void help(int y, int n, vector<int>& p) {
        if (y == n) {
            if (p.size() == n)
                result.push_back(p);
            return;
        }
        for (int x = 0; x < n; x++) {
            if (check(x, y, n)) {
                arr[x][y] = true;
                p.push_back(x + 1);
                help(y + 1, n, p);
                arr[x][y] = false;
                p.pop_back();
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        memset(arr, false, sizeof(arr));
        vector<int> p;
        help(0, n, p);
        return result;    
    }
};
