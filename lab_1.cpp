#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

typedef string Name;

// Using standard IO for input and result
void rw_std_io() {
	int n;
	cout << "Number of names you want to enter: " << endl;
	cin >> n;
	
	// Reading names from standard input
	vector<Name> names_ip;
	while(n--) {
		Name data;
		cin >> data;
		reverse(data.begin(), data.end());
		names_ip.push_back(data);
	}
	
	// Printing on standard output
	for(Name names: names_ip) {
		cout << names << endl << flush;
	}
	
	cout << "Done!" << endl;
}

// Use user specified file for input and for output
void rw_sys_io() {
	int n;
	cout << "Number of names you want to enter: " << endl;
	cin >> n;
	
	// Write data using ofstream to a file
	ofstream write_on_sys;
	write_on_sys.open("temp_a.txt");
	
	while(n--) {
		Name data;
		cin >> data;
		reverse(data.begin(), data.end());
		write_on_sys << data << endl << flush;
	}
	
	write_on_sys.close();
	
	// Read data using ifstream from a file
	ifstream read_from_sys("temp_a.txt");
	
	Name data;
	cout << "Reading from a file (present in disk)..." << endl;
	while(getline(read_from_sys, data)) {
		cout << data << endl;
	}
	
	read_from_sys.close();
	cout << "Done!" << endl;
}

// ofstream: create file and write to the file, keep it on the disk (CREATE AND WRITE TO FILES)
// ifstream: fetch data from some file and read from it (have to give file name) (READ FROM FILES)

int main() {
	string choice;
	cout << "File Structure Lab-1 \nPress (a/A) to use standard IO \nPress (b/B) to use sys IO" << endl;
	cin >> choice;
	
	if(choice == "a" or choice == "A") {
		rw_std_io();
	} else if(choice == "b" or choice == "B"){
		rw_sys_io();
	} else {
		cout << "ERROR: Invalid choice. Run again!";
	}
}










