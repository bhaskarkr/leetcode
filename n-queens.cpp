class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> bitArr(n);
        vector<vector<string>> ans;
        int  occupied = 0;
        dfs(n, 0, bitArr, ans, 0);
        return ans;
    }
    
    void dfs(int n, int curr, vector<int> bitArr, vector<vector<string>> &ans, int occupied) {
        if(curr == n) {
            vector<string> temp;
            for(auto bit : bitArr) {
                string  s =  "";
                for(int i = 0; i < n;  i++) {
                    s.push_back(bit & (1<<i) ? 'Q' : '.'); 
                }
                temp.push_back(s);
            }
            ans.push_back(temp);
            return; 
        }
        
        for(int i = 0; i < n;  i++) {
            bitArr[curr] = (1 << i);
            if(occupied & bitArr[curr])
                continue;
            bool isValid = true;
            for(int j = 1; j <= curr && isValid; j++) {
                if((bitArr[curr - j]&(bitArr[curr]<<j)) || (bitArr[curr  - j]&(bitArr[curr]>>j)))  {
                    isValid  = false;
                }
            }
            if(isValid) {
                occupied |= bitArr[curr];
                dfs(n, curr  + 1, bitArr, ans, occupied);
                occupied ^= bitArr[curr];
            }   
        }
    }
};
