class SnakeGame {
public:
    queue<pair<int, int>> snake;
    set<pair<int, int>> snakeSet;
    pair<int, int> curr = {0, 0};
    int w, h, score = 0;
    queue<pair<int, int>> food;
    unordered_map<string, pair<int, int>> moves = {
        {"U", {-1, 0}},
        {"D", {1, 0}},
        {"R", {0, 1}},
        {"L", {0, -1}}
    };
    SnakeGame(int width, int height, vector<vector<int>>& f) {
        w = width;
        h = height;
        snakeSet.insert({0, 0});
        snake.push({0, 0});
        for(auto &ff : f)
            food.push({ff[0], ff[1]});
    }
    
    int move(string direction) {
        int nx = curr.first + moves[direction].first;
        int ny = curr.second + moves[direction].second;
        if(nx >= h || nx < 0 || ny >= w || ny < 0)
            return -1;
        if(food.empty() || food.front().first != nx || food.front().second != ny) {
            snakeSet.erase(snakeSet.find({snake.front().first, snake.front().second}));
            snake.pop();
        } else
            score++, food.pop();
        if(snakeSet.find({nx, ny}) != snakeSet.end())
            return -1;
        snake.push({nx, ny});
        snakeSet.insert({nx, ny});
        curr = {nx, ny};
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
