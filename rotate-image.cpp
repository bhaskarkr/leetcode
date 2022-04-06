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
