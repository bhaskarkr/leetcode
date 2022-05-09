class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        unordered_map<int, int> index;
        unordered_set<string> pairs;
        for(int i = 0; i < nums.size(); i++) {
            index[nums[i]] = i + 1;
        }
            
        for(auto seq : sequences) {
            for(int i = 1; i < seq.size(); i++) {
                if(index[seq[i-1]] > index[seq[i]] )
                    return false;
                pairs.insert(to_string(seq[i-1])+"_"+to_string(seq[i]));
            }
        }
        
        for(int i = 1; i < nums.size(); i++) {
           if(pairs.find(to_string(nums[i-1])+"_"+to_string(nums[i])) == pairs.end())
               return false;    
        }
        return true;
    } 
};
