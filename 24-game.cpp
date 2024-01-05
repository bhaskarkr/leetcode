class Solution {
public:
    vector<double> generator(double a, double b) {
        vector<double> ops = {a + b, a - b, b - a, a * b};
        if(b != 0) ops.push_back(a / b);
        if(a != 0) ops.push_back(b / a);
        return ops;
    }
    bool helper(vector<double> &cards) {
        if(cards.size() <= 1)
            return abs(cards[0] - 24.0) < 0.1;
        for(int i = 0; i < cards.size(); i++) {
            for(int j = i + 1; j < cards.size(); j++) {
                vector<double> temp;
                for(int k = 0; k < cards.size(); k++)
                    if(k != i && k != j)
                        temp.push_back(cards[k]);
                vector<double> possibilities = generator(cards[i], cards[j]);
                for(double poss : possibilities) {
                    temp.push_back(poss);
                    if(helper(temp)) return true;
                    temp.pop_back();
                }
            }
        } 
        return false;
    }
    bool judgePoint24(vector<int> &cards) {
        vector<double> doubleCards(cards.begin(), cards.end());
        return helper(doubleCards);
    }
};
