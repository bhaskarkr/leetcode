class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string temp;
        for(string s : strs) {
            temp += to_string(s.length()) + "#" + s;
        }
        return temp;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int index = 0;
        while(index < s.length()) {
            int splitPos = s.find('#', index);
            int len = stoi(s.substr(index, splitPos - index));
            ans.push_back(s.substr(splitPos + 1, len ));
            index = splitPos + len + 1;

        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
