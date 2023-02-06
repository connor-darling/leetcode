class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        std::vector<std::vector<int>> answer = mat;
        // calculate 2d prefix sum

        // calculate prefix sum for each row
        for (int row = 0; row < mat.size(); ++row) {
            for (int col = 1; col < mat[row].size(); ++col) {
                mat[row][col] +=  mat[row][col - 1];
            }
        }

        // calculate prefix sum for each column
        for (int col = 0; col < mat[col].size(); ++col) {
            for (int row = 1; row < mat.size(); ++row) {
                mat[row][col] += mat[row - 1][col];
            }
        }

        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[i].size(); ++j) {
                int r1 = i - k;
                int r2 = i + k;
                int c1 = j - k;
                int c2 = j + k;

                if (r1 < 0) r1 = 0;
                if (r2 >= mat.size()) r2 = mat.size() - 1;
                if (c1 < 0) c1 = 0;
                if (c2 >= mat[i].size()) c2 = mat[i].size() - 1;

                answer[i][j] = sumRegion(r1, r2, c1, c2, mat);
            }
        }

        return answer;
    }

    int sumRegion(int r1, int r2, int c1, int c2, std::vector<std::vector<int>> &m) {
        int extra = 0;
        int total = m[r2][c2];
        if (r1 - 1 >= 0) extra += m[r1 - 1][c2];
        if (c1 - 1 >= 0) extra += m[r2][c1 - 1];
        if (r1 - 1 >= 0 && c1 - 1 >= 0) extra -=  m[r1 - 1][c1 - 1];
        return total - extra;
    }
};
