class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int p = 0, m = 0, g = 0, lp = 0, lm = 0, lg = 0, n = garbage.size(), ans = 0;
        travel.insert(travel.begin(), 0);
        for(int i = 0; i < n; i++) {
            if(i > 0)
                travel[i] += travel[i-1];
            for(char c : garbage[i]) {
                switch(c) {
                    case 'P': p++, lp = i;
                              break;
                    case 'M': m++, lm = i;
                              break;
                    default: g++, lg = i;
                }
            }
        }
        return travel[lp] + travel[lg] + travel[lm] + p + m + g;
    }
};
