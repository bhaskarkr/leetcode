class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> stk;
        map<string, int> temp;
        int i = 0, n = formula.length();
        while(i < n) {
            char c = formula[i];
            i++;
            if(c == '(') {
                stk.push(temp);
                temp.clear();
            } else if(c == ')') {
                int num = 0;
                while(i < n && isdigit(formula[i])) {
                    num = num*10 + (formula[i] - '0');
                    i++;
                }
                num = num == 0 ? 1 : num;
                if(!stk.empty()) {
                    map<string, int> temp2 = temp;
                    temp = stk.top();
                    stk.pop();
                    for(auto [k, v] : temp2) {
                        temp[k] += temp2[k] * num;
                    }
                }
            } else {
                string ele = "";
                ele.push_back(c);
                while(i < n && islower(formula[i])) {
                    ele.push_back(formula[i]); 
                    i++;
                }
                int num = 0;
                while(i < n && isdigit(formula[i])) {
                    num = num*10 + (formula[i] - '0');
                    i++;
                }
                num = num == 0 ? 1 : num;
                temp[ele] += num;
            }
        }
        string ans = "";
        for(auto [k, v] : temp) {
            ans += k + (v > 1 ? to_string(v) : "");
        }
        return ans;
        
    }
};
