class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> ans;
        for(int i = 1; i < currentState.length(); i++) {
            if(currentState[i] == '+' && currentState[i-1] == '+') {
                currentState[i] = '-';
                currentState[i-1] = '-';
                ans.push_back(currentState);
                currentState[i] = '+';
                currentState[i-1] = '+';
            }
        }
        return ans;
    }
};
