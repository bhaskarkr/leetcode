class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> PQ;
        for(int num : nums) {
            if(num % 2) 
                num *= 2;
            PQ.insert(num);
        }
        int ans = *PQ.rbegin() - *PQ.begin();
        while(!PQ.empty() && *PQ.rbegin() % 2 == 0) {
            int num = *PQ.rbegin();
            PQ.erase(prev(PQ.end()));
            num /= 2;
            PQ.insert(num);
            ans = min(ans, *PQ.rbegin() - *PQ.begin());
        }
        return ans;
    }
};
