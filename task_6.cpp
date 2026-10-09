#include <iostream>
#include <limits>

class LinkedStack {
private:
    struct Node {
        int data;
        Node *next;
    };

    Node *top = nullptr;

public:
    ~LinkedStack() {
        ClearStack();
    }

    void Push(int value) {
        top = new Node{value, top};
    }

    void Pop() {
        if (IsEmpty()) {
            std::cout << "Stack underflow: cannot pop from an empty stack"
                      << std::endl;
            return;
        }

        Node *removed = top;
        std::cout << "Popped: " << removed->data << std::endl;
        top = top->next;
        delete removed;
    }

    void Peek() {
        if (IsEmpty()) {
            std::cout << "Stack underflow: cannot peek at an empty stack"
                      << std::endl;
            return;
        }

        std::cout << "Top: " << top->data << std::endl;
    }

    bool IsEmpty() {
        return top == nullptr;
    }

    void Display() {
        if (IsEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }

        std::cout << "Stack (top to bottom): ";
        for (Node *current = top; current != nullptr; current = current->next) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }

    void ClearStack() {
        while (top != nullptr) {
            Node *removed = top;
            top = top->next;
            delete removed;
        }
    }
};

int main() {
    LinkedStack stack;
    int choice;

    // A stack is LIFO; unlike Task 5's fixed array, linked nodes grow as needed.
    std::cout << "A stack is LIFO (last in, first out)." << std::endl;
    std::cout << "Task 5 has capacity 5; this linked stack grows dynamically."
              << std::endl;

    while (true) {
        std::cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n"
                  << "Choice: ";
        if (!(std::cin >> choice)) {
            if (std::cin.eof()) {
                break;
            }
            std::cout << "Invalid choice. Enter a number from 1 to 5."
                      << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: {
            int value;
            std::cout << "Value to push: ";
            if (!(std::cin >> value)) {
                if (std::cin.eof()) {
                    std::cout << std::endl;
                    break;
                }
                std::cout << "Invalid value. Enter an integer." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
                break;
            }
            stack.Push(value);
            break;
        }
        case 2:
            stack.Pop();
            break;
        case 3:
            stack.Peek();
            break;
        case 4:
            stack.Display();
            break;
        case 5:
            stack.ClearStack();
            return 0;
        default:
            std::cout << "Invalid choice. Enter a number from 1 to 5."
                      << std::endl;
        }
    }

    // ClearStack also runs in the destructor if input ends before choosing Exit.
    return 0;
}
