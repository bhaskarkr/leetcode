class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        for(int &spell : spells) {
            int l = 0, r = potions.size() - 1;
            int temp = 0;
            while(l <= r) {
                int m = (l + r) / 2;
                if(potions[m] * 1L * spell >= success) {
                    temp = potions.size() - m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            spell = temp;
        }
        return spells;
    }
};
