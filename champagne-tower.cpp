class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // 4
        // (4-1) / 2 = 1.5   (4-1) / 2 = 1.5 
        // (1.5-1)/2 = 0.25  (1.5-1)/2 = 0.25    (1.5-1)/2 = 0.25
        //                          +
        //                   (1.5-1)/2 = 0.25                    
        vector<double> DP(102);
        DP[0] = poured;
        for(int i = 1; i <= query_row; i++) {
            for(int j = query_row - 1; j >= 0; j--) {
                DP[j] = 0.0 > (DP[j] - 1)/2 ? 0.0 : (DP[j] - 1)/2;
                DP[j+1] += DP[j];  
            }
        }
        return 1.0 < DP[query_glass] ?  1.0 : DP[query_glass];
    }
};


class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> DP(102);
        DP[0] = poured;
        for(int row = 1; row <= query_row; row++) {
            for(int glass = row - 1; glass >= 0; glass--) {
                DP[glass] = (DP[glass] - 1) / 2.0 < 0 ? 0.0 :  (DP[glass] - 1) / 2.0;
                DP[glass + 1] += DP[glass];
            }
        }
        return DP[query_glass] > 1.0 ? 1.0 : DP[query_glass];
    }
};
