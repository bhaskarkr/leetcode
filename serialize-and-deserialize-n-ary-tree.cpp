/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    string ans;
    int index = 0;
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if(!root)
            return "# ";
        string temp = to_string(root->val) + " ";
        temp += to_string(root->children.size()) + " ";
        for(auto child : root->children) {
            temp += serialize(child) + " ";
        }
        return temp;
    }

    Node* helper(istringstream &in) {
        string val, count;
        in >> val;
        if(val == "#") {
            return NULL;
        }
        in >> count;
        int temp = stoi(count);
        Node* root = new Node(stoi(val));
        while(temp--) {
            root->children.push_back(helper(in));
        }
        return root;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream in(data);
        cout<<data<<endl;
        return helper(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
