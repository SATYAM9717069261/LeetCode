#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinCost(const vector<int>& A) {
    int N = A.size();
    int min_cost = INT_MAX;

    for (int i = 1; i < N - 1; ++i) {
        int left_len = A[i];
        int right_len = A[i-1];
        if(left_len *2 >= N-1 && right_len*2 >= N-1){
            int cost = A[i] + A[i + 1];
            min_cost = min (min_cost,cost);
        }
    }

    if (A[0] >= N-1)
        min_cost = min(min_cost, A[0]);

    if (A[N - 1] >= N-1)
        min_cost = min(min_cost, A[N - 1]);

    return min_cost;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];

        cout << findMinCost(A) << "\n";
    }

    return 0;
}
