class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX, c = INT_MIN, d = INT_MIN;
        for(auto num : nums) {
            if(a > num) {
                b = a;
                a = num;
            } else if(b > num)
                b = num;

            if(c < num) {
                d = c;
                c = num;
            } else if(d < num)
                d = num;
        }
        return (c*d) - (a*b);
    }
};
