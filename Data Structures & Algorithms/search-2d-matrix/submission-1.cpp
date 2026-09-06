class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start=0;
        int end=matrix[0].size()-1;

        while(start>=0 && start<matrix.size() && end>=0 && end<matrix[0].size()){
            cout<<matrix[start][end]<<" ";
            if(matrix[start][end]==target){
                return true;
            }
            else if(target>matrix[start][end]){
                start++;
            }
            else{
                end--;
            }
        }
        cout<<endl;
        return false;

    }
};
