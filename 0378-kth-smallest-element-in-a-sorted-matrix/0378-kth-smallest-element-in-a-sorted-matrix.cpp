class Solution {
public:
int f(vector<vector<int>>& matrix, int m){
    int n=matrix.size();
    int r=n-1;
    int c=0;
    int count=0;
    while(r>=0 and c<n){
        if(matrix[r][c]<=m){
            count+=r+1;
            c++;
        }
        else r--;
    }
            return count;

}
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l=matrix[0][0];
        int n= matrix.size();
        int h=matrix[n-1][n-1];
        while(l<h){
            int m=l+(h-l)/2;
            if(f(matrix,m)<k){
                l=m+1;
            }
            else
            {
                h=m;
            }
        }
        return l;
    }
};