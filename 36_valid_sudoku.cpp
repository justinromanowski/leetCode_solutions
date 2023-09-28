class Solution {

// did not work for all test cases

public:
    void printVector(vector<char>& v){
        for(int i = 0; i<v.size();i++){
            cout << v[i];
        }
        cout << endl;
    }

    bool duplicateCheck(vector<char>& v){
        if(v.size()>0){
            // sort all of the vectors
            sort(v.begin(),v.end());

            // check if k==k+1 (disclude end of vector since no next element @ the end)
            for(int k = 0; k<v.size()-1;k++){
                if(v[k]==v[k+1]){
                    cout << "DUPE FOUND" << endl;
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        //use a nested for loop to check in all 3 directions
        
        for(int i = 0; i<9; i++){
            vector<char> rowCheck;
            vector<char> colCheck;
            vector<char> boxCheck;
            for(int j = 0; j<9; j++){
                // create vector w/ all elements in row
                if(board[i][j]!='.'){
                    rowCheck.push_back(board[i][j]);
                }
                // create vector w/ all elements in col
                if(board[j][i]!='.'){
                    colCheck.push_back(board[j][i]);
                }
            }
            if(!duplicateCheck(rowCheck)){
                return false;
            }
            if(!duplicateCheck(colCheck)){
                return false;
            }
            printVector(rowCheck);
            printVector(colCheck);
            // check if valid == false to not waste CPU instructions
        }
        return true;
    }
};