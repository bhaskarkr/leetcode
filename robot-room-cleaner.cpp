/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    const vector<pair<int, int>> dir = {{-1,  0}, {0, 1}, {1, 0}, {0, -1}}; 
    void cleanRoom(Robot& robot) {
        set<string> visited;
        dfs(robot, 0, 0, 0, visited);
    }
    
    void dfs(Robot &robot, int x,  int y, int curr,  set<string> &visited) {
        robot.clean();
        visited.insert(to_string(x)+"_"+to_string(y));
        for(int i =  curr; i < curr + 4; i++) {
           int nx = x + dir[i%4].first;
           int ny = y + dir[i%4].second;
            if(visited.find(to_string(nx)+"_"+to_string(ny)) == visited.end()  && robot.move()) {
                dfs(robot, nx, ny, i%4, visited);
            }    
            robot.turnRight();
        }
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
};
