class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        function<char(char)> increment = [&](char c) {
            if(c == '9')
                return '0';
            c++;
            return c;
        };
        function<char(char)> decrement = [&](char c) {
            if(c == '0')
                return '9';
            c--;
            return c;
        };
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if(visited.find("0000") != visited.end()) 
            return -1;
        visited.insert("0000");
        queue<string> Q;
        Q.push("0000");
        int steps = 0;
        while(!Q.empty()) {
            int c = Q.size();
            while(c--) {
                string curr = Q.front();
                Q.pop();
                if(curr == target)
                    return steps;
                for(int d = 0; d < 4; d++) {
                    curr[d] = increment(curr[d]);
                    if(visited.find(curr) == visited.end()) {
                        visited.insert(curr);
                        Q.push(curr);
                    }
                    curr[d] = decrement(curr[d]);
                    curr[d] = decrement(curr[d]);
                    if(visited.find(curr) == visited.end()) {
                        visited.insert(curr);
                        Q.push(curr);
                    }
                    curr[d] = increment(curr[d]);
                }
            }
            steps++;
        }
        return -1;
    }
};
