class Solution {
public:
    int countPoints(string rings) {
        int n = rings.length() / 2;
        vector<int> vec(10);
        int ans = 0;
        for(int i = 0; i < rings.length(); i += 2) {
            char color = rings[i];
            int rodIndex = rings[i+1] - '0';
            int shift = 0;
            switch(color) {
                case 'R': vec[rodIndex] |= 1 << 0;
                     break;
                case 'G': vec[rodIndex] |= 1 << 1;
                    break;
                case 'B': vec[rodIndex] |= 1 << 2;
                    break;
            }
        }
        for(int i = 0; i < 10; i++)
            if(vec[i] == 7)
                ans++;
        return ans;
    }
};
