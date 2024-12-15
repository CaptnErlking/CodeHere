#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int main() {
    map<string, int> data;
    bool cycle = false;

    cout << "Which Cycle you are in :\nPhysics --> 0\nChemistry --> 1\n\n";
    int cycleChoice;
    cin >> cycleChoice;
    if (cycleChoice != 0 && cycleChoice != 1) {
        cerr << "Invalid input. You can only enter 0 or 1 for cycle." << endl;
        return 1;
    }
    cycle = (cycleChoice == 1);

    cout << "Internal Marks for : \n";
    if (cycle) {
        cout << "\tMaths:\t\t";
        cin >> data["Maths"];
        if (data["Maths"] < 0 || data["Maths"] > 50) {
            cerr << "Invalid input for Maths. Marks should be between 0 and 50." << endl;
            return 1;
        }

        cout << "\tChemistry:\t";
        cin >> data["Chemistry"];
        if (data["Chemistry"] < 0 || data["Chemistry"] > 50) {
            cerr << "Invalid input for Chemistry. Marks should be between 0 and 50." << endl;
            return 1;
        }

        cout << "\tCAED:\t\t";
        cin >> data["CAED"];
        if (data["CAED"] < 0 || data["CAED"] > 50) {
            cerr << "Invalid input for CAED. Marks should be between 0 and 50." << endl;
            return 1;
        }

        cout << "\tPython:\t\t";
        cin >> data["Python"];
        if (data["Python"] < 0 || data["Python"] > 50) {
            cerr << "Invalid input for Python. Marks should be between 0 and 50." << endl;
            return 1;
        }
    } else {
        cout << "\tMaths:\t\t";
        cin >> data["Maths"];
        if (data["Maths"] < 0 || data["Maths"] > 50) {
            cerr << "Invalid input for Maths. Marks should be between 0 and 50." << endl;
            return 1;
        }

        cout << "\tPhysics:\t";
        cin >> data["Physics"];
        if (data["Physics"] < 0 || data["Physics"] > 50) {
            cerr << "Invalid input for Physics. Marks should be between 0 and 50." << endl;
            return 1;
        }

        cout << "\tCyber:\t\t";
        cin >> data["Cyber"];
        if (data["Cyber"] < 0 || data["Cyber"] > 50) {
            cerr << "Invalid input for Cyber. Marks should be between 0 and 50." << endl;
            return 1;
        }

        cout << "\tC:\t\t";
        cin >> data["C"];
        if (data["C"] < 0 || data["C"] > 50) {
            cerr << "Invalid input for C. Marks should be between 0 and 50." << endl;
            return 1;
        }
    }

    int esc;
    cout << "\tWhat is your ESC Subject:\n\t\tMechanical --> 1\n\t\tElectronics --> 2\n\t\tElectrical --> 3\n\t";
    cin >> esc;
    if (esc != 1 && esc != 2 && esc != 3) {
        cerr << "Invalid ESC subject. You can only enter 1, 2, or 3." << endl;
        return 1;
    }

    if (esc == 1) {
        cout << "\tMechanical:\t";
        cin >> data["Mechanical"];
        if (data["Mechanical"] < 0 || data["Mechanical"] > 50) {
            cerr << "Invalid input for Mechanical. Marks should be between 0 and 50." << endl;
            return 1;
        }
    } else if (esc == 2) {
        cout << "\tElectronics:\t";
        cin >> data["Electronics"];
        if (data["Electronics"] < 0 || data["Electronics"] > 50) {
            cerr << "Invalid input for Electronics. Marks should be between 0 and 50." << endl;
            return 1;
        }
    } else if (esc == 3) {
        cout << "\tElectrical:\t";
        cin >> data["Electrical"];
        if (data["Electrical"] < 0 || data["Electrical"] > 50) {
            cerr << "Invalid input for Electrical. Marks should be between 0 and 50." << endl;
            return 1;
        }
    }

    cout << "------------------------------------------------------\n";
    cout << "| S.No. | Subject      | CIE |  10 |  9  |  8  |  7  |\n";
    cout << "------------------------------------------------------\n";

    int count = 1;
    for (const auto& subject : data) {
        if (subject.first == "PWSE" || subject.first == "IC" || subject.first == "CE" ||
            subject.first == "SFH" || subject.first == "BK" || subject.first == "IDT") {
            continue;
        }
        int internalMarks = subject.second;
        int marksForGPA10 = max(0, 90 - internalMarks) * 2;
        int marksForGPA9 = max(0, 80 - internalMarks) * 2;
        int marksForGPA8 = max(0, 70 - internalMarks) * 2;
        int marksForGPA7 = max(0, 60 - internalMarks) * 2;

        string resultGPA10 = (marksForGPA10 > 100) ? "GG" : (marksForGPA10 < 40) ? "F" : to_string(marksForGPA10);
        string resultGPA9 = (marksForGPA9 > 100) ? "GG" : (marksForGPA9 < 40) ? "F" : to_string(marksForGPA9);
        string resultGPA8 = (marksForGPA8 > 100) ? "GG" : (marksForGPA8 < 40) ? "F" : to_string(marksForGPA8);
        string resultGPA7 = (marksForGPA7 > 100) ? "GG" : (marksForGPA7 < 40) ? "F" : to_string(marksForGPA7);

        cout << "| " << setw(5) << count << " | "
             << setw(12) << subject.first << " | "
             << setw(3) << internalMarks << " | "
             << setw(3) << resultGPA10 << " | "
             << setw(3) << resultGPA9 << " | "
             << setw(3) << resultGPA8 << " | "
             << setw(3) << resultGPA7 << " |\n";
        count++;
    }
    cout << "------------------------------------------------------\n";

    return 0;
}
