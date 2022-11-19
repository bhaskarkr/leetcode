class Solution {
public:
    
    int comp(vector<int> &p1, vector<int> &p2, vector<int> &p3) {
        return (p3[1]-p2[1])*(p2[0]-p1[0])-(p2[1]-p1[1])*(p3[0]-p2[0]);
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end());
        
        vector<vector<int>> lower, upper;
        for(auto tree : trees) {
            while(lower.size() > 1 && comp(lower[lower.size()-2], lower[lower.size()-1], tree) < 0)
                lower.pop_back();
            while(upper.size() > 1 && comp(upper[upper.size()-2], upper[upper.size()-1], tree) > 0)
                upper.pop_back();
            lower.push_back(tree);
            upper.push_back(tree); 
        }
        set<vector<int>> finalTrees(upper.begin(), upper.end());
        finalTrees.insert(lower.begin(), lower.end());
        vector<vector<int>> ans(finalTrees.begin(), finalTrees.end());
        return ans;
    }
};
