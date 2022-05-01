class Solution {
public:
    string alphabetBoardPath(string target) {
        string step = "";
        int cx = 0;
        int cy = 0;
        for(char c : target) {
            int nx = (c - 'a') / 5;
            int ny = (c - 'a') % 5;
            step += nx < cx ? string(cx - nx, 'U') : "";
            step += ny > cy ? string(ny - cy, 'R') : "";
            step += ny < cy ? string(cy - ny, 'L') : "";
            step += nx > cx ? string(nx - cx, 'D') : "";
            cx = nx;
            cy = ny;
            step += "!";
        }
        return step;
    }

};
