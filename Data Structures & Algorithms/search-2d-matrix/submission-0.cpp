class Solution {
public:
bool search(vector<vector<int>>& mat, int target,int row){
int n=mat[0].size();
int start=0, end=n-1;
while(start<=end){
    int mid=start+(end-start)/2;
     if(target==mat[row][mid]){
        return true;
     }
     else if(target>=mat[row][mid]){
        start=mid+1;
     }
     else{
        end=mid-1;
     }

}
return false;
}
    bool searchMatrix(vector<vector<int>>& mat, int target) {
      int m=mat.size(), n=mat[0].size();
      int start=0, end=m-1;
      while(start<=end){
        int midRow=start+(end-start)/2;
        if(target>=mat[midRow][0] && target <=mat[midRow][n-1]){
          return search(mat,target,midRow);
        }
        else if(target>=mat[midRow][n-1]){
            start=midRow+1;
        }
        else{
            end=midRow-1;
        }
      }
      
      return false;
    }
};
