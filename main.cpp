#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Structure for patient details
struct Patient {
    string name;
    int age;
    bool emergency;   // true = emergency, false = normal
};

int main() {
    queue<Patient> normalQueue;     // Normal patients
    queue<Patient> emergencyQueue;  // Emergency patients

    int choice;

    while (true) {
        cout << "\n===== HOSPITAL PATIENT QUEUE SYSTEM =====\n";
        cout << "1. Add New Patient (Enqueue)\n";
        cout << "2. Call Next Patient (Dequeue)\n";
        cout << "3. Display Waiting List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Patient p;
            cout << "Enter patient name: ";
            cin >> p.name;
            cout << "Enter age: ";
            cin >> p.age;

            int type;
            cout << "Emergency case? (1 = Yes, 0 = No): ";
            cin >> type;
            p.emergency = (type == 1);

            if (p.emergency) {
                emergencyQueue.push(p);
                cout << "Emergency patient added to PRIORITY queue.\n";
            } else {
                normalQueue.push(p);
                cout << "Patient added to normal queue.\n";
            }
        }

        else if (choice == 2) {
            if (!emergencyQueue.empty()) {
                Patient p = emergencyQueue.front();
                emergencyQueue.pop();
                cout << "Calling EMERGENCY patient: " << p.name << " (Age " << p.age << ")\n";
            }
            else if (!normalQueue.empty()) {
                Patient p = normalQueue.front();
                normalQueue.pop();
                cout << "Calling patient: " << p.name << " (Age " << p.age << ")\n";
            }
            else {
                cout << "No patients in queue.\n";
            }
        }

        else if (choice == 3) {
            cout << "\n--- Emergency Patients ---\n";
            if (emergencyQueue.empty()) 
                cout << "None\n";
            else {
                queue<Patient> temp = emergencyQueue;
                while (!temp.empty()) {
                    Patient p = temp.front();
                    temp.pop();
                    cout << p.name << " (Age " << p.age << ")\n";
                }
            }

            cout << "\n--- Normal Patients ---\n";
            if (normalQueue.empty())
                cout << "None\n";
            else {
                queue<Patient> temp = normalQueue;
                while (!temp.empty()) {
                    Patient p = temp.front();
                    temp.pop();
                    cout << p.name << " (Age " << p.age << ")\n";
                }
            }
        }

        else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        }

        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
