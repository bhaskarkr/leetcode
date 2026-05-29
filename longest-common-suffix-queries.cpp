
class Node {
public:
    int index;
    vector<Node*> children = vector<Node*>(26, NULL);
};
class Solution {
public:

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<pair<string, int>> pairs;
        for(int i = 0; i < wordsContainer.size(); i++) {
            pairs.push_back({wordsContainer[i], i});
        }
        sort(pairs.begin(), pairs.end(), [](auto &a , auto &b) {
            if(a.first.length() == b.first.length())
                return a.second > b.second;
            return a.first.length() > b.first.length();
        });
        auto root = new Node();
        root->index = pairs.back().second;
        vector<int> ans;
        int i = 0;
        for(auto &pair : pairs) {
            string word = pair.first;
            auto temp = root;
            Node* prev = NULL;
            reverse(word.begin(), word.end());
            for(char c : word) {
                if(!temp->children[c - 'a'])
                    temp->children[c - 'a'] = new Node();
                prev = temp;
                temp = temp->children[c - 'a'];
                temp->index = pair.second;
            }
            i++;
        }

        for(string &word : wordsQuery) {
            auto temp = root;
            reverse(word.begin(), word.end());
            int tempAns = root->index;
            for(char c : word) {
                if(!temp->children[c - 'a']) {
                    // cout<<"temp "<<temp->index<<endl;
                    break;
                }
                // cout<<c<<" "<<endl;
                temp = temp->children[c - 'a'];
                tempAns = temp->index;
                // cout<<temp->index<<endl;
            }
            ans.push_back(tempAns);
        }
        return ans;
    }
};
