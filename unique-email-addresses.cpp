class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> ans;
        for(auto email : emails) {
            string t;
            bool ignore = false;
            bool domain = false;
            for(char c : email) {
                if(!domain && c == '+')
                    ignore = true;
                else if(c == '@') {
                    domain = true;
                    ignore = false;
                    t += c;
                }
                else if(!domain && c == '.')
                    continue;
                if(!ignore)
                    t += c;
            }
            ans.insert(t);
        }   
        return ans.size();
    }
};
