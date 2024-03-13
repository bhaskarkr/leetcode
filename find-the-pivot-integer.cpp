class Solution {
public:
    int pivotInteger(int n) {
        int sum = (n * (n + 1)) / 2, temp = 0;
        for(int x = 1; x <=n; x++) {
            if(temp + x == sum - temp)
                return x;
            temp += x;
        }
        return -1;
    }
};


class Solution:
    def pivotInteger(self, n: int) -> int:
        l = 1
        r = n
        total = (r * (r + 1)) // 2 
        while(l <= r):
            m = (l + r) // 2
            ls = (m * (m - 1)) // 2
            rs = total - (m * (m + 1)) // 2
            if ls == rs:
                return m
            elif ls < rs:
                l = m + 1
            else:
                r = m - 1
        return -1
