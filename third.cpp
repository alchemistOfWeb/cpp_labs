#include <iostream>
#include <cstdlib> // for rand(), srand()
#include <ctime> // time()
#include <string>

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int rows, cols;
    std::cin >> rows >> cols;

    int matrix[rows][cols];

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            matrix[i][j] = rand() % 2 - 1;
            std::cout << matrix[i][j] << '\t';
        }
        std::cout << std::endl;
    }

    // get sum of rows elements where is at least one negative number.
    int row_sums[rows];
    bool have_negative[rows];

    for (int i=0; i<rows; i++) {
        have_negative[i] = false;
        for (int j=0; j<cols; j++) {
            if (matrix[i][j] < 0) {
                have_negative[i] = true;
                break;
            }
        }

        if (!have_negative[i]) {
            continue;
        }

        int row_sum = 0;

        for (int j=0; j<cols; j++) {
            row_sum += matrix[i][j];
        }

        row_sums[i] = row_sum;
    }

    std::cout << "sums of rows:\n";

    for (int i=0; i<rows; i++) {
        std::string res = 
            have_negative[i] ? std::to_string(row_sums[i]) : "there is no negative numbers";
        std::cout << "row " << i << ":\t" << res << std::endl;
    }

    // get coordinates of saddle points.
    int maxs_in_cols[cols], mins_in_rows[rows];
    for (int i=0; i<cols; i++) maxs_in_cols[i] = matrix[0][i];
    for (int i=0; i<rows; i++) mins_in_rows[i] = matrix[i][0];

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (matrix[i][j] > maxs_in_cols[j]) maxs_in_cols[j] = matrix[i][j]; // = i
            if (matrix[i][j] < mins_in_rows[i]) mins_in_rows[i] = matrix[i][j]; // = j
        }
    }

    int sad_pnt_i = 0;
    std::cout << "saddle points:\n";

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if ((matrix[i][j] == maxs_in_cols[j]) && (matrix[i][j] == mins_in_rows[i])) {
                sad_pnt_i++;
                std::cout << "saddle point " << sad_pnt_i << " has coordinates:\trow=" << i << " and col=" << j << std::endl;
            }
        }
    }
} 
