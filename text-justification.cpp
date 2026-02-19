class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;
        while(i < words.size()) {
            vector<string> temp = {words[i]};
            int len = words[i++].length();
            while(i < words.size() && len + 1 + words[i].length() <= maxWidth) {
                temp.push_back(' ' + words[i]);
                len += words[i].length() + 1;
                i++;
            }
            int spaces = maxWidth - len;
            if(temp.size() == 1) {
                ans.push_back(temp[0] + string(spaces, ' '));
            } else {
                int extraSpace = (spaces) / (temp.size() - 1);
                int additionalSpace = (spaces) % (temp.size() - 1);
                string concat;
                if(i < words.size()) {
                    for(int j = 0; j < temp.size() - 1; j++) {
                        temp[j] += string(extraSpace + (additionalSpace-- > 0 ? 1 : 0), ' ');
                        concat += temp[j];
                    }
                    concat += temp.back();
                } else {
                    for(int j = 0; j < temp.size(); j++) {
                        concat += temp[j];
                    }
                    concat += string(maxWidth - concat.length(), ' ');
                }
                ans.push_back(concat);
            }
        }
        return ans;
    }
};
