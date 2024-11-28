#include <iostream>



using namespace std;



int main () {

  int examOne;

  int examTwo;

  int examThree;

  int examAdd;

  int examAve;

  bool result;



  cout << "Input Exam One: ";

  cin >> examOne;



  cout << "Input Exam Two: ";

  cin >> examTwo;



  cout << "Input Exam Three: ";

  cin >> examThree;



  examAdd = examOne + examTwo + examThree;



  examAve = examAdd/3;

  cout << "Average Score: " << examAve << "\n";



  if (examAve>70) {

      cout << "Passed!" << "\n";

  } else {

      cout << "Failed.";

  }



  return 0;

}
