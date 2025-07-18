class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        queue<string> q;
        int i = 0;
        q.push("");
        vector<string> inps = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        while(i < digits.length()) {
            int cn = q.size();
            while(cn--) {
                string curr = q.front();
                q.pop();
                int num = digits[i] - '0' - 2;
                for(char c : inps[num])
                    q.push(curr + c);
            }
            i++;
        }
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
            
        return ans.size() == 1 ? vector<string>() : ans;
    }
};
