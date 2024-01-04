class Solution {
public:
    
    string nearestPalindromic(string n) {
        long num = stol(n);
        if(n.length() == 1) {
            return to_string(num - 1);
        }
        int digit = n.length();
        int prefLen = (digit + 1) / 2;
        
        vector<long> candidates = {(long) pow(10, digit - 1) - 1, (long) pow(10, digit) + 1};
        
        long pref = stol(n.substr(0, prefLen));
        vector<long> prefixes = {pref, pref - 1, pref + 1};
        for(auto pref : prefixes) {
            string post = to_string(pref);
            if(digit % 2)
                post.pop_back();
            reverse(post.begin(), post.end());
            string prefPost = to_string(pref) + post;
            candidates.push_back(stol(prefPost));
        }
        long minDiff = INT_MAX, ans = INT_MAX;
        for(auto cand : candidates) {
            if(cand != num && abs(cand - num) < minDiff)
            {
                minDiff = abs(cand - num);
                ans = cand;
            } else if(abs(cand - num) == minDiff)
                ans = min(ans, cand);
        }

        return to_string(ans);
    }
};
