/*

https://leetcode.com/problems/insert-delete-getrandom-o1

*/

#include<vector>
#include<unordered_map>

using namespace std;

class RandomizedSet {

    vector<int> set;
    unordered_map<int, int> indexMap;

public:
    RandomizedSet() {
        set = vector<int>();
        indexMap = unordered_map<int, int>();   
    }
    
    bool insert(int val) {
        if(indexMap.find(val) != indexMap.end()) {
            return false;
        }

        indexMap[val] = set.size();
        set.push_back(val);
        
        return true;
    }
    
    bool remove(int val) {
        if(indexMap.find(val) == indexMap.end()) {
            return false;
        }

        int lastEl = set.back();
        set[indexMap[val]] = lastEl;
        set.pop_back();
        indexMap[lastEl] = indexMap[val];
        indexMap.erase(val);

        return true;
    }
    
    int getRandom() {
        return set[rand()%set.size()];
    }
};

int main() {
    return 0;
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */