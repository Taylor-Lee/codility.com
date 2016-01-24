#include <iostream>
#include <string>

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <limits>

using namespace std;

int max_count = 0;

int getLongestPath(vector< vector<int> > &A, int x, int y, int max_val, int count) {
	if (x >= A.size() || y >= A[0].size())
		return count;

	if (A[x][y] > max_val) {
		++count;
		max_val = A[x][y];
		//cout << "( " << x << ", " << y << "): " << A[x][y] << "=> ";
	}

	// Move to X-axis and Y-axis
	int max_X = getLongestPath(A, x + 1, y, max_val, count);
	int max_Y = getLongestPath(A, x, y + 1, max_val, count);

	return max(max_X, max_Y);
}

int solution(vector< vector<int> > &A) {
	for (int x = 0; x < A.size(); ++x) {
		for (int y = 0; y < A[0].size(); ++y) {
			//cout << "( " << x << ", " << y << "): " << A[x][y] << "=> ";
			int longest = getLongestPath(A, x, y, A[x][y], 1);
			max_count = max(max_count, longest);
			//cout << "max: " << longest << endl;
		}
	}
	return max_count;
}

void main() {
	vector< vector<int>> A(4, vector<int>(5));
	A[0][0] = 7;    A[0][1] = -2;  A[0][2] = 0;   A[0][3] = 4;    A[0][4] = 2;
	A[1][0] = -1; A[1][1] = 0;   A[1][2] = 1;   A[1][3] = 3;    A[1][4] = 1;
	A[2][0] = 1;   A[2][1] = 2;  A[2][2] = 1;  A[2][3] = -1;  A[2][4] = 2;
	A[3][0] = 4;   A[3][1] = 0;    A[3][2] = 0;    A[3][3] = -3;   A[3][4] = 0;

	cout << solution(A);
}