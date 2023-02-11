class Solution {
public:
    bool isArmstrong(int n) {
        string s = to_string(n);
        int sum = 0, k = n, d = s.length();
        while(n > 0) {
            int t = n % 10;
            int m = d;
            int temp = t;
            while(--m > 0)
                temp*=t;
            sum += temp;
            cout<<sum<<endl;;
            n /= 10;
        }
        cout<<sum<<endl;;
        return sum == k;
    }
};
