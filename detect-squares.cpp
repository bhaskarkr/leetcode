class DetectSquares {
public:
    unordered_map<int, multiset<int>> xCoor;
    DetectSquares() {
    }
    
    void add(vector<int> point) {
        xCoor[point[0]].insert(point[1]);
    }
    
    int count(vector<int> point) {
        int ans = 0;
        set<int> yCoor(xCoor[point[0]].begin(), xCoor[point[0]].end());
        vector<int> uniqYCoor(begin(yCoor), end(yCoor));
        for(int i = 0; i < uniqYCoor.size(); i++) {
            int diff = abs(uniqYCoor[i] - point[1]);
            if(diff < 1)
                continue;
            int possibleLowerX = point[0] - diff;
            int possibleUpperX = point[0] + diff;
            ans += xCoor[possibleLowerX].count(point[1]) * xCoor[possibleLowerX].count(uniqYCoor[i]) * xCoor[point[0]].count(uniqYCoor[i]);
            ans += xCoor[possibleUpperX].count(point[1]) * xCoor[possibleUpperX].count(uniqYCoor[i]) * xCoor[point[0]].count(uniqYCoor[i]);
        }
        return ans;
    }
};


class DetectSquares {
    public:
    unordered_map<int, map<int, int>> xCoor;
    DetectSquares() {
    }
    
    void add(vector<int> point) {
        xCoor[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int ans = 0;
        vector<pair<int, int>> yCoor(xCoor[point[0]].begin(), xCoor[point[0]].end());
        for(int i = 0; i < yCoor.size(); i++) {
            int diff = abs(yCoor[i].first - point[1]);
            if(diff < 1)
                continue;
            int possibleLowerX = point[0] - diff;
            int possibleUpperX = point[0] + diff;
            ans += xCoor[possibleLowerX][point[1]] * xCoor[possibleLowerX][yCoor[i].first] * xCoor[point[0]][yCoor[i].first];
            ans += xCoor[possibleUpperX][point[1]] * xCoor[possibleUpperX][yCoor[i].first] * xCoor[point[0]][yCoor[i].first];
        }
        return ans;
    }
};
