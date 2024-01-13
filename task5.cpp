#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	int m = 5;
	
	int mas[m] = {1, 2, 3, 4, 5};
	string str = "";
	int el = 0;
	
	cout << "Mas is size of 5" << endl;
	cout << "Enter number of element to see:" << endl;
	cin >> str;
	try {
		el = stoi(str);
		if (el > 4 or el < 0) {
			throw el;
		}
		cout << mas[el] << " - is your element!" << endl;	
	}
	catch(std::invalid_argument e) {
		cout << "Only numbers are allowed! \n";
	}
	catch(std::out_of_range e) {
    	cout << "Too big number! \n";
    }
    catch(int n) {
    	cout << "Your number is not in mas" << endl;
	}
	catch(...) {
    	cout << "Unknown error! \n";
    }
	return 0;
}
