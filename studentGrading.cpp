#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    string name;
    cout << "Enter the student's name: ";
    getline(cin, name);
    
    int n; // Number of subjects
    cout << "Enter the total number of subjects: ";
    cin >> n;
    
    string subject[n];
    double marks[n];
    string grade[n];
    double sum = 0;
    double max_marks = -1; // Initialize max_marks to a lower value
    int max_idx = -1; // Initialize max_idx to an invalid value
    double min_marks = 101; // Initialize min_marks to a higher value
    int min_idx = -1; // Initialize min_idx to an invalid value
    
    cout << "Enter the subjects' names and marks:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Subject " << i + 1 << ": ";
        cin.ignore(); // Ignore newline left in buffer
        getline(cin, subject[i]);
        
        do {
            cout << "Marks: ";
            cin >> marks[i];
            if(marks[i] < 0 || marks[i] > 100) {
                cout << "Enter a valid mark between 0 and 100." << endl;
            }
        } while(marks[i] < 0 || marks[i] > 100);
        
        // Calculate grade based on marks
        if(marks[i] >= 90) {
            grade[i] = "Outstanding";
        } else if(marks[i] >= 80) {
            grade[i] = "Excellent";
        } else if(marks[i] >= 70) {
            grade[i] = "Very Good";
        } else if(marks[i] >= 60) {
            grade[i] = "Good";
        } else if(marks[i] >= 50) {
            grade[i] = "Fair";
        } else if(marks[i] >= 33) {
            grade[i] = "Below Average";
        } else {
            grade[i] = "Fail";
        }
        
        // Update max and min marks and indices
        if(marks[i] > max_marks) {
            max_marks = marks[i];
            max_idx = i;
        }
        if(marks[i] < min_marks) {
            min_marks = marks[i];
            min_idx = i;
        }
        
        sum += marks[i];
    }
    
    double average = sum / n;
    string remarks = (average >= 33) ? "Passed" : "Failed";
    string OverAllGrade;
    
    // Calculate overall grade based on average
    if(average >= 90) {
        OverAllGrade = "Outstanding";
    } else if(average >= 80) {
        OverAllGrade = "Excellent";
    } else if(average >= 70) {
        OverAllGrade = "Very Good";
    } else if(average >= 60) {
        OverAllGrade = "Good";
    } else if(average >= 50) {
        OverAllGrade = "Fair";
    } else if(average >= 33) {
        OverAllGrade = "Below Average";
    } else {
        OverAllGrade = "Fail";
    }
    
    // Output the result
    cout << endl;
    cout << "                                 RESULT                                  " << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Student's Name: " << name << endl;
    cout << "___________________________________________________________________________" << endl;
    
    cout << setw(15) << "Subject" << setw(15) << "Marks" << setw(15) << "Grade" << endl;
    cout << endl;
    for(int i = 0; i < n; i++) {
        cout << setw(15) << subject[i] << setw(15) << marks[i] << setw(15) << grade[i] << endl;
    }
    cout << endl;
    cout << "Total Marks: " << sum << "            " << "Percentage: " << average << endl;
    cout << "Remarks: " << remarks << "            " << "Over All Grade: " << OverAllGrade << endl;
    cout << "Highest marks in " << subject[max_idx] << " and the marks are " << max_marks << ", grade " << grade[max_idx] << endl;
    cout << "Lowest marks in " << subject[min_idx] << " and the marks are " << min_marks << ", grade " << grade[min_idx] << endl;
    
    cout << "____________________________________________________________________________" << endl;
    
    return 0;
}