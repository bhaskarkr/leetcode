class Solution {
public:
    string fractionToDecimal(long numerator, long denominator) {
        string ans = "";
        if(numerator == 0)
            return "0";
        if(numerator < 0 ^ denominator < 0)
            ans += '-';
        numerator = abs(numerator);
        denominator = abs(denominator);
        ans += to_string(numerator/denominator);
        if(numerator % denominator == 0)
            return ans;
        ans += '.';
        unordered_map<int, int> remainderPos;
        for(long remainder = numerator % denominator; remainder > 0; remainder = remainder % denominator) {
            if(remainderPos.count(remainder) > 0) {
                ans.insert(remainderPos[remainder], 1, '(');
                ans+= ')';
                return ans; 
            }
            remainderPos[remainder] = ans.size();
            remainder *= 10;
            ans += to_string(remainder/denominator);
        }
        return ans;
    }
};
