class KthLargest {
     priority_queue<int,vector<int>,greater<int>>minHeap;
     int kSize;
public:
    KthLargest(int k, vector<int>& nums) {
       kSize=k;
       for(int x:nums){
        add(x);
       }

    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>kSize){
            minHeap.pop();
        }
        return minHeap.top();
    }
};
