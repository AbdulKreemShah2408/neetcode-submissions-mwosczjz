class Solution {
public:
   priority_queue<int,vector<int>,greater<int>>minHeap;
    int findKthLargest(vector<int>& nums, int k) {
       for(int n:nums){
        minHeap.push(n);
        if(minHeap.size()>k){
            minHeap.pop();
        }
       }
       return minHeap.top();
    }
};
