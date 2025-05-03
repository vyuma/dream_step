/* 
Discussion for Linked List Reversal:

(1) Pseudocode for Reversing Linked List:
    function reverseList(head):
        // Case 1: 0 nodes (empty list)
        if head is NULL:
            return NULL

        // Case 2: 1 node
        if head->next is NULL:
            return head

        // Case 3: 2 nodes
        if head->next->next is NULL:
            second = head->next
            second->next = head
            head->next = NULL
            return second

        // Case 4: 3 or more nodes
        previous = NULL
        current = head
        while current is not NULL:
            next = current->next
            current->next = previous
            previous = current
            current = next
        
        return previous

(2) C++ Implementation is shown in the code below.

(3) Test Cases in main() will demonstrate handling of:
    - Empty list
    - Single node list
    - Two-node list 
    - Multi-node list

(4) Case Combination Strategy:
    - The algorithm uses a uniform approach that works for all list lengths
    - Key strategy is to maintain three pointers: previous, current, and next
    - This allows in-place reversal without additional data movement
    - Handles edge cases (0, 1, 2 nodes) with minimal additional logic

(5) Final Work Method:
    Node* reverseList(Node* head) {
        Node* previous = NULL;
        Node* current = head;
        
        while (current != NULL) {
            Node* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        
        return previous;
    }
*/

// Node structure for the Linked List
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to reverse the linked list
Node* reverseList(Node* head) {
    // Handle 0 nodes (empty list)
    if (head == NULL) {
        return NULL;
    }

    // Handle 1 node
    if (head->next == NULL) {
        return head;
    }

    // Handle 2 nodes
    if (head->next->next == NULL) {
        Node* second = head->next;
        second->next = head;
        head->next = NULL;
        return second;
    }

    // Handle 3 or more nodes
    Node* previous = NULL;
    Node* current = head;

    while (current != NULL) {
        Node* next = current->next; // Store next node
        current->next = previous;    // Reverse the link
        previous = current;          // Move previous to current
        current = next;              // Move to next node
    }

    return previous
}

// Helper function to print the list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "@" << endl;
}

// Helper function to create a list from an array
Node* createList(int arr[], int size) {
    if (size == 0) return NULL;

    Node* head = new Node(arr[0]);
    Node* current = head;

    for (int i = 1; i < size; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

int main() {
    // Test Case 1: Empty List
    cout << "Empty List Test:" << endl;
    Node* emptyList = NULL;
    cout << "Before: ";
    printList(emptyList);
    emptyList = reverseList(emptyList);
    cout << "After:  ";
    printList(emptyList);
    cout << endl;

    // Test Case 2: Single Node List
    cout << "Single Node List Test:" << endl;
    int singleArr[] = {42};
    Node* singleList = createList(singleArr, 1);
    cout << "Before: ";
    printList(singleList);
    singleList = reverseList(singleList);
    cout << "After:  ";
    printList(singleList);
    cout << endl;

    // Test Case 3: Two Node List
    cout << "Two Node List Test:" << endl;
    int twoNodeArr[] = {1, 2};
    Node* twoNodeList = createList(twoNodeArr, 2);
    cout << "Before: ";
    printList(twoNodeList);
    twoNodeList = reverseList(twoNodeList);
    cout << "After:  ";
    printList(twoNodeList);
    cout << endl;

    // Test Case 4: Multi-Node List
    cout << "Multi-Node List Test:" << endl;
    int multiNodeArr[] = {1, 2, 3, 4, 5, 6};
    Node* multiNodeList = createList(multiNodeArr, 6);
    cout << "Before: ";
    printList(multiNodeList);
    multiNodeList = reverseList(multiNodeList);
    cout << "After:  ";
    printList(multiNodeList);

    return 0;
}