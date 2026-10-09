#include <iostream>

class ArrayStack {
public:
    void Push(int value) {
        if (IsFull()) {
            std::cout << "Stack overflow: cannot push " << value << std::endl;
            return;
        }

        items[++top] = value;
    }

    void Pop() {
        if (IsEmpty()) {
            std::cout << "Stack underflow: cannot pop from an empty stack"
                      << std::endl;
            return;
        }

        std::cout << "Popped: " << items[top--] << std::endl;
    }

    void Peek() const {
        if (IsEmpty()) {
            std::cout << "Stack underflow: cannot peek at an empty stack"
                      << std::endl;
            return;
        }

        std::cout << "Top: " << items[top] << std::endl;
    }

    bool IsEmpty() const {
        return top == -1;
    }

    bool IsFull() const {
        return top == 4;
    }

    void Display() const {
        if (IsEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }

        std::cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; --i) {
            std::cout << items[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    // top is the index of the last occupied slot; -1 means empty.
    int items[5]{};
    int top = -1;
};

int main() {
    ArrayStack stack;

    for (int i = 1; i <= 5; ++i) {
        stack.Push(i * 10);
    }
    stack.Display();

    stack.Push(60);
    stack.Pop();
    stack.Peek();

    std::cout << "Emptying the stack:" << std::endl;
    while (!stack.IsEmpty()) {
        stack.Pop();
    }
    stack.Pop();
    stack.Peek();
}