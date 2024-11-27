#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <future>

using namespace std;

class Person {
     public:
        int ticketNum = 0;
        string personName = "null";
 };

 using namespace std;
 class Queue {
 private:


  int front, rear, capacity;
  Person* queue;
  public:
  Person personOne;

  Queue(int cap) {
    front = 0;
    rear = -1;
    capacity = cap;
    queue = new Person[capacity];
  }
  ~Queue() {
    delete[] queue;
  }
  void enqueue(Person data) {
    if (isFull()) {
      cout << "Queue is full" << endl;
      return;
    } else {

      cout << data.personName << " added to the queue" << endl;
      queue[++rear] = data;
    }
  }
  ///////////
 void dequeue() {
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return;
    } else {
      // Shift elements one position to the left
      for (int i = 0; i < rear; i++) {
        queue[i] = queue[i + 1];
      }
      rear--;
    }
  }
  /////////////////
  Person peek() {
    if (isEmpty()) {
      return personOne;
    }
    return queue[front];
  }
  bool isFull() {
    return rear == capacity-1;
  }
  bool isEmpty() {
    return rear == -1;
  }
  /////////////////
   void display() {
 if (isEmpty()) {
 cout << "Queue is empty" << endl;
 return;
 }
 for (int i = front; i < rear +1; i++) {
 cout << queue[i].personName << " < ";
 }
 cout << endl;
 }
 ///////////////
 int returnSize() {
    return rear + 1;
}
void  searchName(string name) {

      for (int i = front; i < rear +1; i++) {
        if (queue[i].personName == name) {
            cout << queue[i].personName << " is currently in position #" << i + 1<< " with ticket number #" << queue[i].ticketNum << endl;
            return;
        }
 }
    cout << "No such name found." << endl;
    return;
 }

 void searchNum(int num) {
      for (int i = front; i < rear +1; i++) {
        if (queue[i].ticketNum == num) {
            cout << queue[i].personName << " is currently in position #" << i + 1<< " with ticket number #" << queue[i].ticketNum << endl;
            return;
        }
 }
    cout << "No such ticket number found." << endl;
    return;
 }

 };

    void releaseQueue (Queue a) {
    using namespace std::chrono_literals;
     std::this_thread::sleep_for(2000ms);
        if (a.isEmpty()) {
            cout << "Line is empty." << endl;
        return;


        }
    };

   void autoDequeue(Queue a) {
     using namespace std::chrono_literals;
     std::this_thread::sleep_for(2000ms);
        a.dequeue();
/*        if (a.isEmpty()) {
            cout << "Line is empty." << endl;
        return;
        }
    cout << a.peek().personName << " has recieved a ticket (Ticket #" << a.peek().ticketNum << ")" << endl;
    a.dequeue();
    if (a.isEmpty()) {
        cout << "Line is now empty." << endl;
        return;
     } else {
     cout << "Next in line: " << a.peek().personName << " with Ticket #" << a.peek().ticketNum << endl;

    return;
 }*/

};

 void printLine() {
    cout << "=================================" << endl;
 };
int main(){
    Queue concertQueue(100);
    Person personOne;
    int counter = 0;
    int what = 0;
    bool programRunning = true;
    string inputOne;
    string inputTwo;
    string nameSearch;
    int numSearch;

    using namespace std::chrono_literals;

    printLine();
    cout << "Welcome to Rodrigo's Concert Ticketing System!" << endl;

    while (programRunning) {
        printLine();
        cout << "What would you like to do? " << endl;
        cout << "[1] Enqueue a person." << endl;
        cout << "[2] Query Queue." << endl;
        cout << "[3] Process Tickets." << endl;
        cout << "[4] Process Tickets and Exit Program." << endl;
        cout << "Input: ";
        cin >> inputOne;
        printLine();


        if (inputOne == "1") {
            cout << "Enter the name: ";
            cin >> personOne.personName;
            printLine();
            counter++;
            personOne.ticketNum = counter;
            concertQueue.enqueue(personOne);
            cout << personOne.personName << " has been added to the queue with ticket #" << personOne.ticketNum << endl;
            cout << "Queue Size: " << concertQueue.returnSize() << endl;

        } else if (inputOne == "2") {
            cout << "Query by..." << endl;
            cout << "[1] Name" << endl;
            cout << "[2] Ticket Number" << endl;
            cout << "[3] Cancel" << endl;
            cout << "Input: ";
            cin >> inputTwo;
                    printLine();
            if (inputTwo == "1") {
                cout << "Name to search... ";
            cin >> nameSearch;
            concertQueue.searchName(nameSearch);

            } else if (inputTwo == "2") {
                cout << "Ticket number to search... ";
            cin >> numSearch;
            concertQueue.searchNum(numSearch);

            } else if (inputTwo == "3") {

            } else {
                cout << "Invalid Input." << endl;
            }


        } else if (inputOne == "3") {
            what = concertQueue.returnSize();
            if (concertQueue.isEmpty()) {
                cout << "Line is empty." << endl;
                continue;
                }
            for (int i = 0; i < what; i++) {

                std::this_thread::sleep_for(60000ms);

                cout << concertQueue.peek().personName << " has recieved a ticket (Ticket #" << concertQueue.peek().ticketNum << ")" << endl;
                concertQueue.dequeue();
                if (concertQueue.isEmpty()) {
                    cout << "Line is now empty." << endl;
                } else {
                cout << "Next in line: " << concertQueue.peek().personName << " with Ticket #" << concertQueue.peek().ticketNum << endl;
                cout << "Queue Size: " << concertQueue.returnSize() << endl;
                printLine();
 }
            }
        } else if (inputOne == "4") {
            cout << "Thank you for using Rodrigo's Concert Ticketing System!" << endl;
            break;
        } else {
            cout << "Invalid input." << endl;
        }
    }
    printLine();
    return 0;
}
