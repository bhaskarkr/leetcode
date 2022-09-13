class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = 0;
        for(auto byt : data) {
            if(n == 0) {
                if(byt>>3 == 0b11110)
                    n = 4 - 1;
                else if(byt>>4 == 0b1110)
                    n = 3 - 1;
                else if(byt>>5 == 0b110)
                    n = 2 - 1;
                else if(byt>>7)
                    return false;
                
            } else {
                n--;
                if(byt>>6 != 0b10)
                    return false;
            }
        }
        return n == 0;
    }
};
