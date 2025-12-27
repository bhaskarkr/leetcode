class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> c(26);
        int i = 0, j = 0, ans = 0, n = s.length(), maxCount = 0;
        while(i < n) {
            c[s[i] - 'A']++;
            maxCount = max(maxCount, c[s[i] - 'A']);
            while(i - j + 1 - maxCount > k) {
                c[s[j] - 'A']--;
                j++;
            }
            ans = max(ans, i - j + 1);
            i++;
        }
        return ans;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> c(26);
        int i = 0, j = 0, ans = 0, n = s.length();
        while(i < n) {
            c[s[i] - 'A']++;
            int maxCount = 0, maxChar = 'A';
            for(int a = 0; a < 26; a++) {
                if(c[a] > maxCount) {
                    maxCount = c[a];
                    maxChar = a + 'A';
                }
            }
            int invalid = i - j + 1 - maxCount;
            if(invalid > k) {
                c[s[j] - 'A']--;
                if(s[j] != maxChar)
                    invalid--;
                j++;
            }
            ans = max(ans, i - j + 1);
            i++;
        }
        return ans;
    }
};


class Solution {
public:
    int getMaxCount(vector<int> &counter) {
        int maxCount = 0;
        for(int i : counter)
            maxCount = max(maxCount, i);
        return maxCount;
    }
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);
        int start = 0, end = 0, ans = 0;
        for(char c : s) {
            counts[c - 'A']++;
            end++;
            while(end - start - getMaxCount(counts) > k) {
                counts[s[start++]-'A']--;
            }
            ans = max(ans, end - start);
        }
        return ans;

    }
};


class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> uset(s.begin(), s.end());
        int ans = 0;

        for(char c : uset) {
            int count = 0, K = k;
            for(int r = 0, l = 0; r < s.length(); r++) {
                while(K < 0 && l < r) {
                    if(s[l] != c)
                        K++;
                    l++;
                }
                if(s[r] != c)
                    K--;
                if(K >= 0)
                    ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};
