#include <iostream>
#include <vector>
#include <algorithm> // For std::min

const int INF = 1e9; // A large value to represent infinity for minimum queries

std::vector<int> arr; // Original array
std::vector<int> tree; // Segment tree

// Function to build the segment tree
// v: current node index in the tree
// tl: left bound of the current segment
// tr: right bound of the current segment
void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = arr[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        tree[v] = std::min(tree[2 * v], tree[2 * v + 1]);
    }
}

// Function to query for the minimum in a given range [l, r]
// v: current node index in the tree
// tl: left bound of the current segment
// tr: right bound of the current segment
// l: left bound of the query range
// r: right bound of the query range
int query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return INF; // Query range is invalid or outside current segment
    }
    if (l == tl && r == tr) {
        return tree[v]; // Current segment matches query range
    }
    int tm = (tl + tr) / 2;
    // Recursively query left and right children and take the minimum
    return std::min(query(2 * v, tl, tm, l, std::min(r, tm)),
                    query(2 * v + 1, tm + 1, tr, std.max(l, tm + 1), r));
}

// Function to update a value at a specific position pos
// v: current node index in the tree
// tl: left bound of the current segment
// tr: right bound of the current segment
// pos: position to update
// new_val: new value to set at pos
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        tree[v] = new_val; // Leaf node, update directly
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(2 * v, tl, tm, pos, new_val); // Update in left child
        } else {
            update(2 * v + 1, tm + 1, tr, pos, new_val); // Update in right child
        }
        tree[v] = std::min(tree[2 * v], tree[2 * v + 1]); // Update current node
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    arr.resize(n);
    std::cout << "Enter " << n << " elements:
";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // The segment tree will have at most 4*N nodes
    tree.resize(4 * n);
    build(1, 0, n - 1); // Build the tree starting from root (index 1)

    std::cout << "\nSegment Tree built successfully.\n";

    // Example Usage
    int q_count;
    std::cout << "Enter the number of queries: ";
    std::cin >> q_count;

    for (int i = 0; i < q_count; ++i) {
        std::cout << "\nQuery " << i + 1 << ":\n";
        std::cout << "Choose operation (1 for Range Minimum Query, 2 for Update): ";
        int type;
        std::cin >> type;

        if (type == 1) {
            int l, r;
            std::cout << "Enter query range [l, r] (0-indexed): ";
            std::cin >> l >> r;
            if (l < 0 || r >= n || l > r) {
                std::cout << "Invalid range.\n";
            } else {
                std::cout << "Minimum in range [" << l << ", " << r << "]: " << query(1, 0, n - 1, l, r) << "\n";
            }
        } else if (type == 2) {
            int pos, new_val;
            std::cout << "Enter position to update (0-indexed) and new value: ";
            std::cin >> pos >> new_val;
            if (pos < 0 || pos >= n) {
                std::cout << "Invalid position.\n";
            } else {
                arr[pos] = new_val; // Update original array
                update(1, 0, n - 1, pos, new_val); // Update segment tree
                std::cout << "Array and Segment Tree updated. New value at index " << pos << " is " << new_val << ".\n";
            }
        } else {
            std::cout << "Invalid operation type.\n";
        }
    }

    return 0;
}
