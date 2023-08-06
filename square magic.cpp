#include <iostream>
#include <vector>
using namespace std;

bool Is_it(const vector<vector<int>>& My_matrix) {
    int n = My_matrix.size();
    // Check if the My_matrix is square first
    for (int i = 0; i < n; i++) {
        if (My_matrix[i].size() != n) {
            return false;//because our function is bool
        }
    }

    // //checking our main first row/col
    int main_sum = 0;
    for (int i = 0; i < n; i++) {
        main_sum += My_matrix[0][i];
    }
    // checking our other rows
    for (int i = 0; i < n; i++) {
        int sum_rows = 0;
        for (int j = 0; j < n; j++) {
            sum_rows += My_matrix[i][j];
        }
        if (sum_rows != main_sum) {
            return false;
        }
    }

    // Check columns
    for (int i = 0; i < n; i++) {
        int sum_cols = 0;
        for (int j = 0; j < n; j++) {
            sum_cols += My_matrix[j][i];
        }
        if (sum_cols != main_sum) {
            return false;
        }
    }

    // Check the first diagonal top-left-bottom-right
    int main_diagonal = 0;
    for (int i = 0; i < n; i++) {
        main_diagonal += My_matrix[i][i];
    }
    if (main_diagonal != main_sum) {
        return false;
    }
    // Check the second diagonal bottom-left-top-right
    int second_diagonal = 0;
    for (int i = 0; i < n; i++) {
        second_diagonal += My_matrix[i][n - i - 1];
    }
    if (second_diagonal != main_sum) {
        return false;
    }
    // If all conditions are satisfied, the matrix is a magic square
    return true;
}

int main() {
    int A[50][50];
    int n;
    cout << "\nEnter the matrix Dimensions: ";
    cin >> n;
    if (n <= 0 || n > 10) {
        cout << "Invalid matrix size. Please enter a size between 1 and 10." << endl;
        return 1;
    }
    cout << "Enter elements of a matrix\n"; // entering elements of matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
cout << "Displaying elements of a matrix\n"; // seeing elements of matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<A[i][j]<<"\t";
        }
        cout<<endl;
    }
    // Create a 2-dimensional vector from the input array
    vector<vector<int>> My_matrix;
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            row.push_back(A[i][j]);
        }
        My_matrix.push_back(row);
    }

    bool result = Is_it(My_matrix);

    if (result) {
		cout<<"matrix is square magic\n";
    } else {
        cout << "Matrix is not a magic square" << endl;
    }

    return 0;
}