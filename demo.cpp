// Demo.cpp
// Dr. Matthew Smith, SUT
// Demonstration of application of virtual functions in situations
// involving polymorphism (upcasting and downcasting) and
// dynamic allocation and deletion.

#include <iostream>

using namespace std;

class Base {
	// The base class from which another class will be derived
	public:
		// The base constructor cannot be virtual
		Base() {
			cout << "Base:Base() Base constructor called\n";
		}
		// The destructor should be virtual if polymorphism and dynamic
		// memory allocation is exploited.
		virtual ~Base() {
			cout << "Base:~Base() Base destructor called\n";
		}
		// The print function is overloaded in the derived class.
		// To make sure the correct version is used, its a good
		// idea to make it virtual too.
		virtual void Print() {
			cout << "Base:Print() Base Print called\n";
		}
};


class Derived : public Base {
	public:
		Derived() {
			cout << "Derived:Derived() Derived constructor called\n";
		}
		~Derived() {
			cout << "Derived:~Derived() Derived destructor called\n";
		}
		void Print() {
			cout << "Derived:Print() Derived Print called\n";
		}
};


int main() {

	// Create pointers to base and derived classes.
	Base *p;
	Derived *q;

	// Each of the small tests below is designed to test
	// a slightly different feature of the polymorphism in C++.
	// Edit out which tests you wish to as required.
	// Make sure you delete your objects!

	cout << "MSG:\t Creating new base p...\n";
	p = new Base;  // Create a new Base called p
	cout << "\n";

	cout << "MSG:\t Printing from p...\n";
	p->Print();
	cout << "\n";


	cout << "MSG:\t Creating new derived q...\n";
	q = new Derived;
	cout << "\n";

	cout << "MSG:\t Printing from q...\n";
	q->Print();
	cout << "\n";

	// P was declared as a Base pointer. So all will be fine.
	cout << "MSG:\t Deleting p...\n";
	delete p;
	cout << "\n";

	// q was declared as a pointer to a derived type. All will be fine.
	cout << "MSG:\t Deleting q...\n";
	delete q;
	cout << "\n";


	// p, originally defined as a base pointer, has been downcast to a derived type.
	// This is when trouble starts.
	cout << "MSG:\t Casting p as derived...\n";
	p = new Derived;
	cout << "MSG:\t p is now printing...\n";
	p->Print();
	cout << "MSG:\t Deleting p (cast as derived)...\n";
	delete p;
	cout << "\n";

	// Now we will engage in upcasting - the pointer to a derived type (q) will
	// be cast as a base.
	cout << "MSG:\t Casting q as base...\n";
	p = new Base;
	q = (Derived*)p;
	cout << "MSG:\t q is now printing...\n";
	q->Print();
	cout << "MSG:\t Deleting q (cast as base)\n";
	delete q;
	cout << "\n";

	cout << "MSG:\t Program complete\n";
	return 0;
}
