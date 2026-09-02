class LFUCache {
public:

    int capacity;
    int minFreq;

    // key -> {value, frequency}
    unordered_map<int, pair<int, int>> data;

    // frequency -> keys
    // front = recently used
    // back = least recently used
    unordered_map<int, list<int>> freqList;

    // key -> position in freqList
    unordered_map<int, list<int>::iterator> position;


    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }


    // Increase frequency of a key
    void increaseFreq(int key) {

        int freq = data[key].second;

        // Remove key from old frequency list
        freqList[freq].erase(position[key]);

        // If old minimum frequency list becomes empty
        if (freqList[freq].empty() && minFreq == freq) {
            minFreq++;
        }

        // Increase frequency
        data[key].second++;

        int newFreq = data[key].second;

        // Put key at front of new frequency list
        freqList[newFreq].push_front(key);

        // Update position
        position[key] = freqList[newFreq].begin();
    }


    int get(int key) {

        // Key doesn't exist
        if (data.find(key) == data.end()) {
            return -1;
        }

        // Key is being used, so frequency increases
        increaseFreq(key);

        return data[key].first;
    }


    void put(int key, int value) {

        // Capacity = 0
        if (capacity == 0) {
            return;
        }


        // Key already exists
        if (data.find(key) != data.end()) {

            // Update value
            data[key].first = value;

            // Updating an existing key counts as usage
            increaseFreq(key);

            return;
        }


        // Cache is full
        if (data.size() == capacity) {

            // Least frequently used list
            // Take the least recently used key
            int lruKey = freqList[minFreq].back();

            // Remove from frequency list
            freqList[minFreq].pop_back();

            // Remove from maps
            position.erase(lruKey);
            data.erase(lruKey);
        }


        // Insert new key
        data[key] = {value, 1};

        // New key has frequency 1
        freqList[1].push_front(key);

        // Store its position
        position[key] = freqList[1].begin();

        // New key has minimum frequency
        minFreq = 1;
    }
};