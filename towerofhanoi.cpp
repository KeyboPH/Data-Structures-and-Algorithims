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
            }
        }
        void pop() {
            if (isEmpty()) {
                cout << "Stack is empty! Pop aborted." << endl;
            } else {
                top--;

            }
        }
        int peek() {
            if (isEmpty()) {
                return -1;
            } else {
                return stackArray[top];
            }

        }

};

void printLine() {
    cout << "=====================================" << endl;
}

int main()
{
    bool programRunning = true;
    bool placingStack = false;
    string inputOne;
    string inputTwo;
    string stackSelectorOne;
    string stackSelectorTwo;
    int valueSelector;
    int inputThree;

    Stack stackOne(5);
    Stack stackTwo(5);
    Stack stackThree(5);

    Stack stackGhost(5);

    stackOne.push(5);
    stackOne.push(4);
    stackOne.push(3);
    stackOne.push(2);
    stackOne.push(1);

    printLine();

    cout << "[Tower of Hanoi Game]" << endl;
    cout << "[The Goal is to transfer all elements from stack one to stack three!]" << endl;
    cout << "[There are three stacks. Stack one is initialized from 5 to 1 bottom to top. The other two are empty.]" << endl;
    cout << "[All stacks have a max capacity of 5.]" << endl;
    cout << "[You cannot transfer an element if it is greater than the top element of the stack you are trying to place it on.]" << endl;
    cout << "[Good luck!]" << endl;

    printLine();


    while (programRunning) {
        if (stackThree.isFull()) {
            cout << "You Win! Thanks for playing." << endl;
            break;
            }
        printLine();
        cout << "What would you like to do?" << endl;
        cout << "[1] Transfer an element" << endl;
        cout << "[2] Peek the stacks" << endl;
        cout << "[3] Read Rules Again" << endl;
        cout << "[4] Exit Program" << endl;
        cout << "Input: ";
        cin >> inputOne;
        printLine();

        if (inputOne == "1") {


            while (true) {

                cout << "What stack to select? ";
                cin >> stackSelectorOne;
                if (stackSelectorOne == "1") {
                    if (!stackOne.isEmpty()) {
                        valueSelector = stackOne.peek();
                        stackOne.pop();
                        break;
                    } else {
                             cout << "Whoops! Stack is empty. Try again." << endl;
                             continue;
                        }
                } else if (stackSelectorOne == "2") {
                    if (!stackTwo.isEmpty()) {
                        valueSelector = stackTwo.peek();
                        stackTwo.pop();
                        break;
                    } else {
                             cout << "Whoops! Stack is empty. Try again." << endl;
                             continue;
                        }
                } else if (stackSelectorOne == "3") {
                    if (!stackThree.isEmpty()) {
                        valueSelector = stackThree.peek();
                        stackThree.pop();
                        break;
                    } else {
                        cout << "Whoops! Stack is empty. Try again." << endl;
                        continue;
                    }
                } else {
                    cout << "Invalid Selection. Please try again." << endl;
                }


                }
            placingStack = true;

            while (true) {
                cout << "Where to place? ";
                cin >> stackSelectorTwo;

                if (stackSelectorTwo == "1") {
                    if (stackOne.isFull()) {
                        cout << "Whoops! Stack is full. Try Again." << endl;
                    } else {
                        if (stackOne.isEmpty()){
                            stackOne.push(valueSelector);
                            cout << "Element Placed!" << endl;
                            break;
                    } else {
                        if (valueSelector > stackOne.peek()) {
                            cout << "Current element too big to place! Try Again." << endl;
                            continue;
                        }
                    }
                        stackOne.push(valueSelector);
                        cout << "Element Placed!" << endl;
                        break;
                    }
                } else if (stackSelectorTwo == "2") {
                    if (stackOne.isFull()) {
                        cout << "Whoops! Stack is full. Try Again." << endl;
                    } else {
                        if (stackTwo.isEmpty()){
                            stackTwo.push(valueSelector);
                            cout << "Element Placed!" << endl;
                            break;
                    } else {
                        if (valueSelector > stackTwo.peek()) {
                            cout << "Current element too big to place! Try Again." << endl;
                            continue;
                        }
                    }
                        stackTwo.push(valueSelector);
                        cout << "Element Placed!" << endl;
                        break;
                    }
                } else if (stackSelectorTwo == "3") {
                    if (stackThree.isFull()) {
                        cout << "Whoops! Stack is full. Try Again." << endl;
                    } else {
                        if (stackThree.isEmpty()){
                            stackThree.push(valueSelector);
                            cout << "Element Placed!" << endl;
                            break;
                    } else {
                        if (valueSelector > stackThree.peek()) {
                            cout << "Current element too big to place! Try Again." << endl;
                            continue;
                        }
                    }
                        stackThree.push(valueSelector);
                        cout << "Element Placed!" << endl;
                        break;
                    }
                } else {
                    cout << "Invalid Selection. Please try again." << endl;

                }
                }

        } else if (inputOne == "2") {

            cout << "Peeking stacks:" << endl;
            cout << "Stack One Top: ";
            if (stackOne.isEmpty()) {
                cout << "Stack is empty." << endl;
            } else {
                cout << stackOne.peek() << endl;
            }

            cout << "Stack Two Top: ";
            if (stackTwo.isEmpty()) {
                cout << "Stack is empty." << endl;
            } else {
                cout << stackTwo.peek() << endl;
            }
            cout << "Stack Three Top: ";
            if (stackThree.isEmpty()) {
                cout << "Stack is empty." << endl;
            } else {
                cout << stackThree.peek() << endl;
            }


        } else if (inputOne == "3") {
            cout << "[Tower of Hanoi Game]" << endl;
            cout << "[The Goal is to transfer all elements from stack one to stack three!]" << endl;
            cout << "[There are three stacks. Stack one is initialized from 5 to 1 bottom to top. The other two are empty.]" << endl;
            cout << "[All stacks have a max capacity of 5.]" << endl;
            cout << "[You cannot transfer an element if it is greater than the top element of the stack you are trying to place it on.]" << endl;
            cout << "[Good luck!]" << endl;
        } else if (inputOne == "4") {
            cout << "Exited Program. You lose :(" << endl;
            programRunning = false;
        } else {
        cout << "Invalid Input." << endl;
        }

    }
    return 0;
}
