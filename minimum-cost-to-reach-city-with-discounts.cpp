class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        unordered_map<int, vector<pair<int, int>>> adMat;
        for(auto &h : highways) {
            adMat[h[0]].push_back({h[1], h[2]});
            adMat[h[1]].push_back({h[0], h[2]});
        }
        vector<vector<int>> costs(n, vector<int>(discounts + 1, 1e9));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int cost = curr[0], discountUsed = curr[1], node = curr[2];
            if(node == n - 1)
                return cost;
            for(auto &child : adMat[node]) {
                int newCost = cost + child.second;
                int newCostWithDiscount = cost + child.second / 2;
                int nextNode = child.first;
                if(discountUsed < discounts && costs[nextNode][discountUsed + 1] > newCostWithDiscount) {
                    costs[nextNode][discountUsed + 1] = newCostWithDiscount;
                    pq.push({newCostWithDiscount, discountUsed + 1, nextNode});
                } 
                if(costs[nextNode][discountUsed] > newCost){
                    costs[nextNode][discountUsed] = newCost;
                    pq.push({newCost, discountUsed, nextNode});
                }
            }
        }
        return -1;
    }
};
