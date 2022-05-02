class Solution {
public:
    bool canTransform(string start, string end) {
        int i = -1;
        int j = -1;
        int m = start.length(), n = end.length();
        while(true) {
            while(++i < m && start[i] == 'X');
            while(++j < n && end[j] == 'X');
            if(i == m || j == n)
                break;
            if(start[i] != end[j] || (start[i] == 'L' ? i < j : i > j))
                return false;
        }
        return i == m && j == n;
    }
};
