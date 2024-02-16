class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> umap;
        for(auto num : arr)
            umap[num]++;
        priority_queue<int> pq;
        for(auto [k, v] : umap)
            pq.push(-v);
        while(!pq.empty() && (k += pq.top()) >= 0)
            pq.pop();
        return pq.size();
    }
};
