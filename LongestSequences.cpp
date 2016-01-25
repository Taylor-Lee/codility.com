#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

int getLongestPath(int x, int y, int max_val, vector< vector<int> > &A, vector< vector<int> > &max_matrix) {
	if (x >= A.size() || y >= A[0].size())
		return 0;

	if (A[x][y] < max_val)
		return 0;

	max_val = A[x][y];

	int &max_length = max_matrix[x][y];
	if (max_length != INT_MIN)
		return max_length;

	// Move to X-axis and Y-axis
	int max_X = getLongestPath(x + 1, y, max_val, A, max_matrix);
	int max_Y = getLongestPath(x, y + 1, max_val, A, max_matrix);
	max_length = max(max_X, max_Y);

	return 1 + max_length;
}

int solution(vector< vector<int> > &A) {
	// Make cache matrix for dynamic programming
	vector< vector<int>> max_matrix(A.size(), vector<int>(A[0].size(), INT_MIN));
	int max_longest = 0;

	for (int x = 0; x < A.size(); ++x) {
		for (int y = 0; y < A[0].size(); ++y) {
			int longest = getLongestPath(x, y, A[x][y], A, max_matrix);
			max_longest = max(max_longest, longest);
		}
	}

	return max_longest;
}

void main() {
	vector< vector<int>> A(4, vector<int>(5));
	A[0][0] = 7;    A[0][1] = -2;  A[0][2] = 0;   A[0][3] = 4;    A[0][4] = 2;
	A[1][0] = -1; A[1][1] = 0;   A[1][2] = 1;   A[1][3] = 3;    A[1][4] = 1;
	A[2][0] = 1;   A[2][1] = 2;  A[2][2] = 1;  A[2][3] = -1;  A[2][4] = 2;
	A[3][0] = 4;   A[3][1] = 0;    A[3][2] = 0;    A[3][3] = -3;   A[3][4] = 0;

	cout << solution(A);
}