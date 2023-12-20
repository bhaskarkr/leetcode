class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        unordered_map<int, vector<int>> seats;
        for(auto rs : reservedSeats)
            seats[rs[0]].push_back(rs[1]);
        int ans = 0;
        for(auto [k, v] : seats) {
            v.insert(v.begin(), 1);
            v.push_back(10);
            for(auto c = next(v.begin()); c != v.end(); c++) {
                int s = *prev(c);
                int e = *c;
                bool s1 = (s < 2 && e > 5);
                bool s2 = (s < 4 && e > 7);
                bool s3 = (s < 6 && e > 9);
                if(s1 || s3)
                    ans += s1 + s3;
                else if(s2)
                    ans++;
            }
        }
        ans += 2 * (n - seats.size());
        return ans;
    }
};
