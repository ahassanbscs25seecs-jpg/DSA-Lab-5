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

    void DeleteNode(int value) {
        if (length == 0) {
            std::cout << "Nothing to delete" << std::endl;
            return;
        }

        Node *iter = head;
        while (iter != nullptr && iter->data != value) {
            iter = iter->next;
        }

        if (iter == nullptr) {
            std::cout << "Couldn't find value " << value << "in the list" << std::endl;
            return;
        }

        /* Update links between nodes */
        if (iter == head && iter == tail) {
            /* If there is one element */
            /* Don't update links, just clear both pointers */
            tail = head = nullptr;
        } else if (iter == head) {
            /* If the element is the head (1st element) */
            head = head->next;
            head->prev = nullptr;
        } else if (iter == tail) {
            /* If the element is the tail */
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            /* If the element is in the middle */
            iter->next->prev = iter->prev;
            iter->prev->next = iter->next;
        }

        delete iter;
        length--;
    }

    void InsertBefore(int position, int value) {
        if (position < 1 || position > length) {
            std::cout << "Position out of range" << std::endl;
            return;
        }

        Node *newNode;
        Node *iter;

        newNode = new Node{value, nullptr, nullptr};
        length++;

        if (length == 1) {
            head = tail = newNode;
            return;
        }

        iter = head;
        
        /* Find the `position`th node */
        for (int i = 1; i < position; i++) {
            iter = iter->next;
        }

        newNode->prev = iter->prev;
        newNode->next = iter;

        if (iter == head) {
            head->prev = newNode;
            head = newNode;
        } else {
            iter->prev->next = newNode;
            iter->prev = newNode;
        }
    }

private:
    /* Set pointers to nullptr and length to zero initially */
    Node *head = nullptr;
    Node *tail = nullptr;
    int length = 0;
};

int main() {
    DoublyList list;

    // AddNode inserts at the head, so add in reverse order.
    list.AddNode(30);
    list.AddNode(20);
    list.AddNode(10);

    std::cout << "Insert 15 before position 1:" << std::endl;
    list.InsertBefore(2, 15);
    std::cout << "Forward: ";
    list.PrintForward();
    std::cout << "Reverse: ";
    list.PrintReverse();

    std::cout << "Delete 20:" << std::endl;
    list.DeleteNode(20);
    std::cout << "Forward: ";
    list.PrintForward();
    std::cout << "Reverse: ";
    list.PrintReverse();

    std::cout << "Insert 5 before the head:" << std::endl;
    list.InsertBefore(1, 5);
    std::cout << "Forward: ";
    list.PrintForward();
    std::cout << "Reverse: ";
    list.PrintReverse();

    std::cout << "Delete the head (5):" << std::endl;
    list.DeleteNode(5);
    std::cout << "Forward: ";
    list.PrintForward();
    std::cout << "Reverse: ";
    list.PrintReverse();

    std::cout << "Delete the tail (30):" << std::endl;
    list.DeleteNode(30);
    std::cout << "Forward: ";
    list.PrintForward();
    std::cout << "Reverse: ";
    list.PrintReverse();

    std::cout << "Try deleting a missing value:" << std::endl;
    list.DeleteNode(100);
    std::cout << "Forward: ";
    list.PrintForward();
    std::cout << "Reverse: ";
    list.PrintReverse();

    std::cout << "Try an invalid insertion position:" << std::endl;
    list.InsertBefore(0, 7);
    std::cout << "Forward: ";
    list.PrintForward();
    std::cout << "Reverse: ";
    list.PrintReverse();

    DoublyList onlyNode;
    onlyNode.AddNode(42);
    std::cout << "Only-node list before deletion:" << std::endl;
    std::cout << "Forward: ";
    onlyNode.PrintForward();
    std::cout << "Reverse: ";
    onlyNode.PrintReverse();

    std::cout << "Delete the only node:" << std::endl;
    onlyNode.DeleteNode(42);
    std::cout << "Forward: ";
    onlyNode.PrintForward();
    std::cout << "Reverse: ";
    onlyNode.PrintReverse();

    DoublyList emptyList;
    std::cout << "Operations on an empty list:" << std::endl;
    emptyList.InsertBefore(1, 7);
    emptyList.DeleteNode(7);
    std::cout << "Forward: ";
    emptyList.PrintForward();
    std::cout << "Reverse: ";
    emptyList.PrintReverse();
}
