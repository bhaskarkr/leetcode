class Solution {
public:
    char solver(vector<char> values, char op) {
        switch(op) {
            case '&' : {
                if(count(values.begin(), values.end(), 'f'))
                    return 'f';
                break;
            } 
            case '|' : {
                if(count(values.begin(), values.end(), 't'))
                    return 't';
                return 'f';
            }
            case '!' : {
                return values[0] == 't' ? 'f' : 't';
            }
        }
        return 't';
    }
    char helper(int &index, string &exp) {
        char op = exp[index++];
        index++; // (
        vector<char> vals;
        while(index < exp.length() && exp[index] != ')') {
            if(exp[index] == 't')
                vals.push_back('t'), index++;
            else if(exp[index] == 'f')
                vals.push_back('f'), index++;
            else if(exp[index] == ',')
                index++;
            else
                vals.push_back(helper(index, exp));
        }
        index++; // )
        return solver(vals, op);
    }
    bool parseBoolExpr(string expression) {
        int index = 0;
        return helper(index, expression) == 't';
    }
};
