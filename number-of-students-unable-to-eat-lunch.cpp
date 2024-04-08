class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> stu;
        for(int i = 0; i < sandwiches.size(); i++) {
            stu.push(students[i]);
        }
        for(int i = 0; i < sandwiches.size(); i++) {
            int c = stu.size();
            while(c-- && stu.front() != sandwiches[i]) {
                stu.push(stu.front());
                stu.pop();
            }
            if(stu.front() == sandwiches[i]) {
                stu.pop();
            } else 
                break;
        }
        return stu.size();
    }
};
