#include <iostream>
#include <vector>

using namespace std;

/*
 * Time complexity O(rows + cols)
 * Space complexity O(1)
 */
bool find_element(vector< vector<int>> matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int start_row = 0;
    int start_col = cols - 1;

    while (start_row < rows && start_col >= 0) {
        if (target == matrix[start_row][start_col])
            return true;
        else if (target < matrix[start_row][start_col])
            start_col--;
        else
            start_row++;
    }

    return false;
}

int main(){
    int target;
    int rows, cols;

    cin >> target >> rows >> cols;

    vector< vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];


    bool element_found = find_element(matrix, target);

    if (element_found)
        cout << "1";
    else
        cout << "0";
    cout << endl;

    return 0;
}
