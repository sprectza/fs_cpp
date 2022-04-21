#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Student {
	string name, usn, sem, dept;
};

struct Details {
	vector<Student> data_local_to_code;
	
	void pack() {
		ofstream write_on_sys;
		write_on_sys.open("student.txt", ios::app);
		
		vector<string> buffer;
		Student s;
		cout << "Enter USN: "; cin >> s.usn; buffer.push_back(s.usn); 
		cout << "Enter Name: "; cin >> s.name; buffer.push_back(s.name); 
		cout << "Enter Sem: "; cin >> s.sem; buffer.push_back(s.sem); 
		cout << "Enter Dept: "; cin >> s.dept; buffer.push_back(s.dept); 
		
		data_local_to_code.push_back(s);
		write_on_sys << "| " << buffer[0] << " | " << buffer[1] << " | " << buffer[2] << " | " << buffer[3] << " |" << endl;
		
		write_on_sys.close();
		cout << "Packed!" << endl;
	}
	
	void unpack() {
		ifstream read_from_sys("student.txt");
		string data;
		while(getline(read_from_sys, data)) {
			cout << data << endl;
		}
		read_from_sys.close();
		cout << "Unpacked!" << endl;
	}
	
	void modify(int usn_to_modify) {
		for(Student &s : data_local_to_code) {
			if(s.usn == usn_to_modify) {
				modifications()
			}
		}
	}
	
	void search() {
		
	}
};

int main() {
	Details det;
	det.pack();
	det.unpack();
}
