class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);
        while(w*(area/w) != area) {
            w--;
        }
        return {area/w, w};
    }
};
