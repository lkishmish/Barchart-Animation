#include <iostream>
#include "barchartanimate.h"
using namespace std;


bool BarDefaultConstructor() {
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    // cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

bool BarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    // cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}

bool BarBooleanOperator() {
  Bar b("Chicago", 1000, "US");
  Bar c("Miami", 2000, "US");
  if (b.operator<(c) != true) {
    cout << "testBarBooleanOperator: operator< failed" << endl;
    return false;
  } else if (b.operator<=(c) != true) {
    cout << "testBarBooleanOperator: operator<= failed" << endl;
    return false;
  } else if (b.operator>(c) != false) {
    cout << "testBarBooleanOperator: operator> failed" << endl;
    return false;
  } else if (b.operator>=(c) != false) {
    cout << "testBarBooleanOperator: operator>= failed" << endl;
    return false;
  }
  // cout << "testBarBooleanOperator: all passed!" << endl;
  return true;
}
bool DumpFunction() {
  BarChart testBar(3);
  map<string, string> testColor;
  testBar.addBar("Chicago", 1000, "US");
  testBar.addBar("Miami", 2000, "US");
  testBar.addBar("Dublin", 100000, "Ireland");
  testBar.dump(cout);
  // cout << "testDumpFunction: all passed!" << endl;
  return true;
}
bool AddBars() {
  BarChart testBar(5);
  // BarChartAnimate testBar1(5);
map<string,string> colorMap;
  testBar.addBar("Chicago", 1000, "US");
  testBar.addBar("Miami", 2000, "US");
  testBar.addBar("Berlin", 560000, "Germany");
  testBar.addBar("Dublin", 2000000, "Ireland");
  testBar.addBar("Accra", 40000000, "Ghana");
  
  return true;
  }
bool animateBars(){
  
 string filename;
  cout<<"ENTER THE FILENAME:"<<endl;
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	
	while (!inFile.eof()) {
		bca.addFrame(inFile);
   // cout<<"Test Passed for addFrame"<<endl;
    
	}
	
	bca.animate(cout, 12, 4);

  return true;
}
int main() {
	BarDefaultConstructor();
	BarParamConstructor();
	BarBooleanOperator();
  DumpFunction();
  AddBars();
  animateBars();
    return 0;
}