class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if(n == 1 || n == 2)
            return true;
        int start = 2;
        string target = to_string(n);
        int targetLen = target.length();
        sort(target.begin(), target.end());
        while(1) {
            start *= 2;
            string curr = to_string(start);
            int currLen = curr.length();
            if(currLen == targetLen) {
                sort(curr.begin(), curr.end());
                if(curr == target)
                    return true;
            } else if(currLen < targetLen) {
                continue;
            } else {
                return false;
            }
        }
        return false;
    }
};
