class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        vector<int> arr;
        int day = 1;
        for(int num : bulbs) {
            auto itr = lower_bound(arr.begin(), arr.end(), num);
            if(arr.empty())
                arr.push_back(num);
            else if(itr == arr.end()) {
                if(num - arr.back() - 1 == k)
                    return day;
                arr.push_back(num);
            }
            else {
                if(itr != arr.begin() && num - (*prev(itr)) - 1 == k)
                    return day;
                if(itr != arr.end() && (*itr) - num - 1 == k)
                    return day;
                arr.insert(itr, num);
            }
            day++;
        } 
        /*
            [6,5,8,9,7,1,10,2,3,4]
            [5,6,7,8,9,]
        */
        return -1;
    }
};
