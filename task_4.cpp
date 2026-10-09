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
        if (length == 1) {
            head = newNode;
            head->next = head;
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
        if (length == 0) {
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
    
    void DeleteNode(int value) {
        if (length == 0) {
            std::cout << "Nothing to delete" << std::endl;
            return;
        }

        Node *current = head;
        Node *previous = nullptr;

        /* Search for node to delete */
        do {
            if (current->data == value) {
                break;
            }

            previous = current;
            current = current->next;
        } while (current != head);

        /* If node not found */
        if (current->data != value) {
            std::cout << "Value " << value << " not found in the list" << std::endl;
            return;
        }

        /* If the list has only one node */
        if (length == 1) {
            delete head;
            head = nullptr;
            length = 0;
            return;
        }

        if (current == head) {
            Node *tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }

            head = head->next;
            tail->next = head;
        } else {
            previous->next = current->next;
        }

        delete current;
        length--;

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

    std::cout << "Empty-list test:" << std::endl;
    list.DeleteNode(10);
    list.PrintList();
    std::cout << "Count: " << list.CountNodes() << std::endl;

    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);

    int deletions[] = {10, 30, 20};
    for (int value : deletions) {
        std::cout << "Delete " << value << ":" << std::endl;
        list.DeleteNode(value);
        list.PrintList();
        std::cout << "Count: " << list.CountNodes() << std::endl;
    }

    std::cout << "Missing-value test:" << std::endl;
    list.DeleteNode(99);
    list.PrintList();
    std::cout << "Count: " << list.CountNodes() << std::endl;

    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(20);
    list.AddNode(30);
    std::cout << "Duplicate-value test (delete 20 once):" << std::endl;
    list.DeleteNode(20);
    list.PrintList();
    std::cout << "Count: " << list.CountNodes() << std::endl;

    list.ClearList();
}
