// circMain.cpp (an excellent start to Lab3 Circular Linked List)
// This does create a circularly linked list, but it's only a start for your class.
// Linked List of names (simplified read & write.  Not a class at all!)
// reading the names, traversing the list, & writing to the console & file
// Written by Paris Henighan, TCC Student, Virginia Beach Campus

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include <string>
#include "CircList.cpp"

using namespace std;

ifstream fin ("CircInput.txt");
ofstream fout("CircOutput.txt");

void title(string);                             // prototypes for functions called
void process(CircList list);

int main()
{
    CircList list1;
    CircList list2;
    fin >> list1;
    list2 = list1;

    title("LIST");

    fout << "(Original list1.  List size = " << list1.size() << ')' << endl;
    cout << "(Original list1.  List size = " << list1.size() << ')' << endl;
    fout <<list1;
    fout << "(Original list2.  List size = " << list2.size() << ')' << endl;
    cout << "(Original list2.  List size = " << list2.size() << ')' << endl;
    fout <<list2;
    process(list2);
    fin.close();
	fout.close();                               // close the output file.
	return 0;
}

void process(CircList list)
{
    cout << "(Copy of original.  List size = " << list.size() << ')' << endl;
    fout << "(Copy of original.  List size = " << list.size() << ')' << endl;
    fout << list;
    list.find("Gore");
    fout << list;
    cout << list;
    ///It just isn't working. I've tried several things. This is the closest I have come.
    //list.delete7thNode();
    //cout << "delete 7th node: ";
    //fout << list;
}

void title(string st)
{
    fout << "   A  C I R C U L A R L Y  L I N K E D  L I S T  ( T H E  J O S E P H U S  P R O B L E M )" << endl << endl;
    char date[10];
    _strdate(date);
    fout << setw(43) << "Current Date: " << date << endl << endl;
    fout << setw(41) << " by "<< endl << endl;
    fout << setw(47) << "Paris Henighan"<< endl << endl;
    cout << "   A  C I R C U L A R L Y  L I N K E D  L I S T  ( T H E  J O S E P H U S  P R O B L E M )" << endl << endl;
    cout << setw(43) << "Current Date: " << date << endl << endl;
    cout << setw(41) << " by "<< endl << endl;
    cout << setw(47) << "Paris Henighan"<< endl << endl;
}
