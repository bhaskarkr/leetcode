class Solution {
public:
    string breakPalindrome(string palindrome) {
        for(int i = 0; i < palindrome.length()/2; i++) {
            if(palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }      
        }
        if(palindrome.length() > 1) {
            palindrome[palindrome.length() - 1]++;
            return palindrome;
        }
            
        return "";
    }
};
