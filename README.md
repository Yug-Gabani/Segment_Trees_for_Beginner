# Segment Trees for Beginner

A simple, beginner-friendly C++ implementation of a **Segment Tree** — a data structure used to efficiently answer range queries (like range sum) and perform point updates on an array.

## What is a Segment Tree?

A segment tree is a binary tree where each node represents a range (segment) of the array. It lets you:

- **Query** the sum (or other aggregate) of any range `[l, r]` in `O(log n)` time.
- **Update** a single element and have the tree reflect the change in `O(log n)` time.

This is much faster than a naive approach, where a range sum query takes `O(n)` and there's no efficient way to keep results consistent after updates.

## Files

| File | Description |
|---|---|
| `Code.cpp` | A node-based segment tree implementation supporting range sum queries and point updates. |

## How It Works

The implementation in `Code.cpp` uses a `Node` class where each node stores:
- `start`, `end` — the range this node covers
- `sum` — the sum of the array elements in that range
- `left`, `right` — pointers to the child nodes

### Core Operations

1. **Build** — Recursively splits the array into halves until each node covers a single element (a leaf), then combines child sums going back up the tree.
2. **Query (Range Sum)** — Recursively checks each node for three cases:
   - **No overlap**: the node's range is completely outside `[l, r]` → return `0`
   - **Complete overlap**: the node's range is completely inside `[l, r]` → return the node's sum
   - **Partial overlap**: recurse into both children and combine the results
3. **Update** — Walks down to the leaf node matching the given index, updates its value, then recalculates the sums of all ancestor nodes on the way back up.

## Example Usage

```cpp
vector<int> arr = {3, 8, 7, 6, -2, -8, 4, 9};

SegmentTree st(arr);

cout << st.rangesum(1, 4) << endl; // 19

st.printupdate(2, 10);
cout << st.rangesum(1, 4) << endl; // 22
```

## Getting Started

### Prerequisites
A C++ compiler (e.g., `g++`) that supports C++11 or later.

### Compile and Run

```bash
g++ -o segment_tree Code.cpp
./segment_tree
```

Expected output:
```
19
22
```

## Complexity

| Operation | Time Complexity | Space Complexity |
|---|---|---|
| Build | O(n) | O(n) |
| Range Sum Query | O(log n) | O(1) extra (recursive call stack: O(log n)) |
| Update | O(log n) | O(1) extra (recursive call stack: O(log n)) |

## Why Use a Segment Tree?

Segment trees are commonly used in competitive programming and applications that need:
- Frequent range queries (sum, min, max, GCD, etc.) on an array
- Frequent updates to individual elements
- Better performance than recalculating from scratch each time

## Contributing

This project is meant as a learning resource. Feel free to fork it, experiment with other aggregate functions (min, max, product), or add support for range updates using lazy propagation.

## License

This project currently has no license specified. Feel free to reach out to the repository owner if you'd like to use this code beyond personal learning.
