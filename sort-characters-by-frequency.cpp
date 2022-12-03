class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> count(256);
        for(char c : s) {
            count[c].first++;
            count[c].second = c;
        }
        sort(count.rbegin(), count.rend());
        string ans = "";
        for(int i = 0; i < 256 && count[i].first;i++) {
            ans+= string(count[i].first, count[i].second);
           // while(count[i].first) {
           //     count[i].first--;
           //     ans+= count[i].second;
           // }
        }
        return ans;
    }
};
