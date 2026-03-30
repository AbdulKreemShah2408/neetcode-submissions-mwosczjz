class Solution {
public:
    int maxArea(vector<int>& heights) {
       int maxWater=0;
        int left=0;
        int right=heights.size()-1;
        while(left<right){
            int width=right-left;
            int height=min(heights[left],heights[right]);
            int currWater=width*height;
            maxWater= max(currWater,maxWater);
            heights[left]<heights[right] ? left++ :right--;
        }
     
       return maxWater;
       
    }
};
