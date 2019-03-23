# VirtualDestructor
Demonstration of virtual destructors and virtual functions in C++

### Dr. Matthew Smith, Swinburne University of Technology


The code attached - demo.cpp - demonstrates some of the ideas associated with classes, derived classes, polymorphism (runtime) and the hazards associated with dynamic memory allocation of classes, and their deletion. 

The conclusion of this demonstration: virtual functions are required when you wish to ensure that objects involving derived classes which employ polymorphism (in the form of upcasting or downcasting) use the correct class functions. This is especially important for destructors - any derived class needs to call both its own destructor as well as the destructor from the base from which it was derived. Making the base class destructor virtual ensures this happens, avoiding memory leaks.


### Compilation

To compile the code in a linux environment, you might use the GNU C++ compiler:

g++ demo.cpp -o test.run

which is run by calling ./test.run from the same directory it is located in (otherwise enter the whole path).

### Additional information

There is an accompanying PDF which covers some of the topics involved in this demo. Good luck.
