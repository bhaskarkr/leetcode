class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string, int> inDegree;
        unordered_map<string, vector<string>> ingreToRec;
        for(int i = 0; i < n; i++) {
            for(string ingre : ingredients[i]) {
                ingreToRec[ingre].push_back(recipes[i]);
            }
            inDegree[recipes[i]] = ingredients[i].size();
        }
        vector<string> ans;
        queue<string> Q;
        for(string sup : supplies)
            Q.push(sup);
        while(!Q.empty()) {
            string curr = Q.front();
            Q.pop();
            for(string rec : ingreToRec[curr]) {
                inDegree[rec]--;
                if(inDegree[rec] == 0) {
                    Q.push(rec);
                    ans.push_back(rec);
                }
            }
        }
        
        return ans;
    }
};
