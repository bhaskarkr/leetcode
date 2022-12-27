class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> a(250), b(250);
        stringstream ss1(version1), ss2(version2);
        string token;
        int i = 0;
        while(getline(ss1, token, '.')) {
            a[i++] = stoi(token);
        }
        int j = 0;
        while(getline(ss2, token, '.')) {
            b[j++] = stoi(token);
        }
        int limit = max(i, j), k = 0;
        while(k <= limit) {
            if(a[k] < b[k])
                return -1;
            else if(a[k] > b[k])
                return 1;
            k++;
        }
        return 0;
    }
};
