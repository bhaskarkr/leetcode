class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i  = 0, j = 0;
        for(auto elem : pushed) {
            pushed[i++] = elem;
            while(i>0 && pushed[i-1] == popped[j]) {
                j++;
                i--;
            }
        }
        return i == 0;  
    }
};
