class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int num : nums) {
            int div = 0;
            for(int d = 2; d * d <= num; d++) {
                if(num % d == 0) {
                    if(div == 0) {
                        div = d;
                    } else {
                        div = 0;
                        break;
                    }
                }
            }
            if(div > 0 && div != num / div) {
                ans += 1 + div + num + num /div;
            }
        }
        return ans;
    }
};
