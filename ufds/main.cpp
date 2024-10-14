#include <bits/stdc++.h>
#define array vector
using namespace std;

// @author: Thawan Ribeiro, 2024-06-26
// @algorithm: UFDS for Competitive Programming
// @url: https://github.com/thawan-xyz

class UFDS {
private:
    int sets;
    array<int> leader, rank, size;

public:
    UFDS(const int N) : sets(N), leader(N), rank(N, 0), size(N, 1) {
        for (int i = 0; i < N; ++i) leader[i] = i;
    }

    int find_set(int x) {
        if (leader[x] != x) leader[x] = find_set(leader[x]);

        return leader[x];
    }

    int size_set(int x) {
        return size[find_set(x)];
    }

    bool is_same_set(int x, int y) {
        return find_set(x) == find_set(y);
    }

    void unite_sets(int x, int y) {
        if(is_same_set(x, y)) return;

        int a = find_set(x); int b = find_set(y);
        if (rank[a] < rank[b]) swap(a, b); leader[b] = a;

        if (rank[a] == rank[b]) rank[a]++;
        size[a] += size[b];

        sets--;
    }

    int num_sets() const {
        return sets;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cerr << "Thawan";
    return 0;
}
