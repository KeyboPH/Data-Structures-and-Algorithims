// Anakin Amparo Data Structures and Algorithim
#include <iostream>
using namespace std;

int main() {
    float inputOne = 0;
    float inputTwo = 0;
    char inputThree;
    float output = 0.0;
    std::cout << "Enter first number to calculate: ";
    std::cin >> inputOne;
    std::cout << "Enter second number to calculate: ";
    std::cin >> inputTwo;
    std::cout << "Enter operator to use (+,-,*,/): ";
    std::cin >> inputThree;
    
    switch(inputThree) {
        case '+':
        cout <<  "Your number is: "  << inputOne + inputTwo;
        break;
        
        case '-':
        cout <<  "Your number is: "  << inputOne - inputTwo;
        break;
        
        case '*':
        cout <<  "Your number is: " << inputOne * inputTwo;
        break;
        
        case '/':
        output = inputOne / inputTwo;
        cout << "Your number is: " << inputOne / inputTwo;
        break;
        
        default:
        cout << "Error ";
        
    
        
    }


    




    return 0;
}




















