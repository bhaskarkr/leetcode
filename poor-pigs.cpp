class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs = 0;
        int totalRoundPlusLastLeftOver = minutesToTest/minutesToDie + 1;
        while(pow(totalRoundPlusLastLeftOver, pigs) < buckets)
            pigs++;
        return pigs;
    }
};
