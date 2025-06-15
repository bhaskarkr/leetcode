class Solution {
public:
    int maxDiff(int num) {
        vector<int> av, bv;
        string s = to_string(num);
        for(char c : s) {
            string a = s;
            string b1 = s;
            string b2 = s;
            for(char &ch : a) {
                if(ch == c)
                    ch = '9';
            }
            if(b1[0] != c) {
                for(int i = 0; i < b1.length(); i++) {
                    if(b1[i] == c)
                        b1[i] = '0';
                }
                bv.push_back(stoi(b1));
            }

            for(int i = 0; i < b2.length(); i++) {
                if(b2[i] == c)
                    b2[i] = '1';
            }
            bv.push_back(stoi(b2));
            av.push_back(stoi(a));
        }
        sort(av.rbegin(), av.rend());
        sort(bv.begin(), bv.end());

        return *av.begin() - *bv.begin();
    }
};
