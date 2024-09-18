class RandomizedSet {
    vector<int>vec;             // vec { val , val , val ...}
    unordered_map<int,int>mp;   // val -> vec index
public:
    RandomizedSet() {
        
    }
    
    bool search(int val){
        if(mp.find(val) == mp.end())
            return false;
        return true;
    }
    
    bool insert(int val) {
        if(search(val))
            return false;
        vec.push_back(val);
        mp[val] = vec.size() - 1;   // map store the val -> vector index
        return true;
    }
    
    bool remove(int val) {
        if(!search(val))
            return false;
        auto it = mp.find(val);
        int vec_index = it->second;
        vec[vec_index] = vec.back();    //replace vec_index value with last value 
        vec.pop_back();                 //then poping last value of vector
        mp[vec[vec_index]] = vec_index; //then updating the map for last value
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return vec[rand() % vec.size()];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */