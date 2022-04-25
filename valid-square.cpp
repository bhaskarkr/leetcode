class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int, int> distance;
        distance[getDistance(p1, p2)]++;
        distance[getDistance(p2, p3)]++;
        distance[getDistance(p3, p4)]++;
        distance[getDistance(p1, p3)]++;
        distance[getDistance(p2, p4)]++;
        distance[getDistance(p1, p4)]++;
        bool dia = false;
        bool sides = false;
        for(auto [k, v] : distance)
            if(k == 0)
                return false;
            else if(v == 4)
                sides = true;
            else if(v == 2)
                dia = true;
            else
                return false;
        return dia && sides;
    }
    
    int getDistance(vector<int>& p1, vector<int>& p2) {
        return (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
    }
};
