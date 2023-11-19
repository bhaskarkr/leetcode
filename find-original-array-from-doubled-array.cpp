class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int, int> mp;
        for(int n : changed)
            mp[n]++;
        vector<int> ans;
        if(changed.size() % 2)
            return {};
        for(auto &[k, v] : mp) {
            while(v > 0 && mp[2*k] >= v) {
                v--;
                ans.push_back(k);
                mp[2*k]--;
            }
            if(v > 0)
                return {};
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2)
            return {};
        int minN = INT_MAX, maxN = INT_MIN;
        vector<int> vec(200005);
        for(int i : changed) {
            vec[i]++;
            minN = min(minN, i);
            maxN = max(maxN, i);
        }
        vector<int> ans((changed.size()/2));
        int j = 0;
        for(int i = minN; i <= maxN; i++) {
            if(vec[i] == 0)
                continue;
            if(vec[2*i] < vec[i])
                return {};
            while(vec[i]-- > 0) {
                vec[2*i]--;
                ans[j++] = i;
            }
        }
        return ans;
    }
};
