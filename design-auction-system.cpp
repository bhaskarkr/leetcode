class AuctionSystem {
public:      
    unordered_map<int, unordered_map<int, int>> userItemToAmount;      
    unordered_map<int, set<tuple<int, int>>> itemUserBid;                     
    AuctionSystem() {
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        if(userItemToAmount[userId][itemId] != 0) {          
            itemUserBid[itemId].erase({userItemToAmount[userId][itemId], userId});
        }                
    
        userItemToAmount[userId][itemId] = bidAmount;        
        itemUserBid[itemId].insert({bidAmount, userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        addBid(userId, itemId, newAmount);  
    }
    
    void removeBid(int userId, int itemId) {     
        itemUserBid[itemId].erase({userItemToAmount[userId][itemId], userId});   
        userItemToAmount[userId][itemId] = 0;  
    }
    
    int getHighestBidder(int itemId) {
        if(itemUserBid[itemId].empty()) {
            return -1;
        }
        return get<1>(*itemUserBid[itemId].rbegin());
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */
