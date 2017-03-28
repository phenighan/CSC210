/* CircList.h Specifications and ClassDefinitions for Lab 3
   Header file for the Circular Linked List lab assignment
   Implements the “Josephus problem” as an ADT
   These member names must be used in your class without modification.
   The two public functions for reading and printing will be commented out in your
   final version.
   They may be used for starting the class until overloaded operators are implemented
   Programmer Paris Henighan 29 March 2017
*/

#ifndef CircList_H
#define CircList_H

using namespace std;

struct node
{
    string myName;                            // holds name of the prisoner
    node*  next;                              // link points to the next node
};

class CircList
{
    // operator overloading for insertion & extraction streams
    friend ostream& operator<< (ostream &, const CircList & );
    friend istream& operator>> (istream &, CircList & );

    public:
        CircList();                           // constructor for linked list
        ~CircList();                          // destructor for linked list
        CircList(const CircList & source);    // copy constructor
        const CircList& operator= (const CircList &);  // * overload assignment op *

        int size() const;                     // returns number of nodes in list
        void addNode(string);                 // adds a node with data name
        string delete7thNode();               // deletes node after adv. pointer by 7
        bool find(string prisoner);           // reset pointers based upon lottery
        bool isEmpty();                       // returns true if list is empty
        //void printList(ostream&);           // temporary not used in finished Lab 3
        //void readData(istream&);            // temporary not used in finished Lab 3

   private:
        node *head;                           // points head of list in circ. order
        node *last;                           // points to last node (before head)
        int  count;                           // keeps count of # nodes in the list
     	void copyList(const CircList & rhs);  // a private copy function
        void deleteList();                    // deletes the entire list
};

#endif


