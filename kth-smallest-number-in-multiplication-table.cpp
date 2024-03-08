class Solution {
public:
    int isValid(int m, int n, int value) {
        int count = 0;
        for(int i = 1; i <= m; i++)
            count += min(n, value / i);
        return count;
    }
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(isValid(m, n, mid) >= k)
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
};
