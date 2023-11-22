/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> temp, result, merged;
        for(auto emp : schedule) {
            for(auto sc : emp) {
                temp.push_back(sc);
            }
        }
        sort(temp.begin(), temp.end(), [](auto a, auto b) {
            return a.start < b.start;
        });
        merged.push_back(temp[0]);
        for(int i = 1; i < temp.size(); i++) {
            if(temp[i].start <= merged.back().end)
                merged.back().end = max(temp[i].end, merged.back().end);
            else
                merged.push_back(temp[i]);
        }

        for(int i = 1; i < merged.size(); i++) {
            Interval t(merged[i-1].end, merged[i].start);
            result.push_back(t);
        }
        return result;
    }
};
