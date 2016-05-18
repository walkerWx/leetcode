#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {

    public:

        NumMatrix(vector<vector<int>> &matrix) {

            int row = matrix.size() + 1;
            int col = (matrix.size() == 0) ? 1 : matrix.at(0).size() + 1;
            for (int i = 0; i < row; ++i) {
                region_sum.push_back(vector<int>());
                int row_sum = 0;
                for (int j = 0; j < col; ++j) {
                    if (i == 0 || j == 0) {
                        region_sum[i].push_back(0); 
                    } else {
                        row_sum += matrix[i-1][j-1];
                        region_sum[i].push_back(region_sum[i-1][j] + row_sum); 
                    }
                } 
            } 

            for (auto line : region_sum) {
                for (auto e : line) {
                    cout << e << "\t"; 
                } 
                cout << endl;
            }
        }

        int sumRegion(int row1, int col1, int row2, int col2) {
            return region_sum[row2+1][col2+1] - region_sum[row1][col2+1] - region_sum[row2+1][col1] + region_sum[row1][col1];
        }

    private:

        vector<vector<int>> region_sum;

};

int main() {
    vector<vector<int>> matrix;
    /*
    for (int i = 0; i < 4; ++i) {
        matrix.push_back(vector<int>());
        for (int j = 0; j < 4; ++j) {
            matrix[i].push_back(1); 
        } 
    }
    */

    NumMatrix nm(matrix);
    /*
    cout << nm.sumRegion(0,0,0,0) << endl;
    cout << nm.sumRegion(0,0,3,3) << endl;
    cout << nm.sumRegion(1,0,2,2) << endl;
    cout << nm.sumRegion(1,1,2,3) << endl;
    */
}
