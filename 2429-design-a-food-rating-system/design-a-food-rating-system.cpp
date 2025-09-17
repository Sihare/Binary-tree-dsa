class FoodRatings {
private:
    unordered_map<string, set<pair<int, string>>> cuisine;
    unordered_map<string, pair<string , int>> high;
public:
    FoodRatings(vector<string>& foods, vector<string>& types, vector<int>& ratings) {
        for (int i = 0, n = foods.size(); i < n; ++i) {
            cuisine[types[i]].insert({ -ratings[i], foods[i]});
            high[foods[i]] = {types[i], ratings[i]};
        }
    }
    void changeRating(string food, int newRate) {
        string type = high[food].first;
        cuisine[type].erase({ -high[food].second, food});
        cuisine[type].insert({ -newRate, food});
        high[food].second = newRate;
    }
    string highestRated(string type) {
        return cuisine[type].begin()->second;
    }
};
