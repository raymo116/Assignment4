# Assignment4
Simulation of the Registrar's Office

## Project Outline
### Classes
- Registrar
  - `unsigned int worldTime;` (should this be outside of the class?)
  - `unsigned int futureStudents;` (should this be outside of the class?)
  - `unsigned int studentsServed;`
  - `Window windows[8];`
  - `unsigned int meanStudentWait;`
  - `unsigned int medianStudentWait;`
  - `unsigned int maxStudentWait;`
  - `unsigned int longStudentWaitTimes;`
  - The mean window idle time
  - The longest window idle time
  - Number of windows idle for over 5 minutes.
  - Window
  - `Student currentStudent;`
  - `unsigned int currentIdleTime;`
  - `unsigned int longestIdleTime;`
- Student
  - `unsigned int waitTime;`
  - `unsigned int timeLeft;`
  - `unsigned int timeArrived;`
- Queue (Standard)
  - `GenQueue clientele;`
  - `GenQueue realQueue;`
- DoubleyLinkedList (Standard)
  - One for each GenQueue

### Process
#### Pseudocode
Load from File
- Read whole file to string
- Error checking on string
  - Negative numbers
  - Charcters
  - Invalid files
- `While` Loop
  - Convert string to students
    - Check if too many/few numbers
  - `Registrar.futureStudents++;`  
Simulation
- `While(futureStudents > studentsServed)`
  - Count down for every student at a window
  - Fill open windows
  - Check `clientele` for next
  - `student.waitTime++;`
  - Check if student wait time is more than 10
  - `Registrar.worldTime++;`
Calculate stats
- The mean student wait time.
- The median student wait time.
- The longest student wait time.
- The number of students waiting over 10 minutes
- The mean window idle time
- The longest window idle time
- Number of windows idle for over 5 minutes.
Output
- Print stats
