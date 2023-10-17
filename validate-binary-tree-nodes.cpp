class Solution {
public:

    bool traverse(int curr, vector<int>& leftChild, vector<int>& rightChild, set<int> &visited) {
        if(visited.find(curr) != visited.end())
            return false;
        visited.insert(curr);
        if(leftChild[curr] != -1 && (visited.find(leftChild[curr]) != visited.end() || !traverse(leftChild[curr], leftChild, rightChild, visited)))
            return false;
        if(rightChild[curr] != -1 && (visited.find(rightChild[curr]) != visited.end() || !traverse(rightChild[curr], leftChild, rightChild, visited)))
            return false;
        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n);
        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1) 
                indegree[leftChild[i]]++;
            if(rightChild[i] != -1)
                indegree[rightChild[i]]++;
        }
        int root = -1;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                if(root != -1)
                    return false;
                root = i;
            }
            if(indegree[i] > 1)
                return false;
        }
        if(root == -1)
            return false;
        set<int> visited;
        return traverse(root, leftChild, rightChild, visited) && visited.size() == n;
    }
};
