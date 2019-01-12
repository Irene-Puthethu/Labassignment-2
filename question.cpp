//Implement Singly Linked List using C++. Make sure the following functions:

//Beginning of the assignment
//library
#include <iostream>
using namespace std;

class Node{
  //since we use the class throughout the program it needs to be public
  public:
  //Defining the data
  int value;
  //Pointer to the next Node
  Node * next;
  //Constructor that makes the pointer to NULL for the first one 
  Node(){
      next = NULL;
  }
};

// making the linked list in steps
class LinkedList{
      //Making the head and tail by pointing
      public:
      //Head -> Node type ptr
        Node * head;
        Node * tail;
        
      //Constructor
      LinkedList(){
        head = NULL;
        tail = NULL;
      }
      
//1. insert(int data) - Adds a new element to the end of the linked list. 
//insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  
//Example: insertAt(1, 3) - inserts 3 at the first position. 
	//It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list. 
	//Insert
      void insert(int data){
        //If first node is added 
        //new has 8 bytes as it is a pointer //temp is the pointer pointing to the new guy 
         Node * temp = new Node;
        //adding data to the value //goes to the temp and then finds the place and atores the data 
        temp->value = data; 
        // first node only 
        if (head == NULL){
          head = temp;
          tail = temp;
          // second node only
        }
        else {
          tail->next = temp; 
        }
        tail = temp;
      }
      
      void insertAt(int pos,int data){
          //Reach the place before position
          Node * current = head;
          int i = 1; 
          if(i<pos-1){
              i++;
              current = current-> next;
          }
          else {
            cout<<"Linked list does not have that many elements"<<endl;
          }
           //Create a node
          Node * temp = new Node; 
          temp -> value = data;
      }
//2.delete() - Deletes the element at the end of the list. 
     //Deletion of the last element
      void delet(){
        //store tail in a temp
        Node * temp = tail;
        //before the tail has to point to null 
        Node * current = head;
        while(current->next != tail){
          current = current->next;
        }
        current->next = NULL;
        
        //update tail ie. move to the previous one 
        tail=current;
        //delete temp 
        delete temp;
          
      }
      
//5.display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 -> NULL” for a linked list hol
 //Display
      void display(){
        Node * current = head;
        while(current != NULL){
          cout<<current->value<<"->";
          current = current->next;
        }cout<<endl;
      }
};

//main function
int main(){
  LinkedList l1;
  l1.insert(1);
  l1.insert(2);
  l1.insert(3);
  l1.display();
  l1.delet();
  l1.display();
     return 0;
}
