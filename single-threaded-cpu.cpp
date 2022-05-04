class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
        int n = tasks.size();
        vector<vector<int>> enTask(n);
        for(int i = 0; i < n; i++) {
            //            enTime,  index, procTime
            enTask[i] = {tasks[i][0], i, tasks[i][1]};
        }
        sort(enTask.begin(), enTask.end());
        long time = 0;
        int itr = 0;
        vector<int> ans;
        while(ans.size() < n) {
            while(itr < n && time >= enTask[itr][0]) {
                //                   procTime          index          enqTime(not required)
                pair<int, int> temp = {enTask[itr][2], enTask[itr][1]}; //, enTask[itr][0]};
                PQ.push(temp);
                itr++;
            }
            if(PQ.empty()) {
                time = enTask[itr][0];
                continue;
            }
            auto curr = PQ.top();
            PQ.pop();
            ans.push_back(curr.second);
            time += curr.first;
        }    
        return ans;
    }
};
