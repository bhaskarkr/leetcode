class Solution {
public:
    /*
              Case 1                  Case 2                  Case 2
                b                       b                       b
       +----------------+      +----------------+      +----------------+
       |                |      |                |      |                |
       |                |      |                |      |                |
     c |                | a  c |                | a  c |                | a
       |                |      |                |      |                |    f
       +--------------->|      |                |      |                | <----+
                d       |      |                ^ e    |                |      | e
                               |                |      |                       |
                               +----------------+      +-----------------------+
                                        d                       d
    */
    bool isSelfCrossing(vector<int>& distance) {
        for(int i = 3; i < distance.size(); i++) {
            if(distance[i] >= distance[i-2] 
                && distance[i-1] <= distance[i-3])
                return true;
            if(i > 3 
                && distance[i-4] + distance[i] >= distance[i-2] 
                && distance[i-1] == distance[i-3]) 
                return true;
            if(i > 4 
                && distance[i-4] <= distance[i-2] 
                && distance[i-1] <= distance[i-3]
                && distance[i] + distance[i-4] >= distance[i-2] 
                && distance[i-1] + distance[i-5] >= distance[i-3])
                return true;
        }
        return false;
    }
};
