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



class Solution {
public:
    vector<string> transformer(vector<int> nums) {
        vector<string> ans;
        for(int num: nums) {
            string temp = string(nums.size(), '.');
            for(int i = 0; i < nums.size(); i++) {
                if((num >> i)&1)
                    temp[i] = 'Q';
            }
            ans.push_back(temp);
        }   
        cout<<endl;
        return ans;
    }

    void helper(vector<vector<string>> &ans,  vector<int> &tracker, int n) {
        if(tracker.size() == n) {
            ans.push_back(transformer(tracker));
            return;
        }
        for(int pos = 0; pos < n; pos++) {
            int curr = 1 << pos;
            bool isValid = true;
            for(int shift = 1; shift <= tracker.size(); shift++) {
                int left = (curr << shift) & tracker[tracker.size() - shift];
                int right = (curr >> shift) & tracker[tracker.size() - shift];
                int col = curr & tracker[tracker.size() - shift];
                if(left || right || col) {
                    isValid = false;
                    break;
                }  
            }
            if(isValid) {
                tracker.push_back(curr);
                helper(ans, tracker, n);
                tracker.pop_back();
            }   
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> tracker;
        vector<vector<string>> ans;
        helper(ans, tracker, n);
        return ans;
    }
};
