#include <iostream>
using namespace std;

template <typename T>
class my_list {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t size_;

public:
    class iterator {
    private:
        Node* ptr;

    public:
        iterator() : prt(nullptr) {}
        explicit iterator(Node* p) : ptr(p) {}

        T& operator*() {
            return ptr->data;
        }

        bool operator==(const iterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const iterator& other) const {
            return prt != other.ptr;
        }

        iterator& operator++() {  // prefix
            ptr = ptr->next;
            return *this;
        }
        
        iterator operator++(int) {  // postfix
            iterator temp = *this;
            ptr = ptr->next;
            return temp;
        }

        // Decrement operators
        iterator& operator--() {  // prefix
            ptr = ptr->prev;
            return *this;
        }
        
        iterator operator--(int) {  // postfix
            iterator temp = *this;
            ptr = ptr->prev;
            return temp;
        }
        
        // Friend declaration to give my_list access to ptr
        friend class my_list;
    };

    my_list() : head(nullptr), tail(nullptr), size(0) {}

    ~my_list() {
        clear();
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        size_ = 0;
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if(!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size_++;
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size_++;
    }

    void pop_back() {
        if (!tail) return;

        if (head == tail) {
            delete tail;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        size_--;
    }

    void pop_front() {
        if (!head) return;
        
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        size_--;
    }

    T& front() {
        return head->data;
    }

    T& back() {
        return tail->data;
    }

    bool empty() const {
        return size_ == 0;
    }

    size_t size() const {
        return size_;
    }

    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator(nullptr);
    }

    void list_bubble_sort() {
        // Base case: empty list or list with just one element
        if (size_ <= 1) return;
        
        // Call the recursive helper function with the size of the list
        list_bubble_sort_recursive(size_);
    }

    private:
    // Recursive helper function for bubble sort
    void list_bubble_sort_recursive(size_t n) {
        // Base case: If we've sorted the first element, we're done
        if (n <= 1) return;
        
        // One pass of bubble sort to move the largest element to the end
        bubble_pass(n);
        
        // Recursively sort the list excluding the last element
        list_bubble_sort_recursive(n - 1);
    }

    void bubble_pass(size_t n) {
        iterator current = begin();
        iterator next;
        
        // Go through the list up to the n-th element
        for (size_t i = 0; i < n - 1; i++) {
            next = current;
            ++next;
            
            // If current element is greater than the next, swap them
            if (*current > *next) {
                // Swap the data values
                T temp = *current;
                *current = *next;
                *next = temp;
            }
            
            // Move to the next pair
            ++current;
        }
    }
};

int main() {
    my_list<int> lst;
    
    lst.push_back(5);
    lst.push_back(2);
    lst.push_back(9);
    lst.push_back(1);
    lst.push_back(5);
    
    cout << "List before sorting: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    lst.list_bubble_sort();
    
    cout << "List after sorting: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}