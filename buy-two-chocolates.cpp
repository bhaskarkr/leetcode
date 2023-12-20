class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int a = 200, b = 200;
        for(auto p : prices) {
            if(p <= a) {
                b = a;
                a = p;
            } else if(b > p)
                b = p;
        } 
        return  money - a - b >= 0 ? money - a - b: money;
    }
};
