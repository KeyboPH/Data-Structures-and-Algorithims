#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct jeepRoute {
    string id = "0";
    string name = "Default Name";
    float distance = 0.0;
    float priceRegular = 0.0;
    float priceDiscount = 0.0;
    vector <string> landmarks = {"Default Landmark A", "Default Landmark B"};
    string operatingHours = "XX:XX = XX:XX";
    float time = 0.0;
    int operatingJeeps = 0;
};
void printLine() {
    cout << "==============================" << endl;
};

int main()
{
    bool programRunning = true;
    string userInputOne;
    string userInputTwo;
    string userInputThree;
    string nameHolder = " ";
    bool foundRoute = false;
    int counter = 0;
    jeepRoute routeTest = {"2", "Default Name", 0.0,0.0,0.0,{"Landmark A"}, "XX:XX - XX:XX", 0,0};
    jeepRoute routeDefault = {"0", "Default Name", 0.0,0.0,0.0,{"Landmark A"}, "XX:XX - XX:XX", 0,0};
    jeepRoute routeOne = {"1","Lucena City Proper - Site", 5.0, 13.00, 11.00, {"Enverga University", "SM City Lucena", "Dumaca River", "STI College", "New Lucena City Public Market"}, "5:30 AM - 9:00 PM", 25.00, 27};
    vector <jeepRoute> database = {};
    vector <jeepRoute> databaseTransfer = {routeOne};




    cout << "Jeepney Route Database." << endl;
    while (programRunning) {
        printLine();
        cout << "What would you like to do?" << endl;
        cout << "[1] Create a new jeepney route" << endl;
        cout << "[2] Read an existing jeepney route" << endl;
        cout << "[3] Update an existing jeepney route" << endl;
        cout << "[4] Delete the database" << endl;
        cout << "[5] Stop Program" << endl;
        printLine();
        cout << "Input: ";
        cin >> userInputOne;
        if (userInputOne == "1") {
            printLine();
            cout << "Creating Jeepney Route." << endl;
            database.push_back(routeDefault);
            cout << "Enter ID No. : ";
            cin >> database.back().id;
            cout << "Enter Full Route Name: ";
            cin >> database.back().name;
            cout << "Enter Route Length in km: ";
            cin >> database.back().distance;
            cout << "Enter Regular Fare: ";
            cin >> database.back().priceRegular;
            cout << "Enter Discounted Fare: ";
            cin >> database.back().priceDiscount;
            cout << "Enter Landmarks. Enter \"0\" to finish landmark input." << endl;
            while (true) {
                cout << "Input: ";
                if (userInputThree == "0") {
                    counter = 0;
                    database.back().landmarks.pop_back();
                    database.back().landmarks.pop_back();
                    break;
                }
                database.back().landmarks.push_back("x");
                cin >> userInputThree;
                database.back().landmarks[counter] = userInputThree;
                counter++;
            }
            cout << "Enter Operating Hours. Format as \"XX:XX PM - XX:XX PM\".: ";
            cin >> database.back().operatingHours;
            cout << "Enter Route Time (in minutes): ";
            cin >> database.back().time;
            cout << "Enter number of operating Jeeps: ";
            cin >> database.back().operatingJeeps;

            cout << "Jeepney Route Created!" << endl;

        }
        else if (userInputOne == "2") {
            printLine();
            cout << "Reading Jeepney Route. " << endl;
            cout << "Enter the ID of the Jeepney Route to Read: ";
            cin >> userInputTwo;
            printLine();
            for (int i = 0; i < database.size(); i++) {
                if (userInputTwo == database[i].id) {
                    foundRoute = true;
                    cout << "Route Name: " << database[i].name << endl;
                    cout << "ID No. : " << database[i].id << endl;
                    cout << "Route Length: " << database[i].distance << " km" << endl;
                    cout << "Regular Fare: " << database[i].priceRegular << " PHP" << endl;
                    cout << "Discounted Fare: " << database[i].priceDiscount << " PHP" << endl;
                    cout << "Landmarks: ";
                    for (int x = 0; x < database[i].landmarks.size(); x++) {
                        cout << database[i].landmarks[x] << ", ";
                    }
                    cout << "\nOperating Hours: " << database[i].operatingHours << endl;
                    cout << "Route Time: " << database[i].time << " minutes" << endl;
                    cout << "No. of Operating Jeeps: " << database[i].operatingJeeps << endl;


                }

            }
            if (foundRoute != true) {
                cout << "No Route with that ID was found." << endl;
            }
            foundRoute = false;
            userInputTwo = "";

        }
        else if (userInputOne == "3") {
            printLine();
            cout << "Updating a Route." << endl;
            cout << "Enter the ID of the Route you want to update: ";
            cin >> userInputTwo;
            printLine();
            for (int i = 0; i < database.size(); i++) {
                if (userInputTwo == database[i].id) {
                    cout << "Enter ID No. : ";
                    cin >> database[i].id;
                    cout << "Enter Full Route Name: ";
                    cin >> database[i].name;
                    cout << "Enter Route Length in km: ";
                    cin >> database[i].distance;
                    cout << "Enter Regular Fare: ";
                    cin >> database[i].priceRegular;
                    cout << "Enter Discounted Fare: ";
                    cin >> database[i].priceDiscount;
                    cout << "Enter Landmarks. Enter \"0\" to finish landmark input." << endl;
                    database[i].landmarks.clear();
                    while (true) {
                        cout << "Input: ";
                        if (userInputThree == "0") {
                            counter = 0;
                            break;
                        }
                        database[i].landmarks.push_back("x");
                        cin >> userInputThree;
                        database[i].landmarks[counter] = userInputThree;
                        counter++;
                    }

                    cout << "Enter Operating Hours. Format as \"XX:XX PM - XX:XX PM\".";
                    cin >> database[i].operatingHours;
                    cout << "Enter Route Time (in minutes): ";
                    cin >> database[i].time;
                    cout << "Enter number of operating Jeeps: ";
                    cin >> database[i].operatingJeeps;



                    }
                else {

                }

                }
            cout << "No route with that ID was found." << endl;




        }
        else if (userInputOne == "4") {
            printLine();
            cout << "Warning! You are about to reset the database. Are you sure? y/n: ";
            cin >> userInputTwo;
            if (userInputTwo == "y" | userInputTwo == "Y") {
                database.clear();
                cout << "Deleted Database." << endl;
            } else if (userInputTwo == "n" | userInputTwo == "N") {
                cout << "Operation Aborted.";
            } else {
                cout << "Invalid Input. Aborting Deletion..." << endl;
            }
            /*cout << "Enter the ID of the Route you want to delete: ";
            cin >> userInputTwo;
            for (int i = 0; i < database.size(); i++) {
                if (userInputTwo == database[i].id) {
                    /*for (int x = 0; x < database.size(); i++) {
                        if (database[x].id != userInputTwo) {
                            databaseTransfer[x] = database[x];
                        }
                    }

                    database.clear();
                    for (int y = 0; y < databaseTransfer.size(); y++) {
                        database.push_back(databaseTransfer[y]);
                    }
                    cout << "Route Deleted! " << endl;
                    databaseTransfer.clear()
                    database.clear();

                    break;
                }

            }*/


        }
        else if (userInputOne == "5") {
            printLine();
            cout << "Shutting Down." << endl;
            programRunning = false;
        }
        else {
            cout << "Invalid Input. Please try again." << endl;
        }

    }
    return 0;
}
















