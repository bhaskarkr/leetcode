class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0, n = start.length();
        while(i <= n and j <= n) {
            while(i < n and start[i] == '_')
                i++;
            while(j < n and target[j] == '_')
                j++;
            if(i == n or j == n)
                return i == n and j == n;
            if(start[i] != target[j]) 
                return false;
            if(target[j] == 'L') {
                if(j > i)
                    return false;
            } else {
                if(i > j)
                    return false;
            }
            i++, j++;
        }
        return true;
    }
};
