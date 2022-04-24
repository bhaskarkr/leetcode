class UndergroundSystem {
public:
    unordered_map<string, pair<int, int>> startToEndSumAndCount;
    unordered_map<int, pair<string, int>> idToStartStation;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        idToStartStation[id]  = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int duration = t - idToStartStation[id].second;
        string key = idToStartStation[id].first + "-" + stationName;
        if(startToEndSumAndCount.find(key) == startToEndSumAndCount.end())
            startToEndSumAndCount[key] = {duration, 1};
        else {
             startToEndSumAndCount[key].first += duration;  
            startToEndSumAndCount[key].second++;  
        }
        idToStartStation.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "-" + endStation;
        return (startToEndSumAndCount[key].first*1.0) /startToEndSumAndCount[key].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
