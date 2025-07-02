#include <iostream>
#include <vector>

using namespace std;

// Function to multiply two matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();    // Number of rows in A
    int m = A[0].size(); // Number of columns in A / rows in B
    int p = B[0].size(); // Number of columns in B

    vector<vector<int>> result(n, vector<int>(p, 0));

    // Matrix multiplication
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < m; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> B = {{7, 8}, {9, 10}, {11, 12}};

    vector<vector<int>> result = multiplyMatrices(A, B);

    cout << "Resultant Matrix:" << endl;
    printMatrix(result);

    return 0;
}
