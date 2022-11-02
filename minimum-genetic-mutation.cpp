class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(start == end)
            return 0;
        unordered_set<string> bankSet;
        unordered_set<string> visited;
        for(auto b : bank)
            bankSet.insert(b);
        queue<string> Q;
        Q.push(start);
        visited.insert(start);
        vector<char> charMut = {'A', 'C', 'G', 'T'};
        int ans = 0;
        while(!Q.empty()) {
            int count = Q.size();
            while(count--) {
                auto ele = Q.front();
                Q.pop();
                if(ele == end)
                    return ans;
                for(char &c : ele) {
                    char prev = c;
                    for(char m : charMut) {
                        c = m;
                        if(visited.find(ele) == visited.end() && bankSet.find(ele) != bankSet.end()) {
                            visited.insert(ele);
                            Q.push(ele);
                        }
                    }
                    c = prev;
                }
            }
            ans++;
        }
        return -1;
    }
};
