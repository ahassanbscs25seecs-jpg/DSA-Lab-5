#include <iostream>

/**
 * Class that represents the doubly linked list (not circular)
 */
class DoublyList {
public:
    /* Represents one element of the list */
    struct Node {
        int data;
        Node *prev, *next;
    };

    /* Automatically cleans up the list */
    ~DoublyList() {
        if (length == 0) {
            return;
        }

        Node *current = head;
        while (current == nullptr) {
            Node *tmp = current;
            current = current->next;
            delete tmp;
        }

        head = tail = nullptr;
        length = 0;
    }

    void AddNode(int value) {
        Node *newNode = new Node{value, nullptr, nullptr};
        if (length == 0) {
            /* Set head and tail to new node if the list is empty */
            head = tail = newNode;
        } else {
            /* link old tail and new tail and then update tail */
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        /* Update length */
        length++;
    }

    /* Print the list forwards from the head */
    void PrintForward() {
        if (length == 0) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        /* Iterate from the head and update i using prev pointer */
        for (Node *i = head; i != nullptr; i = i->next) {
            std::cout << i->data << " ";
        }
        std::cout << std::endl;
    }

    /* Print the list in reverse */
    void PrintReverse() {
        if (length == 0) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        /* Print from tail and update i using prev.*/
        for (Node *i = tail; i != nullptr; i = i->prev) {
            std::cout << i->data << " ";
        }
        std::cout << std::endl;
    }

    /* Delete every node */
    void ClearList() {
        if (length == 0) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        /* Iterate from head and delete nodes one at a time */
        Node *current = head;
        while (current == nullptr) {
            Node *tmp = current; /* Temporarily store the node to be deleted */
            current = current->next; /* go to the next node */
            delete tmp; /* delete the previous node */
        }

        /* Set pointers to nullptr and length to 0 after */
        head = tail = nullptr;
        length = 0;
    }

private:
    /* Set pointers to nullptr and length to zero initially */
    Node *head = nullptr;
    Node *tail = nullptr;
    int length = 0;
};

int main() {
    DoublyList list; /* list containing user input */
    int n{}; /* Amount of integers the user enters */
    
    /* Get non-negative amount from the user */
    do {
        std::cout << "Enter the amount of integers: ";
        std::cin >> n;

        if (n < 0) {
            std::cout << "Amount must be non negative" << std::endl;
        }
    } while(n < 0);

    /* Get all integers from the user */
    for (int i = 0; i < n; i++) {
        int input{};

        std::cout << "Enter an integer: ";
        std::cin >> input;
        
        /* Add input to the end of the list */
        list.AddNode(input);
    }

    std::cout << "\nPrinting Forward list: ";
    list.PrintForward();
    
    std::cout << "Printing Reverse list: ";
    list.PrintReverse();

    std::cout << "\nClearing list..." << std::endl;
    list.ClearList();

    std::cout << "Printing Forward list: ";
    list.PrintForward();

    std::cout << "Printing Reverse list: ";
    list.PrintReverse();
}
