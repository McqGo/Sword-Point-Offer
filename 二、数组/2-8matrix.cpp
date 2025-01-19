#include <iostream>
#include <vector>
using namespace std;

void subMatrix(vector<vector<int>>& matrix, vector<vector<int>>& sub_matrix_sum){
    int len = matrix.size();
    int len_ = matrix[0].size();
    for(int i=0; i<len; i++){
        int row_sum = 0;
        for(int j=0; j<len_; j++){
            row_sum+=matrix[i][j];
            sub_matrix_sum[i+1][j+1] = sub_matrix_sum[i][j+1]+row_sum;
        }
    }
}

int sumRange(vector<vector<int>>& sub_matrix_sum, int row1, int col1, int row2, int col2){
    return sub_matrix_sum[row2+1][col2+1]
           -sub_matrix_sum[row1][col2+1]
           -sub_matrix_sum[row2+1][col1]
           +sub_matrix_sum[row1][col1];
}


int main(){
    vector<vector<int>> matrix = {{3, 0, 1, 4, 2},
                                  {5, 6, 3, 2, 1},
                                  {1, 2, 0, 1, 5},
                                  {4, 1, 0, 1, 7},
                                  {1, 0, 3, 0, 5}};
    int len = matrix.size();
    int len_ = matrix[0].size();

    //初始化，避免后面频繁分配空间
    vector<vector<int>> sub_matrix_sum(len+1, vector<int>(len_+1, 0));

    //预处理，获得sub_matrix
    subMatrix(matrix, sub_matrix_sum);
    
    //求子矩阵的和
    cout<<sumRange(sub_matrix_sum, 0, 0, 2, 1)<<endl;
    
    return 0;
}