//============================================================================
// Name        : 4_vector_sort
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
//dont have to write std:: in front of everything
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
const int RES_SIZE=20;

struct Student_info {
	string name;
	double midterm, final;
};	// note the semicolon--it's required

typedef std::vector<double>::size_type vec_sz;

//used by sort algorithm
bool compareName(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}
bool compareMidterm(const Student_info& x, const Student_info& y)
{
	return x.midterm > y.midterm;
}
bool compareFinal(const Student_info& x, const Student_info& y)
{
	return x.final > y.final;
}

void output_contents(const string &phrase, const vector<Student_info> &students) {
	cout<<phrase<<endl;
	for (int var = 0; var < students.size(); ++var) {
		cout<<"  "<<students[var].name<<", "<<students[var].midterm<<","<<students[var].final<<endl;
	}
}

int main() {

	//students holds a collection of
	//student_info objects
	vector<Student_info> students;
	students.reserve(RES_SIZE);
	int size = students.size();
	int cap = students.capacity();
	bool bemp = students.empty();

	//just need 1 since vector will make a copy when adding it
	Student_info record;

	record.name = "Oliver";
	record.midterm = 50;
	record.final = 100;
	students.push_back(record);	//add record, vector makes a COPY of it
	cap = students.capacity();

	record.name = "Keith";		//so we can reuse it
	record.midterm = 100;
	record.final = 105;
	students.push_back(record);

	record.name = "Winston";
	record.midterm = 98;
	record.final = 44;
	students.push_back(record);
	cap = students.capacity();

	size = students.size();

	//name of first entry in vector
	string name1 = students[0].name;

	//-------------------------------------
	//simple sorting
	vector<int> myVect;
	myVect.push_back(2);
	myVect.push_back(1);
	myVect.push_back(3);
	int i = myVect[0];
	i=myVect[1];
	i=myVect[2];

	sort(myVect.begin(),myVect.end());
	i = myVect[0];
	i=myVect[1];
	i=myVect[2];

	//-------------------------------------
	//complex sorting
	string name;
	double midterm,final;
	size = students.size();

	//by name
	sort(students.begin(), students.end(), compareName);
	output_contents(string("Sorted by Name "),students);

	//sort by Midterm
	sort(students.begin(), students.end(), compareMidterm);
	output_contents(string("Sorted by Midterm "),students);

	//sort by Final
	sort(students.begin(), students.end(), compareFinal);
	output_contents(string("Sorted by Final "),students);


return 0;
}
