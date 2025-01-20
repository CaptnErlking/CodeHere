#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

string calculateGrade(int score) {
    if (score >= 90) return "O";
    if (score >= 80) return "A+";
    if (score >= 70) return "A";
    if (score >= 60) return "B+";
    if (score >= 50) return "B";
    if (score >= 40) return "P";
    return "F";
}

struct Subject {
    string name;
    int credit;
    int marks; 
    string reqMarks[4]; 
};

void calculateRequiredMarks(Subject &subj) {
    int thresholds[4] = {90, 80, 70, 60};

    for (int i = 0; i < 4; ++i) {
        int required = 2 * max(0, thresholds[i] - subj.marks);
        if (required > 100)
            subj.reqMarks[i] = "GG";
        else if (required < 40)
            subj.reqMarks[i] = "F";
        else
            subj.reqMarks[i] = to_string(required);
    }
}

int main() {
    int numSubjects;
    vector<Subject> subjects;

    int choice;
    cout << "Do you want custom subjects or Semester 3 subjects? (1 or 2): ";
    cin >> choice;

    if (choice == 2) {
        numSubjects = 8;
        vector<string> subjectNames = {"Maths", "JAVA", "OS", "DSC", "DDCO", "SCR", "DVP", "DSL"};
        vector<int> credits = {4, 3, 4, 3, 4, 1, 1, 1};
        
        for (int i = 0; i < numSubjects; ++i) {
            Subject subj;
            subj.name = subjectNames[i];
            subj.credit = credits[i];

            cout << "Enter CIE marks for " << subj.name << " (0-50): ";
            cin >> subj.marks;
            if (subj.marks < 0 || subj.marks > 50) {
                cerr << "Invalid input for " << subj.name << ". Marks should be between 0 and 50." << endl;
                return 1;
            }

            if (subj.credit == 3 || subj.credit == 4) {
                calculateRequiredMarks(subj);
            }

            subjects.push_back(subj);
        }
    }
    else if (choice == 1) {
        cout << "Enter the number of subjects: ";
        cin >> numSubjects;

        if (numSubjects <= 0) {
            cerr << "Invalid input. Number of subjects must be greater than 0." << endl;
            return 1;
        }

        for (int i = 0; i < numSubjects; ++i) {
            Subject subj;
            cout << "Enter the name of subject " << i + 1 << ": ";
            cin >> subj.name;
            cout << "Enter credits for " << subj.name << ": ";
            cin >> subj.credit;
            if (subj.credit <= 0) {
                cerr << "Invalid input. Credits must be greater than 0." << endl;
                return 1;
            }
            cout << "Enter CIE marks for " << subj.name << " (0-50): ";
            cin >> subj.marks;
            if (subj.marks < 0 || subj.marks > 50) {
                cerr << "Invalid input for " << subj.name << ". Marks should be between 0 and 50." << endl;
                return 1;
            }

            if (subj.credit == 3 || subj.credit == 4) {
                calculateRequiredMarks(subj);
            }

            subjects.push_back(subj);
        }
    }
    else {
        cerr << "Invalid choice. Please enter 'custom' or 'semester3'." << endl;
        return 1;
    }

    cout << "----------------------------------------------------------------------------\n";
    cout << "| S.No. | Subject      | Credits | CIE |  Req Marks (10) | (9) | (8) | (7) |\n";
    cout << "----------------------------------------------------------------------------\n";

    for (int i = 0; i < numSubjects; ++i) {
        Subject &subj = subjects[i];
        if (subj.credit == 3 || subj.credit == 4) {
            cout << "| " << setw(5) << i + 1 << " | "
                 << setw(12) << subj.name << " | "
                 << setw(7) << subj.credit << " | "
                 << setw(3) << subj.marks << " | "
                 << setw(15) << subj.reqMarks[0] << " | "
                 << setw(3) << subj.reqMarks[1] << " | "
                 << setw(3) << subj.reqMarks[2] << " | "
                 << setw(3) << subj.reqMarks[3] << " |\n";
        } else {
            cout << "| " << setw(5) << i + 1 << " | "
                 << setw(12) << subj.name << " | "
                 << setw(7) << subj.credit << " | "
                 << setw(3) << subj.marks << " | "
                 << setw(33) << "No semester-end exam" << " |\n";
        }
    }
    cout << "----------------------------------------------------------------------------\n";

    double totalGradePoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < numSubjects; ++i) {
        Subject &subj = subjects[i];
        if (subj.credit == 3 || subj.credit == 4) {
            int plannedScore;
            cout << "Enter your planned score for " << subj.name << " (out of 100): ";
            cin >> plannedScore;
            if (plannedScore < 0 || plannedScore > 100) {
                cerr << "Invalid score. It should be between 0 and 100." << endl;
                return 1;
            }
            int totalMarks = subj.marks + plannedScore / 2;
            string grade = calculateGrade(totalMarks);
            cout << subj.name << ": Total = " << totalMarks << ", Grade = " << grade << endl;

            int gradePoint = (grade == "O") ? 10 : (grade == "A+") ? 9 : (grade == "A") ? 8 : (grade == "B+") ? 7 : (grade == "B") ? 6 : (grade == "P") ? 5 : 0;
            totalGradePoints += gradePoint * subj.credit;
            totalCredits += subj.credit;
        }
    }

    if (totalCredits > 0) {
        double sgpa = totalGradePoints / totalCredits;
        cout << "\nEstimated SGPA: " << fixed << setprecision(2) << sgpa << endl;
    } else {
        cout << "\nNo semester-end courses to calculate SGPA.\n";
    }

    return 0;
}
