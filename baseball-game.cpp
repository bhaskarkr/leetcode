class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> data(ops.size());
        int ans = 0;
        int j = 0;
        for(int i = 0; i < ops.size(); i++) {
            if(ops[i] == "+") {
                data[j] = data[j - 1] + data[j - 2];
                j++;
            } else if(ops[i] == "D") {
                data[j] = 2 * data[j - 1];
                j++;
            } else if(ops[i] == "C") {
                data[j - 1] = 0;
                j--;
            } else {
                data[j] = stoi(ops[i]);
                j++;
            }
        }
        for(int num : data)
            ans+=num;
        return ans;
    }
};
