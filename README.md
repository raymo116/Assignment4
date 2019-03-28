# Assignment4
Simulation of the Registrar's Office

## Project Outline
### Classes
- Registrar
  - unsigned int worldTime (should this be outside of the class?)
  - unsigned int futureStudents (should this be outside of the class?)
  - unsigned int studentsServed
- Window
  - Student currentStudent
  - unsigned int currentIdleTime
  - unsigned int longestIdleTime
- Student
  - unsigned int waitTime
  - unsigned int timeLeft
  - unsigned int timeArrived
- Queue (Standard)
  - GenQueue clientele
  - GenQueue realQueue
- DoubleyLinkedList (Standard)
  - One for each GenQueue
