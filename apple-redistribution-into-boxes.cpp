class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
        int j = 0;
        for(int i = 0; i < apple.size(); i++) {
            while(capacity[j] < apple[i]) {
                capacity[j + 1] += capacity[j];
                j++;
            }
            capacity[j] -= apple[i]; 
        }
        return j + 1;
    }
};
