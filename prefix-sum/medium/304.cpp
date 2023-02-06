class NumMatrix {
    std::vector<std::vector<int>> m;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        // calculate 2d prefix sum as a segment
        m = create2dPrefixSum(matrix);
    }

    vector<vector<int>> create2dPrefixSum(vector<vector<int>>& matrix) {
        // calculates prefix sum for each row of the matrix
        for (int row = 0; row < matrix.size(); ++row) {
            for (int col = 1; col < matrix[row].size(); ++col) {
                matrix[row][col] += matrix[row][col - 1];
            }
        } 

        // calculates prefix sum for each column of the matrix
        for (int col = 0; col < matrix[0].size(); ++col) {
            for (int row = 1; row < matrix.size(); ++row) {
                matrix[row][col] += matrix[row - 1][col];
            }
        }
        return matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int extra = 0;
        int total = m[row2][col2];
        if (row1 - 1 >= 0) {
            extra += m[row1 - 1][col2];
        }
        if (col1 - 1 >= 0) {
            extra += m[row2][col1 - 1];
        }
        if (row1 - 1 >= 0 && col1 - 1 >= 0) {
            extra -= m[row1 - 1][col1 - 1];
        }
        return total - extra;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

