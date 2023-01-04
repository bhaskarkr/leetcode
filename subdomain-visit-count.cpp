class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> counter;
        for(string s : cpdomains) {
            int index = s.find(' ');
            int count = stoi(s.substr(0, index));
            s = s.substr(index + 1);
            counter[s] += count;
            while(true) {
                index = s.find('.');
                if(index == string::npos)
                    break;
                index++;
                string domain = s.substr(index);
                counter[domain] += count;
                s = s.substr(index);
            }
        }
        vector<string> ans;
        for(auto [k, v] : counter) {
            ans.push_back(to_string(v)+" "+k);
        }
        return ans;
    }
};
