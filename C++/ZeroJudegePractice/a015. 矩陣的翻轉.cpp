#include<iostream>
#include<vector>
using namespace std;
void transposeMatrix(const vector<vector<int>>&);
int main(){
    int row,column;
    while(cin>>row>>column){
        vector<vector<int>> matrix(row, vector<int>(column));
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                cin>>matrix[i][j];
            }
        }
        transposeMatrix(matrix);
    }
    return 0;
}
void transposeMatrix(const vector<vector<int>>& matrix){
    int row = matrix.size();
    int column = matrix[0].size();
    for(int j=0;j<column;j++){
        for(int i=0;i<row;i++){
            cout<<matrix[i][j];
            if(i!=row-1) cout<<" ";
        }
        cout<<endl;
    }
}