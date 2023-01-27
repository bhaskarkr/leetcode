class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<set<string>> bucket(31);
        set<string> ans;
        for(auto word : words) {
            bucket[word.length()].insert(word);
        }
        for(int i = 2; i < 31; i++) {
            for(auto word : bucket[i]) {
                helper(word, 0, bucket, ans, 0);
            }
        }
        vector<string> vec_ans(ans.begin(), ans.end());
        return vec_ans;
    }

    void helper(string &s, int index, vector<set<string>> &bucket, set<string> &ans, int count) {
        if(index >= s.length()) {
            if(count > 1)
                ans.insert(s);
            return;
        }
        for(int len = 1; len <= s.length() - index; len++) {
            if(bucket[len].find(s.substr(index, len)) != bucket[len].end()) {
                helper(s, index + len, bucket, ans, count + 1);
            }
        }
    }
};
