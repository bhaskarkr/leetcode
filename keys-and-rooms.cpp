class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> visited; 
        visited.insert(0);
        dfs(0, rooms, visited);
        return visited.size() == rooms.size();
    }

    void dfs(int index, vector<vector<int>>& rooms, set<int>& visited) {
        for(auto key : rooms[index]) {
            if(visited.find(key) == visited.end()) {
                visited.insert(key);
                dfs(key, rooms, visited);
            }   
        }

               
    }
};
