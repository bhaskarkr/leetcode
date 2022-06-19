class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        string cur = "";
        auto itr = products.begin();
        for(char c : searchWord) {
            cur.push_back(c);
            vector<string> sug;
            itr = lower_bound(itr, products.end(), cur);
            for(int  i = 0; i < 3 && itr + i != products.end(); i++)  {
                string s = *(itr + i);
                if(s.find(cur) == string::npos)
                    break;
                sug.push_back(s);
            }
            ans.push_back(sug);
        }
        return ans;
    }
};
