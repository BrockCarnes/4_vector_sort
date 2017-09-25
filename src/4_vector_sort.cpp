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
	return x.midterm < y.midterm;
}
bool compareFinal(const Student_info& x, const Student_info& y)
{
	return x.final < y.final;
}
int main() {

	//students holds a collection of
	//student_info objects
	vector<Student_info> students;
	int size = students.size();

	//just need 1 since vector will make a copy when adding it
	Student_info record;

	record.name = "Oliver";
	record.midterm = 50;
	record.final = 100;
	students.push_back(record);	//add record, vector makes a COPY of it

	record.name = "Keith";		//so we can reuse it
	record.midterm = 100;
	record.final = 105;
	students.push_back(record);

	record.name = "Winston";
	record.midterm = 98;
	record.final = 44;
	students.push_back(record);

	size = students.size();

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

	for (int var = 0; var <=size-1; ++var) {
		name = students[var].name;
	}
	//sort by Midterm
	sort(students.begin(), students.end(), compareMidterm);
	for (int var = 0; var <=size-1; ++var) {
		midterm = students[var].midterm;
	}

	//sort by Final
	sort(students.begin(), students.end(), compareFinal);


return 0;
}
