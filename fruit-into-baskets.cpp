class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start = 0, end = 0, ans = 0, n = fruits.size();
        unordered_map<int, int> count;
        while(end < n) {
            count[fruits[end++]]++;
            while(count.size() > 2) {
                count[fruits[start]]--;
                if(count[fruits[start]] == 0) {
                    count.erase(fruits[start]);
                }
                start++;
            }
            ans = max(ans, end - start);
        }
        return ans;
    }
};
