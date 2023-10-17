class File {
public:    
    bool isFile;
    map<string, File*> children;
    string content;
};
class FileSystem {
public:
    File* root;
    FileSystem() {
        root = new File();
    }
    
    vector<string> ls(string path) {
        string subdir;
        stringstream ss(path.substr(1));
        auto curr = root;
        while(getline(ss, subdir, '/')) {
            curr = curr->children[subdir];
        }
        if(curr->isFile) {
            return {subdir};
        }
        vector<string> ans;
        for(auto [k, v] : curr->children)
            ans.push_back(k);
        return ans;
    }
    
    void mkdir(string path) {
        string subdir;
        stringstream ss(path.substr(1));
        auto curr = root;
        while(getline(ss, subdir, '/')) {
            if(curr->children.find(subdir) == curr->children.end())
                curr->children[subdir] = new File();
            curr = curr->children[subdir];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        string subdir;
        stringstream ss(filePath.substr(1));
        auto curr = root;
        while(getline(ss, subdir, '/')) {
            if(curr->children.find(subdir) == curr->children.end())
                curr->children[subdir] = new File();
            curr = curr->children[subdir];
        }
        curr->isFile = true;
        curr->content += content;
    }
    
    string readContentFromFile(string filePath) {
        string subdir;
        stringstream ss(filePath.substr(1));
        auto curr = root;
        while(getline(ss, subdir, '/')) {
            curr = curr->children[subdir];
        }
        return curr->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
