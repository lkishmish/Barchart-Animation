// bar.h
// TO DO:  add header comment here.  Also add function header comments below.

#include <iostream>
#include <string>
#include "myrandom.h" // used in graders, do not remove
using namespace std;

//
// Bar
//
class Bar {
 private:
    // Private member variables for a Bar object
    // TO DO:  Define private member variables for this class
    // NOTE: You should not be allocating memory on the heap for this class.
    string barName; 
// initializing name 
    int barValue;
// initializing value
    string barCategory;
    // initializing category
 public:

    // setting default values in default constructor:
    Bar() {
        barName = "";
        barValue = 0;
        barCategory = "";

    }

    //
   
    //
    // Parameter passed in constructor Bar object.
    //
    Bar(string name, int value, string category) {
        // setting each variable equal user's input
         barName = name;
         barValue = value;
         barCategory = category;
        
    }

    // destructor:
    virtual ~Bar() {
        
        // TO DO:  Write this destructor or leave empty if not needed.
        
    }

    // getName:
	string getName() {
        
      
        
        return barName;  // returns user's input if nothing, returns what is set in default constructor
	}


	int getValue() {
        
		
        
        return barValue;    // returns user's input if nothing, returns what is set in default constructor
	}

    // getCategory:
	string getCategory() {
       
        
        return barCategory; // returns user's input if nothing, returns what is set in default constructor
	}

	// operators
    // TO DO:  Write these operators.  This allows you to compare two Bar
    // objects.  Comparison should be based on the Bar's value.  For example:
	bool operator<(const Bar &other) const {
        
        return this->barValue<other.barValue;  // allows comparison between values (helpful in sorting by values)
	}

	bool operator<=(const Bar &other) const {
        
        return this->barValue<=other.barValue;  // allows comparison between values (helpful in sorting by values)
	}

	bool operator>(const Bar &other) const {
        
        
        return barValue>other.barValue;  // allows comparison between values (helpful in sorting by values)
	}

	bool operator>=(const Bar &other) const {
        
        return barValue>=other.barValue;  // allows comparison between values (helpful in sorting by values)
	}
};

