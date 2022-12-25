// barchart.h
#include <iostream>
#include <algorithm>
#include <map>
#include "myrandom.h" 
#include "bar.h"
#include <vector>

using namespace std;

const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";
const string RESET("\033[0m");

// Color codes for light mode terminals
const string RED("\033[1;36m");
const string PURPLE("\033[1;32m");
const string BLUE("\033[1;33m");
const string CYAN("\033[1;31m");
const string GREEN("\033[1;35m");
const string GOLD("\033[1;34m");
const string BLACK("\033[1;37m");
const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

// Color codes for darker mode terminals
// const string CYAN("\033[1;36m");
// const string GREEN("\033[1;32m");
// const string GOLD("\033[1;33m");
// const string RED("\033[1;31m");
// const string PURPLE("\033[1;35m");
// const string BLUE("\033[1;34m");
// const string WHITE("\033[1;37m");
// const string RESET("\033[0m");
// const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};



//
// BarChart
//
class BarChart {
 private:
   
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // Bars.  As a result, you must also keep track of the number of elements
    // stored (size) and the capacity of the array (capacity).  This is not a
    // dynamic array, so it does not expand.
  
    Bar* bars;  
// pointer to a C-style array
    int capacity; 
// initializing capacity
    int size;
// initializing size
    string barFrame;
// initializing barFrame
    map<string,string> colorMap;
// initializing map
 public:
    
    // setting default values in default constructor
    BarChart() {
      
        barFrame = "";
        bars = nullptr;
        capacity = 0;
        size = 0;
    
    }
    
    // parameterized constructor:
    // Parameter passed in determines memory allocated for bars.
    BarChart(int n) {
      
        capacity = n;
      // setting capacity to argument passed
        bars = new Bar[n];
      // creating bar object of capacity(length) as the argument passed
        size = 0;
      // setting size of the Bar Chart to default value
        barFrame = "";
        // setting barFrame of the Bar Chart to default value
        
    }

    //
    // copy constructor:
    //
    // Called automatically by C++ to create an BarChart that contains
    // a copy of an existing BarChart.  Example: this occurs when passing
    // BarChart as a parameter by value.
    //
    BarChart(const BarChart& other) {
        bars = new Bar[other.capacity];
        barFrame = other.barFrame;
        size = other.size;
        capacity = other.capacity;
        // creating a bar chart with updated values if a bar chart is passed in as argument
        int i = 0;
      // copying contents of the bar chart upto the desired size
        while(i<other.size){ 
            bars[i] = other.bars[i];
            i++;
        }
    }
    
    //
    // copy operator=
    //
    // Called when you assign one BarChart into another, i.e. this = other;
    //
    BarChart& operator=(const BarChart& other) {
        
        if (this == &other)
      return *this;
// defining the equals operator to check if the same bar chart is passed, if different, set one barchart equal to another bar chart

      delete[] bars;
        
    this->bars = new Bar[other.capacity];
    this->size = other.size;
    this->capacity = other.capacity;
// if different, set one barchart equal to another bar chart
      for (int i = 0; i < other.size; ++i)
    {
      this->bars[i] = other.bars[i];
      // updating each value to current value set in parametrized constructor
    }
      return *this; 
    }

    // clear
    // frees memory and resets all private member variables to default values.
    void clear() {
        
        barFrame = "";
      
        size = 0;
      
        capacity = 0;
      
        bars = nullptr;
        
        
    }
    
    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by the
    // BarChart.
    //
    virtual ~BarChart() {
        delete []bars;
        // clearing bar chart by calling destructor
        
    }
    
    // setFrame
    void setFrame(string frame) {
        barFrame = frame;
        
        
        
    }
    
    // getFrame()
    // Returns the frame of the BarChart oboject.
    string getFrame() {
        
        
        
        return barFrame; 
    }

    // addBar
    // adds a Bar to the BarChart.
    // returns true if successful
    // returns false if there is not room
    bool addBar(string name, int value, string category) {
        
        // TO DO:  Write this function.
       
        
        if (size<capacity){
            Bar B(name,value,category);
      bars[size] = B;
      size++;
            return true;
        }
      
        return false; 
    }
    
    // getSize()
    // Returns the size (number of bars) of the BarChart object.
    int getSize() {
        
        return size;  
      
    }
    
    // operator[]
    // Returns Bar element in BarChart.
    // This gives public access to Bars stored in the Barchart.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChart: i out of bounds"
    Bar& operator[](int i) {
        if (i < 0 || i >= size) {
              throw out_of_range("ourvector: i out of bounds");
            }
            return bars[i];
      
    } 

    
    // dump
    // Used for printing the BarChart object.
    // Recommended for debugging purposes.  output is any stream (cout,
    // file stream, or string stream).
    // Format:
    // "frame: 1
    // aname 5 category1
    // bname 4 category2
    // cname 3 category3" <-newline here
    void dump(ostream &output) {
        sort(bars, bars + size, greater<Bar>());
        for (int i = 0; i < size; i++) {
              output << bars[i].getName() << " " << bars[i].getValue() << " "
                     << bars[i].getCategory() << endl;
            }
        
    }
    
    // graph
    // Used for printing out the bar.
    // output is any stream (cout, file stream, string stream)
    // colorMap maps category -> color
    // top is number of bars you'd like plotted on each frame (top 10? top 12?)
    void graph(ostream &output, map<string, string> &colorMap, int top) {
    	int lenMax = 60;  // this is number of BOXs that should be printed
                          // for the top bar (max value)
        
        // TO DO: read this example and this erase it.
        // e.g. Here I am plotting 60 red BOXs to output
        string color = "\033[1;36m";  // you should get this from colorMap
        string barstr = ""; 
      // empty string to add BOXes
  
      sort(bars, bars + size, greater<Bar>());
      // sorting bars in descending order by value
      for (int i = 0; i<lenMax;i++){
        barstr += BOX;
      }
      // first bar 
        
        if(size<top){
          
          size = top;
           // setting size equal to top if it is less than the value passed
        }
        else {
        // iterating size times to display number of bars
        for (int i = 0; i<size;i++)
          {
            // clearing barstr everytime index changes
            barstr="";
            
            int maxValue = bars[0].getValue();
            int value = bars[i].getValue();
            double graph_equation = ((maxValue/value)*lenMax);
            // computing number of bars to be displayed
            int length_of_bar = int(value);
            // casting to int datatype
            color = BLACK;
            // setting default colour as black
         if (colorMap.count(bars[i].getCategory())){
              
              color = colorMap[bars[i].getCategory()];
              // colorMap determines how to color each category and top determines how many bars are printed on each frame
            }
            
        for (int i = 0; i<length_of_bar;i++){
              
                barstr+=BOX;								
              // prints as many BOXes as length of bar
              
            } 
          
      output << color << barstr << " " << bars[i].getName() << " " << bars[i].getValue() << endl;
            // displays the BOXes along with name and value
            
      }
          
          }
    
    
}

};

