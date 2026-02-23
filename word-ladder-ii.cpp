class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> uset(wordList.begin(), wordList.end());
        queue<vector<string>> Q;
        Q.push({beginWord});
        uset.erase(beginWord);
        vector<vector<string>> ans;
        bool found = false;
        while(!Q.empty()) {
            int c = Q.size();
            unordered_set<string> toRemove;
            while(c--) {
                auto curr = Q.front();
                Q.pop();
                string temp = curr.back();
                if(temp == endWord) {
                    found = true;
                    // cout<<"reached"<<endl;
                    ans.push_back(curr);
                    continue;
                }
                for(int index = 0; index < temp.size(); index++) {
                    char c = temp[index];
                    for(char nc = 'a'; nc <= 'z'; nc++) {
                        temp[index] = nc;
                        if(nc == c)
                            continue;
                        if(uset.find(temp) != uset.end()) {
                            curr.push_back(temp);
                            Q.push(curr);
                            curr.pop_back();
                            toRemove.insert(temp);
                        }
                    }
                    temp[index] = c;
                }
            }
            for(string s : toRemove) {
                uset.erase(s);
            }
        }
        return ans;
    }
};
