class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<long> histogram(s.length() + 1, 0);
        for(auto shift : shifts) {
            if(shift[2]) {
                histogram[shift[0]]++;
                histogram[shift[1] + 1]--;
            } else {
                histogram[shift[0]]--;
                histogram[shift[1] + 1]++;
            }
        }
        for(int i = 0; i < histogram.size(); i++) {
            if(i)
                histogram[i] += histogram[i-1];
            s[i] = 'a' + (((s[i] - 'a') + histogram[i]) % 26 + 26) % 26; 
        }
            
        return s;
    }
};
