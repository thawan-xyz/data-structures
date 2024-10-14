#include <bits/stdc++.h>
#define array vector
#define lsb(x) ((x) & -(x))
#define endl '\n'
using namespace std;

// @author: Thawan Ribeiro, 2024-08-31
// @algorithm: Binary Indexed Tree for Competitive Programming
// @url: https://github.com/thawan-xyz

class BinaryIndexedTree {
private:
    const int length;
    array<int> tree;

    void update(int index, int value) {
        while (index <= length) {
            tree[index] += value;
            index += lsb(index);
        }
    }

    int total(int index) {
        int result = 0;
        while (index >= 1) {
            result += tree[index];
            index -= lsb(index);
        }
        return result;
    }

public:
    BinaryIndexedTree(int length, array<int>& original) : length(length + 1), tree(length + 1) {
        for (int index = 0; index < length; ++index) {
            update(index + 1, original[index]);
        }
    }

    int range(int start, int end) {
        return total(end + 1) - total(start);
    }
};

int main() {
    return 0;
}
