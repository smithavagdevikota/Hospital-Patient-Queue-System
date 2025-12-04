Hospital Patient Queue System (C++)
1. Project Description

The Hospital Patient Queue System is a C++ console application that uses the Queue data structure to manage patients in a hospital.
Two queues are used:

Emergency Queue (high priority)

Normal Queue (first-come-first-serve)

Emergency patients are always served before normal patients.
This project demonstrates queue operations and priority handling.

2. Features
1. Add new patient (enqueue)
2. Serve next patient (dequeue)
3. Display all waiting patients
4. Exit


Details:

Adds patient with name, age, and emergency status

Uses two queues to manage priorities

Displays emergency and normal queues separately

3. Data Structure Used
Queue (STL)
- queue<Patient> emergencyQueue
- queue<Patient> normalQueue


Operations used:

push()
pop()
front()
empty()

4. Folder Structure
HospitalQueueSystem/
│
├── main.cpp        // Source code
└── README.md       // Documentation

5. How to Compile and Run
Using g++ (Terminal)
g++ main.cpp -o hospital
./hospital

Using CodeBlocks / Dev C++

Create a new console project

Replace the generated code with main.cpp

Build and run

Using Online Compiler

Go to: https://www.onlinegdb.com

Select "C++"

Paste the code

Run the program

6. Sample Input
1
Raju
34
0

1
Meera
60
1

7. Sample Output
--- Emergency Patients ---
Meera (Age 60)

--- Normal Patients ---
Raju (Age 34)


Calling next patient:

Calling EMERGENCY patient: Meera (Age 60)

8. Code Overview

Patient structure:

struct Patient {
    string name;
    int age;
    bool emergency;
};


Queues:

queue<Patient> emergencyQueue;
queue<Patient> normalQueue;


Enqueue logic:

if (p.emergency)
    emergencyQueue.push(p);
else
    normalQueue.push(p);


Dequeue logic:

if (!emergencyQueue.empty()) {
    // serve emergency
} else if (!normalQueue.empty()) {
    // serve normal
}

9. Future Enhancements
- Add file storage to save patient data
- Add patient ID or token number
- Add department and doctor assignment
- Add graphical interface (Qt / GUI)

10. License

This project is free to use for academic and learning purposes.
