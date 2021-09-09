#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

class LRUCache {
public:

    LRUCache() {this->capacity = 100;}
    LRUCache(size_t capacity) {this->capacity = capacity;}

    const std::string get(const std::string& key) {
        time++;
        if (mp.find(key) == mp.end())
            return std::string("");
        else
        {
            size_t tm = keyTime[key];
            keyTime[key] = time;
            timeKey.erase(tm);
            timeKey[time] = key;
            return mp[key];
        }
    }

    void  set (const std::string& key, const std::string& value) {
        time++;
        if (mp.size() == capacity)
        {
            if (mp.find(key) == mp.end())
            {
                auto top = *(timeKey.begin());
                timeKey.erase(top.first);
                keyTime.erase(top.second);
                mp[key] = value;
                mp.erase(top.second);
                keyTime[key] = time;
                timeKey[time] = key;
            }
            else
            {
                size_t tm = keyTime[key];
                keyTime[key] = time;
                timeKey.erase(tm);
                timeKey[time] = key;
            }
        }
        else
        {
            if (mp.find(key) == mp.end())
            {
                keyTime[key] = time;
                timeKey[time] = key;
                mp[key] = value;
            }
            else
            {
                size_t tm = keyTime[key];
                keyTime[key] = time;
                timeKey.erase(tm);
                timeKey[time] = key;
            }
        }
    }

    void printCache() {
        std::cout << "Current time is:" << this->time << " \nCache is: " << endl;
        for (auto it : timeKey)
            cout << it.first << " " << it.second << endl;
    }

private:
    size_t capacity;
    size_t time = 0;
    unordered_map <std::string, std::string> mp;
    map <std::string, int> keyTime;
    map <int, std::string> timeKey;
};

int main() {    
    LRUCache* lru10 = new LRUCache(3);
    lru10->set("a","b");
    lru10->set("b","c");
    lru10->set("c","d");
    lru10->printCache();
    lru10->set("b","c");
    lru10->printCache();
    lru10->get("a");
    lru10->printCache();
    return 0;
}
