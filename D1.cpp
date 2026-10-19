#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <iostream>

using namespace std;

inline void solve() {
    int N, M;
    cin >> N >> M;
    
    for (int I = 0; I < M; ++I) {
        int L, R;
        cin >> L >> R;
    }
    
    if (N == 1) {
        cout << 0 << "\n";
    } else if (N == 2) {
        cout << 1 << "\n";
        cout << 1 << " " << 1 << "\n";
    } else {
        int K = (N + 1) / 2;
        cout << K << "\n";
        
        cout << 1 << " " << 2 << "\n";
        
        for (int I = 2; I < K; ++I) {
            int VAL = I * 2;
            cout << VAL - 2 << " " << VAL << "\n";
        }
        
        cout << K * 2 - 2 << " " << K * 2 - 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}