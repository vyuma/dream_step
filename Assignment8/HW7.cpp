/*
Binary Tree Implementation and Search Analysis in C++

1. What is the time complexity when locating a record in a Binary Tree?
    The time complexity for searching in a binary search tree is O(h), where h is the height of the tree.
    In a balanced tree with n nodes, the height is approximately log₂(n), making the search O(log n).
    In the worst case (a completely unbalanced tree), the height could be n, making search O(n).

2. What would be the estimated number of key comparisons if the number of nodes in the tree is 100?
    For a balanced binary tree with 100 nodes, we expect approximately log₂(100) ≈ 6.64 comparisons
    on average. This means we'd expect around 7 comparisons for a typical search.

3. Compare the estimated number with x11 that you obtained from Part 1. Are these two numbers close?
    The actual average (x11) from the program runs should be close to the estimated log₂(100) if the
    tree is reasonably balanced. The results will be discussed after program execution.

4. When a tree is not balanced, i.e., a leg is much longer than the other, the worst case may occur.
    What should be done to avoid the worst cases from happening?
    To avoid worst cases, we should use self-balancing binary search trees such as:
    - AVL trees
    - Red-Black trees
    - B-trees
    - Treaps
    These data structures automatically rebalance the tree after insertions and deletions
    to maintain logarithmic height and optimal search performance.
*/

#include <iostream>
#include <vector>
#include <random>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;
    int comparisons;

    bool insertRecursively(Node* &current, int value) {
        if (current == nullptr) {
            current = new Node(value);
            return true;
        }

        if (value == current->value) {
            return false; // Duplicate value
        }

        if (value < current->value) {
            return insertRecursively(current->left, value);
        } else {
            return insertRecursively(current->right, value);
        }
    }

    bool searchRecursively(Node* current, int value) {
        if (current == nullptr) {
            return false;
        }

        comparisons++;

        if (value == current->value) {
            return true;
        }

        if (value == current->value) {
            return true;
        }

        if (value < current->value) {
            return searchRecursively(current->left, value);
        } else {
            return searchRecursively(current->right, value);
        }
    }

    void destroyTree(Node* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() : root(nullptr), comparisons(0) {}

    ~BinarySearchTree() {
        destroyTree(root);
    }

    bool insert (int value) {
        return insertRecursively(root, value);
    }

    bool search (int value) {
        comparisons = 0;
        return searchRecursively(root, value);
    }

    int getComparisons() const {
        return comparisons;
    }
};

int main() {
    // Set up random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> valueDist(1, 500);
    uniform_int_distribution<double> probDist(0.0, 1.0);

    BinarySearchTree tree;
    set<int> values;

    while (values.size() < 100) {
        int newValue = valueDist(gen);
        if (values.insert(newValue).second) {
            tree.insert(newValue);
        }
    }

    // Convert set to vector for easy random selection
    vector<int> treeValues(values.begin(), values.end());

    struct SearchResult {
        int target;
        bool found;
        int comparisons;
    };

    vector<SearchResult> results;

    for (int i = 0; i < 10; ++i) {
        int target;
        
        // ~30% chance to search for a value in the tree
        if (probDist(gen) < 0.3) {
            std::uniform_int_distribution<int> indexDist(0, treeValues.size() - 1);
            target = treeValues[indexDist(gen)];
        } else {
            // Search for a random value that might not be in the tree
            target = valueDist(gen);
        }
        
        bool found = tree.search(target);
        
        results.push_back({target, found, tree.getComparisons()});
    }

    // Display results
    cout << "Binary Tree Search Results (100 nodes, values from 1-500)" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << left << setw(5) << "#" 
                << setw(8) << "Target" 
                << setw(10) << "Result" 
                << setw(12) << "Comparisons" << endl;
    cout << "------------------------------------------------------------" << endl;
    
    int totalComparisons = 0;
    for (size_t i = 0; i < results.size(); ++i) {
        string status = results[i].found ? "Found" : "Not found";
        cout << left << setw(5) << (i + 1)
                    << setw(8) << results[i].target
                    << setw(10) << status
                    << setw(12) << results[i].comparisons << endl;
        totalComparisons += results[i].comparisons;
    }
    
    double averageComparisons = static_cast<double>(totalComparisons) / results.size();
    cout << "------------------------------------------------------------" << endl;
    cout << left << setw(5) << "Average"
                << setw(8) << ""
                << setw(10) << ""
                << setw(12) << fixed << setprecision(2) << averageComparisons << endl;
    cout << "------------------------------------------------------------" << endl;
    
    // Analysis
    cout << "\nAnalysis:" << endl;
    double expectedComparisons = 2.0 * (2.0 * log2(100) - 1) / 3;
    cout << "Theoretical expected comparisons for balanced BST with 100 nodes: ~" 
                << fixed << setprecision(2) << expectedComparisons << endl;
    cout << "Actual average comparisons from experiment: " << averageComparisons << endl;
    double difference = abs(averageComparisons - expectedComparisons);
    cout << "Difference: " << difference << endl;
    
    if (difference <= 1.5) {
        cout << "The experimental results closely match theoretical expectations." << endl;
    } else {
        cout << "The experimental results differ from theoretical expectations," << endl;
        cout << "which suggests the tree may not be optimally balanced." << endl;
    }
    
    return 0;
}