class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int i = 0, j = 0, l1 = word1.length(), l2 = word2.length();
        vector<int> count1(26), count2(26);
        while(i < l1) {
            count1[word1[i]- 'a']++;
            i++;
        }
        while(j < l2) {
            count2[word2[j]- 'a']++;
            j++;
        }       
        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());
        set<char> s1(word1.begin(), word1.end()), s2(word2.begin(), word2.end());
        return count1 == count2 && s1 == s2;
    }
};
