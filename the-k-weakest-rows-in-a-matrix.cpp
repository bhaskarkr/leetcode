class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> countVec;
        for(int i = 0; i < mat.size(); i++) {
            int tempCount = 0;
            for(int j = 0; j < mat[0].size() && mat[i][j]; j++) {
                tempCount++;
            }
            countVec.push_back({tempCount, i});
        }
        sort(countVec.begin(), countVec.end());
        vector<int> ans;
        int i = 0;
        while(i < k)
            ans.push_back(countVec[i++].second);
        return ans;
    }
};
