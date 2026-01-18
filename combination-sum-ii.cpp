class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        helper(0, candidates, target, 0, temp, ans);
        return ans;
    }

    void helper(int index, vector<int> &candidates, int &target, int currSum, vector<int> &currEle, vector<vector<int>> &ans) {
        if(currSum == target) {
            ans.push_back(currEle);
            return;
        }
        if(currSum > target || index >= candidates.size())
            return;
        for(int i = index; i < candidates.size(); i++) {
            if(i > index && candidates[i] == candidates[i-1])
                continue;
            currEle.push_back(candidates[i]);
            helper(i + 1, candidates, target, currSum + currEle.back(), currEle, ans);
            currEle.pop_back();
        }
    }

};


class Solution {
public:
    void helper(vector<vector<int>> &ans, int index, vector<int>& candidates, vector<int> &curr, int target) {
        if(index > candidates.size())
            return;
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        for(int i = index; i < candidates.size(); i++) {
            if(i > index && candidates[i] == candidates[i-1])
                continue;
            if(target >= candidates[i]) {
                curr.push_back(candidates[i]);
                helper(ans, i + 1, candidates, curr, target - candidates[i]);
                curr.pop_back();
            }  
        }           
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int index = 0;
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(ans, 0, candidates, curr, target);
        return ans;
    }
};
