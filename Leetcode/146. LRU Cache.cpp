class LRUCache {
    int capacity;
    map<int,int>mp;
    vector<int>v;
    vector<int>::iterator i;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        i = find(v.begin(),v.end(),key);
        if(i==v.end())return -1;
        v.erase(i);
        v.push_back(key);
        return mp[key];
    }
    
    void put(int key, int value) {
            i = find(v.begin(),v.end(),key);
            if(i!=v.end()){
                v.erase(i);
            }
            if((int)v.size()==capacity){
                mp.erase(v[0]);
                v.erase(v.begin());
            }
            mp[key]=value;
            v.push_back(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
