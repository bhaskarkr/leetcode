class Solution {
public:
    int smallestRepunitDivByK(int k) {
       long i = 1, ans = 1;
        i = i % k;
        unordered_set<int> mods;
        while(i <= k) { 
            if(i == 0)
                return ans;
            if(mods.find(i) != mods.end())
                return -1;
            mods.insert(i);
            i = i * 10 + 1;
            i %= k;
            ans++;
        }
        return -1;
    }
};
