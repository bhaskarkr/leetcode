class Solution {
public:
    vector<int> subTreeNodeCount, bottomUpCount, topDownCount;
    vector<vector<int>> adMat;
    int N;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        subTreeNodeCount.assign(n, 1);
        bottomUpCount.resize(N);
        adMat.resize(N);
        for(auto edge : edges) {
            adMat[edge[0]].push_back(edge[1]);
            adMat[edge[1]].push_back(edge[0]);
        }
        postOrder(0, -1);
        topDownCount.assign(bottomUpCount.begin(), bottomUpCount.end());
        preOrder(0, -1);
        return topDownCount;
    }

    void preOrder(int curr, int prev) {
        for(auto child : adMat[curr]) {
            if(child == prev)
                continue;
            // will decrease by one for each node in subtree
            int nodesChildSide = subTreeNodeCount[child]; 
            // will increase by one for each node in upper side i.e parent side
            int nodesOnParentSide = N - subTreeNodeCount[child];
            topDownCount[child] = topDownCount[curr] - nodesChildSide + nodesOnParentSide;
            preOrder(child, curr);
        }
    }

    void postOrder(int curr, int prev) {
        for(auto child : adMat[curr]) {
            if(child == prev)
                continue;
            postOrder(child, curr);
            subTreeNodeCount[curr] += subTreeNodeCount[child];
            bottomUpCount[curr] += subTreeNodeCount[child] + bottomUpCount[child];
        }
    }
};
