class Solution {
public:
    int numberOfDays(int year, int month) {
        if(month == 2) {
            if(year % 100 == 0)
                return year % 400 == 0 ? 29 : 28;
            return year % 4 == 0 ? 29 : 28;
        }
        month--;
        return ((month % 7) % 2 == 0) ? 31 : 30;
    }
};
