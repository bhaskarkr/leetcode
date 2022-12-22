class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        vector<int> slots(1000005);
        for(auto inter : intervals) {
            slots[inter[0]]++;
            slots[inter[1]]--;
        }
        for(int i = 1; i <= 1000000; i++) {
            slots[i]+=slots[i-1];
            if(slots[i] > 1)
                return false;
        }
        return true;
    }
};
