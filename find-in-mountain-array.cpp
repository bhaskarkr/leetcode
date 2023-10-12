/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int bsr(int l, int r, int target, MountainArray &mountainArr) {
        while(l <= r) {
            int m = (l + r) / 2;
            int val = mountainArr.get(m);
            if(val == target) {
                return m;
            } else if(val > target) {
                l = m + 1;
            } else
                r = m - 1;
        }
        return -1;
    }
    int bsl(int l, int r, int target, MountainArray &mountainArr) {
        while(l <= r) {
            int m = (l + r) / 2;
            int val = mountainArr.get(m);
            if(val == target) {
                return m;
            } else if(val < target) {
                l = m + 1;
            } else
                r = m - 1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 0, r = mountainArr.length() - 1;
        while(l < r) {
            int m = (l + r) / 2;
            int val = mountainArr.get(m);
            if(m < r && mountainArr.get(m + 1) > val) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        cout<<l<<endl;
        int a = bsl(0, l, target, mountainArr);
        return a != -1 ? a : bsr(l + 1,  mountainArr.length() - 1, target, mountainArr);
    }
};
