class LRUCache {
public:
    int capacity;

    // {key, value}
    list<pair<int, int>> lru;

    // key -> position in list
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        // Key doesn't exist
        if (mp.find(key) == mp.end())
            return -1;

        // Get the node
        auto it = mp[key];
        int value = it->second;

        // Move it to front because it is recently used
        lru.erase(it);
        lru.push_front({key, value});

        // Update map
        mp[key] = lru.begin();

        return value;
    }
    
    void put(int key, int value) {
        // Key already exists
        if (mp.find(key) != mp.end()) {
            // Remove old node
            lru.erase(mp[key]);

            // Add updated node at front
            lru.push_front({key, value});

            // Update map
            mp[key] = lru.begin();
        }
        else {
            // If cache is full
            if (lru.size() == capacity) {
                // Last element = least recently used
                auto last = lru.back();

                // Remove it from map
                mp.erase(last.first);

                // Remove it from list
                lru.pop_back();
            }

            // Add new key-value at front
            lru.push_front({key, value});

            // Store its position
            mp[key] = lru.begin();
        }
    }
};