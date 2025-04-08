#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX_SIZE = 610;
int matrix[MAX_SIZE][MAX_SIZE], indexMatrix[MAX_SIZE][MAX_SIZE], maxColumn[MAX_SIZE], dp[MAX_SIZE], result, rows, cols;

int main() {
    while (scanf("%d %d", &rows, &cols) && (rows || cols)) {
        fill(maxColumn, maxColumn + cols + 1, 1);
        for (int i = 1; i <= rows; i++) {
            scanf("%d", &matrix[i][1]);
            indexMatrix[i][1] = 1;
            for (int j = 2; j <= cols; j++) {
                scanf("%d", &matrix[i][j]);
                if (matrix[i][j] > matrix[i][j - 1]) {
                    indexMatrix[i][j] = indexMatrix[i][j - 1];
                    maxColumn[j] = max(maxColumn[j], j - indexMatrix[i][j] + 1);
                } else {
                    indexMatrix[i][j] = j;
                }
            }
        }
        result = 0;
        for (int colStart = 1; colStart <= cols; colStart++) {
            for (int colEnd = cols; colEnd >= colStart; colEnd--) {
                int width = colEnd - colStart + 1;
                if (width > maxColumn[colEnd]) {
                    continue;
                }
                if (width * rows <= result) {
                    continue;
                }
                dp[1] = (indexMatrix[1][colEnd] <= colStart) ? 1 : 0;
                result = max(dp[1] * width, result);
                for (int row = 2; row <= rows; row++) {
                    if (matrix[row][colStart] > matrix[row - 1][colEnd]) {
                        dp[row] = dp[row - 1];
                    } else {
                        dp[row] = 0;
                    }
                    if (indexMatrix[row][colEnd] <= colStart) {
                        dp[row]++;
                    } else {
                        dp[row] = 0;
                    }
                    result = max(dp[row] * width, result);
                }
            }
        }
        printf("%d\n", result);
    }
    return 0;
}