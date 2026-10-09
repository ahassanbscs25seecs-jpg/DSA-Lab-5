/**
 * Task 3 explanation in README.md
 */

#include <iostream>

class SingleCircularList {
public:
    struct Node {
        int data;
        Node *next;
    };

    void AddNode(int value) {
        Node *newNode = new Node{value, nullptr};
        length++;

        /* if the list was empty */
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node *current = head;
        /* Search for the end of the list */
        while (current->next != head) {
            current = current->next;
        }

        current->next = newNode;
        newNode->next = head;
    }

    void PrintList() {
        if (head == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        Node *current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }

    int CountNodes() {
        return length;
    }

    /* Delete all nodes in the list */
    void ClearList() {
        if (length == 0) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        Node *current = head;
        Node *nextNode;

        /* Delete all nodes one by one till we reach a node whose end is head */
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);

        head = nullptr;
        length = 0;
    }
private:
    int length = 0;
    Node *head = nullptr;
};

int main() {
    SingleCircularList list;

    std::cout << "Empty list: ";
    list.PrintList();
    std::cout << "Count: " << list.CountNodes() << std::endl;

    list.AddNode(10);
    std::cout << "One node: ";
    list.PrintList();
    std::cout << "Count: " << list.CountNodes() << std::endl;
    list.ClearList();

    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    std::cout << "Three nodes: ";
    list.PrintList();
    std::cout << "Count: " << list.CountNodes() << std::endl;

    list.ClearList();
}
