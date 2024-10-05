#include <vector>
#include <iostream>
using namespace std;




class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0;i<n/2;i++){
            for (int j=0;j<=(n-1)/2;j++){
                int temp = matrix[i][j];
                matrix[i][j]=matrix[n-1-j][i];
                matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
                matrix[j][n-1-i]=temp;
            }
        }
            
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    Solution sol;
    sol.rotate(matrix);
    for (const auto& row:matrix){
        for (const auto& num:row){
            cout<<num<<' ';
        }
        cout<<endl;
    }
    return 0;

}