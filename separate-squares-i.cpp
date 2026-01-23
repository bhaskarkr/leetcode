class Solution {
public:

    double helper(vector<vector<int>>& squares, double y_split) {
        double bottom_area = 0;
        double upper_area = 0;
        for(auto &square : squares) {
            double edge = square[2];
            double y_up = square[1] + edge;
            double y_bottom = square[1];
            if(y_bottom >= y_split) {
                upper_area += edge * edge;
            } else if (y_up <= y_split){
                bottom_area += edge * edge;
            } else {
                upper_area += edge * (y_up - y_split);
                bottom_area += edge * (y_split - y_bottom);
            }
        }
        return upper_area - bottom_area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double l = 0;
        double r = 2*10e9;
        while(r - l > 1e-5) {
            double m = (r + l) / 2.0;
            double val = helper(squares, m);
             if(val > 0) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }
};
