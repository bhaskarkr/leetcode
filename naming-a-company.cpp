class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<char, unordered_set<string>> mapped;
        for(string s : ideas) {
            mapped[s[0]].insert(s.substr(1));
        }
        long long ans = 0;
        char c1 = 'a';
        while(c1 <= 'z') {
            char c2 = 'a';
            while(c2 <= 'z') {
                int l1 = 0, l2 = 0;
                for(auto &s : mapped[c1]) {
                    if(mapped[c2].find(s) == mapped[c2].end())
                        l1++;
                }
                for(auto &s : mapped[c2]) {
                    if(mapped[c1].find(s) == mapped[c1].end())
                        l2++;
                }
                ans += l1*l2;
                c2++;
            }
            c1++;
        }
        return ans;
    }
};

// class Solution {
// public:
//     long long distinctNames(vector<string>& ideas) {
//         unordered_map<char, set<string>> mapped;
//         for(string s : ideas) {
//             mapped[s[0]].insert(s.substr(1));
//         }
//         long long ans = 0;
//         char c1 = 'a';
//         char c2 = 'a';
//         while(c1 <= 'z') {
//             while(c2 <= 'z') {
//                 int l1 = 0, l2 = 0;
//                 bool f = mapped[ideas[i].substr(1)].find(ideas[i]) == mapped[ideas[i].substr(1)].end();
//                 bool s = mapped[ideas[j].substr(1)].find(ideas[j]) == mapped[ideas[j].substr(1)].end();
//             }
//         }
//         for(int i = 0; i < ideas.size() - 1; i++) {
//             swap(ideas[i][0], ideas[j][0]);
//             bool f = mapped[ideas[i].substr(1)].find(ideas[i]) == mapped[ideas[i].substr(1)].end();
//             bool s = mapped[ideas[j].substr(1)].find(ideas[j]) == mapped[ideas[j].substr(1)].end();
//             if(f && s) {
//                 ans+=2;
//             }
//             swap(ideas[i][0], ideas[j][0]);
//         }
//         return ans;
//     }
// };
