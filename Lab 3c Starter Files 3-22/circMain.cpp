// circMain.cpp (an excellent start to Lab3 Circular Linked List)
// This does create a circularly linked list, but it's only a start for your class.
// Linked List of names (simplified read & write.  Not a class at all!)
// reading the names, traversing the list, & writing to the console & file
// Written by Jeff Goldstein, TCC Adjunct Professor, Virginia Beach Campus

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
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
    process(list2);
    fout << "Original list1.  List size = " << list1.size() << endl;
    cout << "Original list1.  List size = " << list1.size() << endl;
    fout <<list1;
    fout << "Original list2.  List size = " << list2.size() << endl;
    cout << "Original list2.  List size = " << list2.size() << endl;
    fout <<list2;
    fin.close();
	fout.close();                               // close the output file.
	return 0;
}

void process(CircList list)
{
    cout << "List size = " << list.size() << endl;
    fout << list;
    cout << list.find("Gore") << endl;
    cout << list;
}

void title(string st)
{
    cout << "HERE'S THE CIRCULARLY LINKED " << st << endl;
    cout << "====== === ========== ====== ====" << endl << endl;
    fout << "HERE'S THE CIRCULARLY LINKED " << st << endl;
    fout << "====== === ========== ====== ====" << endl << endl;
}
