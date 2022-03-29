class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> charSecret(10), charGuess(10);
        int bulls = 0;
        int cows = 0;
        for(int i = 0; i < secret.length(); i++) {
            if(guess[i] == secret[i])
                bulls++;
            else {
                charGuess[guess[i] - '0']++;
                charSecret[secret[i] - '0']++;
            }
        }
        for(int i = 0; i < 10; i++)
            cows+=min(charSecret[i], charGuess[i]);
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};
