class Solution {
public:
    /*
        [1,5,9],
        [10,11,13],
        [12,13,15]
    */
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n - 1][n-1];
        while(l < r) {
            int m = l + (r - l) / 2;
            int num = 0;
            for(int i = 0; i < n; i++) {
                int pos = upper_bound(matrix[i].begin(), matrix[i].end(), m) - matrix[i].begin();
                num += pos;
            }
            if(num < k)
                l = m + 1;
            else 
                r = m;
        }
        return l;
    }
};
