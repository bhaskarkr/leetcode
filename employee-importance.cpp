class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> u_map;
        for(int i = 0 ; i < employees.size(); i++) {
            u_map[employees[i]->id] = employees[i];
        }
        return getImportanceCount(u_map, id);
    }
    
    int getImportanceCount(unordered_map<int, Employee*> u_map, int id) {
        // cout<<(id)<<endl;
        int sum = u_map[id]->importance;
        for(int i = 0 ; i < u_map[id]->subordinates.size(); i++) {
            sum += getImportanceCount(u_map, u_map[id]->subordinates[i]);
        }
        return sum;
    }
};
