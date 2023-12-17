class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> um;
    unordered_map<string, pair<int, string>> foodRating; 
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++) {
            um[cuisines[i]].insert({ratings[i], foods[i]});
            foodRating[foods[i]] = {ratings[i], cuisines[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        um[foodRating[food].second].erase(um[foodRating[food].second].find({foodRating[food].first, food}));
        foodRating[food] = {newRating, foodRating[food].second};
        um[foodRating[food].second].insert({newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto curr = um[cuisine].rbegin();
        while(next(curr) != um[cuisine].rend() && curr->first == next(curr)->first) {
            curr = next(curr);
        }
        return curr->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
