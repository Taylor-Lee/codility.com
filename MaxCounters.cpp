// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int max = 0;
    
    vector<int> result(N, 0);
    int apply_max = 0;
    
    for (int x : A) {
        if (1 <= x && x <= N) {
            if (result[x - 1] > apply_max) {
                ++result[x - 1];
            } else {
                result[x - 1] = apply_max + 1;
            }
            
            if (result[x -1] > max) {
                max = result[x -1];
            }
        } else if (x == N + 1) {
            apply_max = max;
        }
    }
    
    for (unsigned i = 0; i < result.size(); ++i) {
        if (result[i] < apply_max)
            result[i] = apply_max;
    }
    
    return result;
}