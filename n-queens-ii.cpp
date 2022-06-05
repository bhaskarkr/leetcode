class Solution {
public:
    int totalNQueens(int n) {
        vector<int> bitArr(n);
        int ans = 0;
        int  occupied = 0;
        dfs(n, 0, bitArr, ans, 0);
        return ans;
    }
    
    void dfs(int n, int curr, vector<int> bitArr, int &ans, int occupied) {
        if(curr == n) {
            ans++;
            return; 
        }
        
        for(int i = 0; i < n;  i++) {
            bitArr[curr] = (1 << i);
            if(occupied & bitArr[curr])
                continue;
            bool isValid = true;
            for(int j = 1; j <= curr && isValid; j++) {
                if((bitArr[curr - j]&(bitArr[curr]<<j)) || (bitArr[curr  - j]&(bitArr[curr]>>j)))  {
                    // cout<<"fff"<<endl;
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
