// barchartanimate.h

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used by graders, do not remove
#include "barchart.h"
  
using namespace std;

//
// BarChartAnimate
//
class BarChartAnimate {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    string title;
    string source;
    string xlabel;
    map<string, string> colorMap;
    int c_index;

 public:

    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
//        Should allocate memory on heap for barcharts. This will be a dynamic array that expands (by doubling itself) each time it runs out of room to add a new frame. In the constructor, the capacity should be 4. Everything else should be initialized to default values.
        // TO DO:  Write this constructor.
      size = 0;
      capacity = 4;
      // initialising capacity to 4
      barcharts = new BarChart[4];
      // create new bar chart with default capacity 4
        this->source = source;
        this->title = title;
        this->xlabel = xlabel;
      // updating parameters to what is passed as arguments while calling the function
      c_index = 0;
      // colour index
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() 
   {
        // Frees memory allocated on the heap. Called automatically when the object goes out of scope.
     
      while (barcharts != nullptr) {
          
              delete[] barcharts;
              barcharts = nullptr;
          
            }
      
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    void addFrame(ifstream &file) 
{
       // cout<<"ehuwq"<<endl;
//        The file stream passed in guaranteed to be the format provided above. This explanation is referring to Figure 1 (the file format).
//        Pre condition: when addFrame is called, it assumes that the fstream’s first getline call will get the empty line above the “group of records” blue box.
//        Post condition: The function should read the file to the end of the last record in the group of records (12 records total, in the example given). The function should build a BarChart using this group of records and add it to the BarChartAnimate object.
        // TO DO:  Write this constructor.
        string sum; 
  // line mentioning a number after blank line in text file
        string content;
  // content of file
        string year;
        string category;
        string country;
        string value;
        string city;
  // initialising parameters
        istringstream inSS;
  // string stream
        
        
      if (size == capacity)
    {
      // if the barcharts has run out of space, double the capacity
        int newCapacity = capacity * 2;
        BarChart* newA = new BarChart[newCapacity];
     
        for (int i = 0; i < size; ++i)
        {
          // copying contents to new barchart
          newA[i] = barcharts[i];
          }
      
        // freeing memory, changing capacity to new capacity and updating bar chart to new bar chart with new capacity
      delete[] barcharts;
      barcharts = newA;
      capacity = newCapacity;
        
      }
      
      string contentOne;
        getline(file,contentOne,'\n');
         // new file content variable to store all new lines occuring

      if(file.eof()){
        return;
      }
     
      getline(file,sum);
      int val = stoi(sum);
       // convert string sum to integer 
      BarChart chart(val);
  // create a barchart with its size as number casted to int
        for (int i = 0; i<val;i++){
           
            getline(file,content);
            stringstream inSS(content);
          
          year ="";
          getline(inSS,year,',');
           city = "";
            getline(inSS,city,',');
          country = "";
            getline(inSS,country,',');
          value = "";
            getline(inSS,value,',');
          category = "";
            getline(inSS,category);
          // retrieving all the info from line separated by commas from text file
             if (colorMap.count(category) == 0) {
               
        colorMap[category] = COLORS[(c_index++)%COLORS.size()];
        // setting color for each category
        }
          chart.addBar(city, stoi(value),category);
          chart.setFrame(year);
          
       // adding values of bar and setting its frame
       }
    
            barcharts[size] = chart;
            size++;

      // incrementing size of barchart val times
    }
    
   
      
    
    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
	void animate(ostream &output, int top, int endIter) {
   
		unsigned int microsecond = 50000;
        
    if( endIter == -1 || endIter > size){
      endIter = size;
    }
    for (int i = 0 ; i<endIter ; i++){
       
            usleep(3 * microsecond);  
      output << CLEARCONSOLE;
     
            output <<  BLACK << title << endl;
            output << BLACK << source << endl;
            barcharts[i].graph(output, colorMap, top);
            output << BLACK << xlabel << endl;
            output << BLACK << "Frame: " << barcharts[i].getFrame() << endl;
            // pause for 150,000 microseconds so the animation can be seen in the terminal
    }
        
	}

    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize(){
        
        return size;  
    }

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //
    BarChart& operator[](int i){
      
         if (i < 0 || i >= size) {
           
              throw out_of_range("BarChartAnimate: i out of bounds");
            }
      
            return barcharts[i];
        
        
    }
};
