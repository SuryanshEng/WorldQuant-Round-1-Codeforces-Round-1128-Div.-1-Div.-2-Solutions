#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>
#include <chrono>
#include <cstdint>

using namespace std;

struct FastIO {
    static inline int read_int() {
        int x = 0;
        char c = getchar_unlocked();
        while (c < '0' || c > '9') c = getchar_unlocked();
        while (c >= '0' && c <= '9') {
            x = (x << 3) + (x << 1) + (c - '0');
            c = getchar_unlocked();
        }
        return x;
    }
    
    static inline void write_int(int x) {
        if (x == 0) {
            putchar_unlocked('0');
            putchar_unlocked('\n');
            return;
        }
        char buf[12];
        int i = 0;
        while (x > 0) {
            buf[i++] = (x % 10) + '0';
            x /= 10;
        }
        while (i > 0) putchar_unlocked(buf[--i]);
        putchar_unlocked('\n');
    }
};

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int N = FastIO::read_int();
    int M = FastIO::read_int();
    
    vector<int> l(M), r(M);
    for (int i = 0; i < m; ++i) {
        l[i] = FastIO::read_int();
        r[i] = FastIO::read_int();
    }
    
    FastIO::write_int(0); 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T = FastIO::read_int();
    while (T--) {
        solve();
    }
    return 0;
}