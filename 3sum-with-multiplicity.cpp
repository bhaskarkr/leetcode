class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        /**
            a,b,c
            3a = target ->count[a]*(count[a]-1)*(count[a]-2)/3!
            2a+b = target ->count[a]*(count[a]-1)*count[b]/2!
            a+2b = target ->count[a]*count[b]*(count[b]-1)/2!
            a+b+c = target -> count[a]*count[b]*count[c]
        */
        long ans = 0;
        vector<int> count(101, 0);
        for(auto num : arr)
            count[num]++;
        for(int i = 0; i < 101; i++) {
            if(3*i == target)
                ans += (1L*count[i]*(count[i]-1)*(count[i]-2))/6;
            for (auto j = i + 1, k = target - i - j; j < 101; ++j, --k) {
                if (i * 2 + j == target) ans += count[i] * count[j] * (count[i] - 1) / 2;
                if (i + j * 2 == target) ans += count[i] * count[j] * (count[j] - 1) / 2;
                if (k > j && k < 101) ans += count[i] * count[j] * count[k];
            }
        }
        return ans%1000000007;
    }
};
