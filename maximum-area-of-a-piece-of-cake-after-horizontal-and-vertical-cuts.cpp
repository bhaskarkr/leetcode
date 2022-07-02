class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.emplace_back(0);
        verticalCuts.push_back(0);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        int maxHeight = 0;
        int maxWidth = 0;
        for(int i = 1; i < horizontalCuts.size(); i++) {
            maxHeight = max(maxHeight, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        for(int i = 1; i < verticalCuts.size(); i++) {
            maxWidth = max(maxWidth, verticalCuts[i] - verticalCuts[i-1]);
        }
        return (1L*maxWidth*maxHeight)%1000000007L;
    }
};
