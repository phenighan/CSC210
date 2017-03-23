// CircList.cpp (impmentation file for CircList)
// Written by:  Jeff G

#include "CircList.h"
extern ifstream fin;
extern ofstream fout;

CircList::CircList()
{
    head = NULL;
    last = NULL;
    count = 0;          // initialize length of  to zero
}

CircList::~CircList()
{
    deleteList();
}

CircList::CircList(const CircList & source)
{
    head = last;
    copyList(source);
}

void CircList::copyList(const CircList & rhs)
{
    node *newNode;
    node *current;

    if (head != last)       //if list is not empty
        deleteList();       //delete target list
    if (rhs.head == NULL)
    {
        head = NULL;
        last = NULL;
        count = 0;
    }
    else
    {
        current = rhs.head;     //current points to target
        count = rhs.count;       //copy source's count

        //copy the first node
        head = new node;
        head->myName = current->myName; //copies info
        head->next = head;      //points to itself
        last = head;            //assign last to head
        current = current->next;        //traverse to next node

        //copy remaining list
        while (current != rhs.head)
        {
            newNode = new node;     //create node
            newNode->myName = current->myName;  //copy name
            newNode->next = head;       //set link to head
            last->next = newNode;       //attach newNode after last
            last = newNode;         //make last point to actual last node
            current = current->next; //advance current pointer
        }   //end while
    }   //end else
}
const CircList& CircList::operator=(const CircList & rhs) //rhs = right hand side
{
    if (this != &rhs)   //avoid self assignment
    {
        copyList(rhs);  //call the copyList function
    }
    return *this;
}
int CircList::size() const
{
    return count;
}

void CircList::deleteList()
{
    node * temp;
    while (head != last)
    {
        temp = head;
        head = head->next;
        cout << "Prisoner destroyed" << endl;
        delete temp;
    }
    delete head;
    cout << "Prisoner destroyed" << endl;
    last = NULL;
    temp = NULL;
    count = 0;
}

void CircList::addNode(string name)
{
	node * loc = new node;
    loc-> myName = name;		             // assigns the name to the private member

	if(count != 0)		                     // if list already exists
	{
		loc->next = last->next;				 // assign the last next pointer
		last->next = loc;		             // advance the current pointer
		last = loc;				             // connect the node to the last
	}
	else                                     // it must be a new list
    {
		last = loc;			                 // assign the last pointer
        head = loc;                          // assign the head pointer
        last->next = last;                   // heat points to itself
    }
	count++;				                 // increase the list size by 1
}

string CircList::delete7thNode()
{

}

bool CircList::find(string name)
{
    bool found = false;
    node *cur;
    cur = head;
    while (cur != last && !found)
    {
        if (cur->myName == name)
            found = true;
        else
            head = head->next;
            last = last->next;
            cur = cur->next;
            name = cur->myName;
    }
    return found;
}

istream& operator>> (istream & inData, CircList & cObj)
{
    string name;

    inData >> name;                                // note the priming read 1st item
    while( !inData.eof() )
    {
        cObj.addNode(name);
       // cout << name << endl;                /// for troubleshooting
        inData >> name;
    }
    return inData;
}

ostream& operator<< (ostream & out, const CircList & obj)
{
    node *curr = obj.head;                          // make a copy of the head pointer
    cout << fixed  << showpoint << left;
    out << fixed  << showpoint << left;

	// write the list
    cout << setw(8) << curr->myName;            // priming write name on the console
    out << setw(8) << curr->myName;            // priming output name to the file
	while (curr != obj.last)			            // while not at the last prisoner
	{
        curr = curr->next;			            // now, point to the next node
        cout << setw(8) << curr->myName;        // display name on the console
        out << setw(8) << curr->myName;        // output name to the file
	}
	cout << endl << endl;
	out << endl << endl;
    return out;
}

