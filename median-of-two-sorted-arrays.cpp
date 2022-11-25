class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        if(len % 2) {
            return finder(nums1, nums2, len/2);
        } else {
            return (finder(nums1, nums2, len/2-1) + finder(nums1, nums2, len/2))/2.0;
        }
            
    }
    
    double finder(vector<int>& nums1, vector<int>& nums2, int index) {
        if(nums1.empty())
            return nums2[index];
        if(nums2.empty())
            return nums1[index];
        int n1 = nums1.size(), n2 = nums2.size();
        int i1 = n1 / 2, i2 = n2 / 2;
        int m1 = nums1[i1], m2 = nums2[i2];
        if(i1 + i2 < index) {
            if(m1 > m2) {
                vector<int> temp(nums2.begin() + i2 + 1, nums2.end());
                return finder(nums1, temp, index - i2 -1);
            } else {
                vector<int> temp(nums1.begin() + i1 + 1, nums1.end());
                return finder(temp, nums2, index - i1 -1);
            }
        } else {
            if(m1 > m2) {
                vector<int> temp(nums1.begin(), nums1.begin() + i1);
                return finder(temp, nums2, index);
            } else {
                vector<int> temp(nums2.begin(), nums2.begin() + i2);
                return finder(nums1, temp, index);
            }
        }
    }
};
