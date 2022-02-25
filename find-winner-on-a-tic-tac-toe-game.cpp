class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> A(8), B(8);
        for(int i = 0; i < moves.size(); i++) {
            vector<int> &player = i % 2 ? B : A;
            int x = moves[i][0], y = moves[i][1];
            player[x]++;
            player[y+3]++;
            
            if(x == 1 && y == 1)
                player[7]++, player[6]++;
            else if(x==y)// LT -> RB
                player[6]++;
            else if(x == y-2 || x == y+2)
                player[7]++;    
        }
        for(int i = 0; i < 8; i++) {
            if(A[i] == 3)
                return "A";
            else if(B[i] == 3)
                return "B";
        }
        return moves.size() != 9 ? "Pending" : "Draw";
    }
};
