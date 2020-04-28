#ifndef LIST_H
#define LIST_H


class List
{
    protected:

    private:
        typedef struct node{
            int data;
            node* next;
        }* nodePtr;

        //U could also define this way
        //typedef struct node* nodePtr;

        nodePtr head;
        nodePtr curr;
        nodePtr temp;
    public: //This is where functions go
        List();
        void AddNode(int addData);
        void DeleteNode(int delData);
        void PrintList();
        virtual ~List();
};

#endif // LIST_H
