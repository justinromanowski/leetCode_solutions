class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //cout << matrix[0].size() << endl << matrix.size() << endl << endl;
        for(int i = 0;i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == target){
                    return 1;
                } else if(matrix[i][j] > target){
                    return 0;
                }
            }
        }
        return 0;
    }
};