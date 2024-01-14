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


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> c1(26), c2(26);
        for(char c: word1)
            c1[c - 'a']++;
        for(char c: word2)
            c2[c - 'a']++;
        priority_queue<int> pq1, pq2;
        for(int i = 0; i < 26; i++)
            if(c1[i])
                pq1.push(c1[i]), pq2.push(c2[i]);
        while(!pq1.empty() && !pq2.empty()) {
            if(pq1.top() != pq2.top())
                break;
            pq1.pop(), pq2.pop();
        }
        return pq1.empty() && pq2.empty();
    }
};
