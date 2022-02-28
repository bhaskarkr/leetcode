class Logger {
public:
    unordered_map<string, int> mapper;
    Logger() {
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(mapper.find(message) == mapper.end() || timestamp - mapper[message] >= 10) {
            mapper[message] = timestamp;
            return true;
        } else {
            return false;
        }
        
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
