#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	string str = "";
	
	cout << "Enter file name: " << endl;
	cin >> str;
	
	try {
		ifstream file(str);
		if (!file.is_open()){
			throw runtime_error("NO!");
		} else {
			cout << "File is opened!";
		}
	}
	catch(const exception& e){
		cout << "There is no file!!";
		return 0;
	}
	return 0;
}
