/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * class FontInfo {
 *   public:
 *     // Return the width of char ch when fontSize is used.
 *     int getWidth(int fontSize, char ch);
 *     
 *     // Return Height of any char when fontSize is used.
 *     int getHeight(int fontSize)
 * };
 */
class Solution {
public:
    int getCustomWidth(int fSize, string s, FontInfo fontInfo) {
        int width = 0;
        for(char c : s) {
            width += fontInfo.getWidth(fSize, c);
        }
        return width;
    }
    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
        int l = 0, r = fonts.size() - 1;
        int ans = -1;
        while(l <= r) {
            int m = (r + l) / 2;
            int fSize = fonts[m];
            if(fontInfo.getHeight(fSize) <= h && getCustomWidth(fSize, text, fontInfo) <= w) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans != -1 ? fonts[ans] : -1;
    }
};
