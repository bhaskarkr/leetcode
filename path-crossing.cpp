class Solution {
public:
    bool isPathCrossing(string path) {
        int v = 0, h = 0;
        set<pair<int, int>> us;
        us.insert({0, 0});
        for(char c : path) {
            switch(c) {
                case 'N' : v++; break;
                case 'S' : v--; break;
                case 'E' : h++; break;
                case 'W' : h--; break;
            }
            if(us.find({h, v}) != us.end())
                return true;
            us.insert({h, v});
        }
        return false;
    }
};
