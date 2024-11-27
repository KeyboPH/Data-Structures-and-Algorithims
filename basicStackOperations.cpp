#include <iostream>
#include <string>
#include <stack>


using namespace std;
class Stack {
    private:
        int top;
        int maxSize;
        int* stackArray;

    public:
        Stack(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1;
        }

        ~Stack() {
        delete[] stackArray;

        }

        bool isEmpty() {
            return (top == -1);

        }
        bool isFull() {
            return (top == maxSize - 1);
        }
        void push(int value) {
            if (isFull()) {
                cout << "Stack is full! Push aborted." << endl;
            } else {
                stackArray[++top] = value;
                cout << "Push successful." << endl;
            }
        }
        void pop() {
            if (isEmpty()) {
                cout << "Stack is empty! Pop aborted." << endl;
            } else {
                cout << "Pop successful." << endl;
                top--;

            }


        }
        int peek() {
            if (isEmpty()) {
                cout << "Stack is empty, nothing to peek." << endl;
                return -1;
            } else {
                return stackArray[top];
            }

        }

};


int main()
{
    bool programRunning = true;
    string inputOne;
    int inputTwo;
    Stack stack(5);



    while (programRunning) {
        cout << "What would you like to do?" << endl;
        cout << "[1] Push unto the stack" << endl;
        cout << "[2] Pop the stack" << endl;
        cout << "[3] Peek the stack" << endl;
        cout << "[4] Check if stack is full" << endl;
        cout << "[5] Check if stack is empty" << endl;
        cout << "[6] Exit Program" << endl;
        cout << "Input: ";
        cin >> inputOne;

        if (inputOne == "1") {
            cout << "Input to push: ";
            cin >> inputTwo;
            stack.push(inputTwo);
            cout << "Pushed unto stack." << endl;

        } else if (inputOne == "2") {
            stack.pop();
            cout << "Stack popped." << endl;

        } else if (inputOne == "3") {
            cout << "The top of the stack is " << stack.peek() << endl;
        } else if (inputOne == "4") {
            if (stack.isFull() == 1) {
                cout << "The stack is full!" << endl;
            } else {
            cout << "The stack is not full." << endl;
            }

        } else if (inputOne == "5") {
            if (stack.isEmpty() == 1) {
                cout << "The stack is empty!" << endl;
            } else {
            cout << "The stack is not empty." << endl;
            }


        } else if (inputOne == "6") {
            cout << "Exited Program." << endl;
            programRunning = false;
        } else {
        cout << "Invalid Input." << endl;
        }




    }
    return 0;
}





















