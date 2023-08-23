class Solution {
public:
    string nextClosestTime(string time) {
        vector<char> digits;
        for(char c : time) {
            if(c == ':')
                continue;
            digits.push_back(c);
        }
        sort(digits.begin(), digits.end());
        vector<string> numbers;
        for(char ten : digits) {
            for(char one : digits) { 
                string k = "";
                k.push_back(ten);
                k.push_back(one);             
                numbers.push_back(k);
            }
        }
        auto nextMinute = upper_bound(numbers.begin(), numbers.end(), time.substr(3));
        if(nextMinute != numbers.end() && *nextMinute < "60") {
            return time.substr(0, 3) + (*nextMinute);
        }

        auto nextHour = upper_bound(numbers.begin(), numbers.end(), time.substr(0, 2));
        if(nextHour != numbers.end() && *nextHour < "24") {
            return  (*nextHour) + ":" + numbers[0];
        }
        return numbers[0]+":"+numbers[0];

    }
};
