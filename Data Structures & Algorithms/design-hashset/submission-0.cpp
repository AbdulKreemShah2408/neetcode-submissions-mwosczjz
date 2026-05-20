#include <vector>
#include <algorithm>
class MyHashSet {
    int num_bucket;
     std::vector<std::vector<int>>bucket;
    int getHash(int key){
        return key%num_bucket;
    }
public:
    MyHashSet() {
        num_bucket=1007;
        bucket.resize(num_bucket);
    }
   
    void add(int key) {
        if(contains(key)) return ;
        int index=getHash(key);
        bucket[index].push_back(key);
    }
    
    void remove(int key) {
        int index=getHash(key);
        auto it=std::find(bucket[index].begin(),bucket[index].end(),key);
        if(it !=bucket[index].end()){
            bucket[index].erase(it);
        }
    }
    
    bool contains(int key) {
        int index=getHash(key);
        auto it=std::find(bucket[index].begin(),bucket[index].end(),key);
        return it !=bucket[index].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */