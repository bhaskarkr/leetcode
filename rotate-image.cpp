class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /**
            [[1,2,3],      [[7,4,1],
             [4,5,6],       [8,5,2],
             [7,8,9]]       [9,6,3]]
              0, 0     ->   0, m-1
              0, m-1   -> n-1, m-1
            n-1, m-1   -> n-1, 0
              n-1, 0   -> 0, 0 
        */
        int low = 0, high = matrix.size() - 1;
        while(low < high) {
            for(int i = 0; i < (high - low); i++) {
                swap(matrix[low][low+i], matrix[low+i][high]);
                swap(matrix[low][low+i], matrix[high][high-i]);
                swap(matrix[low][low+i], matrix[high-i][low]);
            }
            low++;
            high--;
        }
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /**
        *
        [
            [5,1,9,11],
            [2,4,8,10],
            [13,3,6,7],
            [15,14,12,16]]
            0,0 -> 3,3
            0,1 -> 2,3
            0,2 -> 1,3
            1,0 -> 3,2
            1,1 -> 2,2
        */
        int m = matrix.size();
        for(int i = 0; i < m; i++) 
            reverse(matrix[i].begin(), matrix[i].end());
        for(int i = 0; i < m - 1; i++) {
            for(int j = 0; j < m - 1 - i; j++) {
                swap(matrix[i][j], matrix[m-1-j][m-1-i]);
            }
        }
    }
};
