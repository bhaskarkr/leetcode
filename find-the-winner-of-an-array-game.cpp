class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxEle = arr[0], c = 0;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] > maxEle) {
                maxEle = arr[i];
                c = 1;
            } else
                c++;
            if(c == k)
                return maxEle;
        }
        return maxEle;
    }
};
