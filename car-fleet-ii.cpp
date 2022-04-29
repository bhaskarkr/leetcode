class Solution {
public:
    
    double calculateCollision(vector<int> c1, vector<int> c2) {
        int dist = c2[0] - c1[0];
        int speed = c1[1] - c2[1];
        return 1.0*(dist)/speed;
    }
    
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> ans(n, -1);
        stack<int> frontCars;
        for(int c1 = n - 1; c1 >= 0 ; c1--) {
            while(!frontCars.empty()) {
                int c2 = frontCars.top();
                if(cars[c1][1] > cars[c2][1] && (ans[c2] == -1 || calculateCollision(cars[c1], cars[c2]) <= ans[c2])) {
                    ans[c1] = calculateCollision(cars[c1], cars[c2]);
                    break;
                }
                frontCars.pop()              ;
            }
            frontCars.push(c1);
        }
        return ans;
    }
};
