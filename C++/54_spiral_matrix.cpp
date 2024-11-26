/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = 0, column = 0;
        int column_size = matrix[0].size();
        int row_size = matrix.size();
        int number_of_elements = 0;

        vector<int> output(column_size * row_size, 0);

        int boundary_left = -1, boundary_right = column_size;
        int boundary_up = 0, boundary_down = row_size;

        string direction = "right";


        while (number_of_elements < column_size * row_size) {
            //cout << "number_of_elements = " << number_of_elements << endl;
            //cout << "row = " << row << endl;
            //cout << "column = " << column << endl;
            //cout << "direction = " << direction << endl;
            output[number_of_elements++] = matrix[row][column];
            if (direction == "right") {
                ++column;
                if (column == boundary_right) {
                    --boundary_right;
                    --column;
                    ++row;
                    direction = "down";
                }
            }
            else if (direction == "left") {
                --column;
                if (column == boundary_left) {
                    ++boundary_left;
                    ++column;
                    --row;
                    direction = "up";
                }
            }
            else if (direction == "up") {
                --row;
                if (row == boundary_up) {
                    ++boundary_up;
                    ++row;
                    ++column;
                    direction = "right";
                }
            }
            else if (direction == "down") {
                ++row;
                if (row == boundary_down) {
                    --boundary_down;
                    --row;
                    --column;
                    direction = "left";
                }
            }
        }
        return output;
    }
};