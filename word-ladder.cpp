class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> uset(wordList.begin(), wordList.end());
        queue<string> Q;
        Q.push(beginWord);
        uset.erase(beginWord);
        int ans = 1;
        while(!Q.empty()) {
            int c = Q.size();
            while(c--) {
                auto curr = Q.front();
                Q.pop();
                if(curr == endWord) {
                    return ans;
                }
                for(int index = 0; index < curr.size(); index++) {
                    char c = curr[index];
                    for(char nc = 'a'; nc <= 'z'; nc++) {
                        curr[index] = nc;
                        if(nc == c)
                            continue;
                        if(uset.find(curr) != uset.end()) {
                            Q.push(curr);
                            uset.erase(curr);
                        }
                    }
                    curr[index] = c;
                }
            }
            ans++;
        }
        return 0;
    }
};
