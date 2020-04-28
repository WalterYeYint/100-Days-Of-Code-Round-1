//My version of reversing a linked list
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node (int data){
        this->data = data;
        next = NULL;
    }
};

class LinkedList{
    public:
    Node *head;
    LinkedList(){
        head = NULL;
    }

    /*Function to reverse the linked list */
    void reverse(){
        Node *current = head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL){
            //Store next
            next = current->next;

            //Reverse current node's pointer
            current->next = prev;

            //Move pointers one position ahead
            prev = current;
            current = next;
        }
        head = prev;
    }

    /*Function to print linked list */
    void print(){
        Node *temp = head;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data){
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

/*Driver program to test above function */
int main(){
    /*Start with empty list */
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);

    cout << "Given linked list\n";
    ll.print();

    ll.reverse();

    cout << "\nReversed Linked list \n";
    ll.print();
    return 0 ;
}