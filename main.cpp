#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
using namespace std;
string name;

                                    /**    THIS IS FIRST CLASS
                                    *
                                    *      CONTAIN SOME SETTERS,GATTERS
                                    *      AND SOME VARIABLES
                                    **/
class Node
{
private:
    Node *next;
    Node *prevv;
    int data;
public:
    void setNextNode(Node *n)
    {   next=n;
    }
void setPrev(Node *n)
{
    prevv=n;
}
    void setData(int d)
    {   data=d;
    }

    int getData()
    {
         return data;
    }

    Node *getNextNode()
    {   return next;
    }
Node *getPrev()
{
    return prevv;
}
    Node(int d)
    {   next=NULL;
        data=d;
        prevv=NULL;
    }

    Node()
    {
         next=NULL;
         prevv=NULL;
    }

};/// CLASS END PARENTHESIS

/**       **********    First Class End      *************
*         *******       Second Class            **********
*         ****         D-Linked_List Class         *******
*
**/

class Linked_List
{
private:
    Node *first;
    Node *NONE;
public:

Linked_List()
{
    first=NULL;
    NONE =NULL;
}
    void add_at_start(int dat)   ///THIS IS ADD AT START FUNCTION
    {
         Node *temp=new Node(dat);
        Node *temp2=first;
        if(first==NULL)
           {
           first=temp;
            temp->setPrev(NONE);
           }
        else
        {   temp->setNextNode(temp2);
             temp2->setPrev(temp);
             first=temp;
             temp->setPrev(NONE);
        }
    }//End

  void add_at_end(int dat)      ///THIS FUNCTION WILL ADD AT END OF THE LIST
  {
      Node *temp=new Node(dat);
      Node *temp2=first;
      if(first==NULL)
        add_at_start(dat);
      else
      {
      while(temp2->getNextNode()!=NULL)
      {
          temp2=temp2->getNextNode();
      }
      temp2->setNextNode(temp);
      temp->setPrev(temp2);
      }
  }//END


    void display_all()             ///This Will display list
    {
        Node *temp=first;
        if(first==NULL)
        cout<<"Sorry, "<<name<<" is Empty :)  "<<endl;
    else{
        while(temp !=NULL)
        {   cout<<temp->getData()<<endl;
            temp=temp->getNextNode();
        }
    }
    }//End

    void display_stack()             ///This Will display stack
    {
        Node *temp=first;
        if(first==NULL)
        cout<<"Sorry, Stack is Empty :)  "<<endl;
    else{
        while(temp !=NULL)
        {
            cout<<temp->getData()<<endl;
            temp=temp->getNextNode();
        }
    }
    }//End



    void remove_first()          ///THIS WILL REMOVE THE FIRST VALUE
    {
        if(first==NULL)
            cout<<"Sorry, "<<name<<" is Empty Nothing to Delete :) "<<endl;
    else if(first->getNextNode()==NONE)
        first=NONE;
    else
       {
        first=first->getNextNode();
        first->setPrev(NONE);
       }
    }//END


    void remove_last()            ///THIS WILL REMOVE THE LAST VALUE
    {

        Node *temp=first;
        if(first==NULL)
            cout<<"Sorry, Queue is Empty :) "<<endl;
        else if(first->getNextNode()==NULL)
            first=NULL;
        else
        {
            while(temp->getNextNode()->getNextNode()!=NULL)
            {
                temp=temp->getNextNode();
            }
        temp->setNextNode(NONE);
        }
    }//End

    void remove_wanted(int dat)      ///THIS WILL REMOVE THE USER GIVEN VALUE FROM LIST
    {
        Node *temp=first;
        int co=0;
        if(first==NULL)
            cout<<"Sorry, Data List is Empty "<<endl;
            else
                if(first->getData()==dat)
            { first=first->getNextNode();
                first->setPrev(NONE);
            }
        else
        {
            Node *t=first;
            while(t->getNextNode()!=NULL)
            {
                if(t->getData()==dat)
                    co++;
            t=t->getNextNode();
            }
            if(co==0)
                cout<<"Sorry, Given Data is not found "<<endl;
            else
            {
               temp=first;
                while(temp->getNextNode()->getData()!=dat)
            {
                temp=temp->getNextNode();
            }
            temp->setNextNode(temp->getNextNode()->getNextNode());
            temp->getNextNode()->setPrev(temp);
            }
 }
 }//END OF FUNCTION

 void st_peak()
 {
     Node *temp=first;
     if(temp==NULL)
        cout<<"Sorry, Stack is Empty  :) "<<endl;
     else
     {
         cout<<"Peak Of Stack is > "<<temp->getData()<<endl;
     }
 }

int getSize()         ///THIS FUNCTION WILL GIVE THE SIZE
{
    int countr=0;
    Node *temp=first;
    if(temp==NULL)
        cout <<"Sorry, "<<name<<" is Empty >> "<<endl;
    else
    {
    while(temp!=NULL)
    {
        temp=temp->getNextNode();
        countr++;
    }
    }
    return countr;
}//END  OF FUNCTION

void remove_index(int ind)     ///THIS FUNCTION WILL REMOVE THE VALUE , WHICH INDEX IS GIVEN BY USER
{
    if(first == NULL)
        cout <<"Sorry, List is Empty "<<endl;
    else {
    Node *temp=first;
    int i=0;
    if(ind < 0)
        cout <<"Sorry, Wrong Index/Location is given : "<<endl;

    else
        if(ind > getSize())
        cout <<" Sorry, given Index Exceeds the Size of List "<<endl;

    else
        if(ind == 0)
      { first = first->getNextNode();
        first ->setPrev(NONE); }
    else
        if (ind==1)
        { first ->setNextNode(first->getNextNode()->getNextNode());
        first->getNextNode()->setPrev(first); }
    else
    {

        for(i=1; i<ind ; i++)
          {
              temp=temp->getNextNode();
    }
    temp->setNextNode(temp->getNextNode()->getNextNode());
    temp->getNextNode()->setPrev(temp);
    }
    }
}//END OF FUNCTION


void add_at_user_p(int dat, int indx)       ///THIS WILL ADD A NEW NODE AT USER GIVEN POSITION
{
    Node *temp2=new Node(dat);
    Node *temp=first;
    if(indx<0)
        add_at_start(dat);
    else if(indx>getSize())
        add_at_end(dat);
    else if(indx+1==getSize())
        add_at_end(dat);
    else
        {
        for (int i=1; i<indx; i++)
        {
            temp=temp->getNextNode();
        }
        temp2->setNextNode(temp->getNextNode());
        temp->setNextNode(temp2);
        temp2->getNextNode()->setPrev(temp2);
        temp2->setPrev(temp);
    }
}//END OF FUNCTION

void search_data(int dat)        ///THIS IS FOR SEARCHING DATA ON THE BASE OF
{                                ///      GIVEN DATA
    Node *temp=first;
    int co=0,x=0;
    while(temp!=NULL)
    {
        if(temp->getData()==dat)
            co++;
     temp=temp->getNextNode();
    }
    if(co==0)
        cout <<"Sorry, The Given Data is Not Found inThe  "<<name<<endl;
    else
    {
        temp=first;
        while(temp->getData()!= dat)
        {
              temp=temp->getNextNode();
        x++;
         }
        cout <<"The Position Of Given Data In "<<endl<<" is "<<x<<endl;
    }
}//END OF FUNCTION

void show_data(int indxx)        ///THIS WILL SEARCH ON THE BASE OF INDEX
{
    Node *temp=first;
    if(indxx>getSize())
        cout <<"Sorry, the Given index Exceeds the Size of the List "<<endl;
    else if(indxx<0)
        cout <<"Sorry, Given Position is not correct "<<endl;
    else
    {
      for(int i=0; i<indxx; i++)
      {
          temp=temp->getNextNode();
      }
      cout <<"The Data At Given Location is "<<temp->getData()<<endl;
    }

}//END OF FUNCTION


void getlast()             ///Return Last
{
    Node *temp=first;
    if(temp==NULL)
        cout<<"Sorry, Queue is Empty "<<endl;
        else if(temp->getNextNode()==NULL)
        cout<<temp->getData()<<endl;
        else
        {
            while(temp->getNextNode()!=NULL)
            {
                temp=temp->getNextNode();
            }
            cout<<temp->getData()<<endl;
        }
}//END
void getfirst()          ///Return First
{
    Node *temp=first;
    if(temp==NULL)
        cout<<"Sorry, "<<name<<" is Empty "<<endl;
    else
    {
        cout<<first->getData()<<endl;
    }
}//EnD

void reverseTheQueue()
{
   Node *temp=first;
 if(temp==NULL)
    cout<<"Queue is empty "<<endl;
 else if(temp->getNextNode()==NULL)
    cout<<"Only One Node , Cannot be reversed "<<endl;
 else
    {
   while(temp->getNextNode()!=NULL)
   {
       temp=temp->getNextNode();
   }//loop

   first=temp;
   Node *t=temp;
   //first->setPrev(NONE);
while(temp->getPrev()!=NULL)
{
    temp->setNextNode(temp->getPrev());
    temp=temp->getPrev();
}
   temp->setNextNode(NONE);

   Node *t2=first;
   t2->setPrev(NONE);
   Node *t1=first->getNextNode();
  while(t1!=NULL)
  {
      t1->setPrev(t2);
      t2=t1;
      t1=t1->getNextNode();
  }
    }
}//End
};//class End

                /*******************      THIS IS QUEUE CLASS
                *********************     THIS IS QUEUE CLASS
                *********************     THIS IS QUEUE CLASS
                *********************     THIS IS QUEUE CLASS
                ********************/
class Queue
{
public:
    Queue()
    {
        Linked_List();
    }
    Linked_List myList;

   void enqueue(int dat)         ///Enqueue
    {
        myList.add_at_end(dat);
    }//End

   void dequeue()              ///DEQUEUE
    {
        myList.remove_first();
    }//END

    void peak()
    {
        myList.getfirst();
    }//END
    void Back()
    {
        myList.getlast();
    }//END

    void display()
    {
        myList.display_all();
    }//END

    void sizeOfqueue()
    {
       int x = myList.getSize();
       cout<<"The Size of Queue is   :"<<x<<endl;
    }

    void findValue(int val)
    {
        myList.search_data(val);
    }
    void Reverse()
    {
      myList.reverseTheQueue();
    }

};// Class End Here


          /****************************   THIS IS STACK CLASS
          *****************************   THIS IS STACK CLASS
          *****************************   THIS IS STACK CLASS
          ****************************/


class Stack
{
public:
    Stack()
    {
        Linked_List();
    }
    Linked_List mylist;
    Queue myQ;
    void PUSH(int dat)
    {
        mylist.add_at_start(dat);
    }// END Function

    void POP()
    {
        mylist.remove_first();
    }   //END

    void peak()
    {
        mylist.st_peak();
    }

    void sizeofstack()
    {
        int x = mylist.getSize();
        cout<<"The Size of Stack is > "<<x<<endl;
    }
void finder(int dat)
{
    mylist.search_data(dat);
}
void display_()
{
    mylist.display_stack();
}

};   //Class End Here






                /**                Hello this main function
                *
                *                  MAIN FUNCTION START FROM HERE
                *
                **/

int main()
{
    Queue myQueue;
    Stack mystack;
    char ch;
    int choice,dat,user_choice;
cout<<"please Select   >> "<<endl;
cout<<"Enter 1 for Queue OR 2 For Stack IMPLEMENTATION >> :";
cin>>user_choice;
    if(user_choice==1)
    {
        name="Queue";
    do           //do while loop start
    {

    system("CLS");
        cout<<"********************************************"<<endl;
        cout<<"1 For Enqueue            ***"<<endl;
        cout<<"2 For Dequeue            ***"<<endl;
        cout<<"3 For Peak/Front         ***"<<endl;
        cout<<"4 For Back               ***"<<endl;
        cout<<"5 For Display            ***"<<endl;
        cout<<"6 For Size of Queue      ***"<<endl;
        cout<<"7 For Finding value      ***"<<endl;
        cout<<"8 For Reverse the Queue  ***"<<endl;

        cout<<"********************************************"<<endl;
       cout <<"Enter Your Choice : ";
        cin>>choice;

        switch(choice)
        {   case 1:
            cout<<endl<<"Enter the Number To Enqueue "<<endl;
            cin >>dat;
            myQueue.enqueue(dat);
            break;
        case 2:
            myQueue.dequeue();
            break;
        case 3:
            myQueue.peak();
            break;
        case 4:
            myQueue.Back();
            break;
        case 5:
            myQueue.display();
            break;
        case 6:
            myQueue.sizeOfqueue();
            break;
        case 7:
            cout<<"Enter the value you want to find its Index "<<endl;
            cin>>dat;
            myQueue.findValue(dat);
            break;
        case 8:
            myQueue.Reverse();
            break;
            default:
                cout<<"Wrong Choice "<<endl;

        }  //switch End
        cout<<"Do You Want To Continue : (y/n) : ";
        cin>>ch;
        cout <<endl<<endl;
    }
    while(ch!='n');
}
    else if(user_choice==2)
    {
        name="Stack";
     do           //do while loop start
    {

    system("CLS");
        cout<<"********************************************"<<endl;
        cout<<"1 For PUSH               ***"<<endl;
        cout<<"2 For POP                ***"<<endl;
        cout<<"3 For Peak/Top           ***"<<endl;
        cout<<"4 For Display            ***"<<endl;
        cout<<"5 For Size of Stack      ***"<<endl;
        cout<<"6 For Finding value      ***"<<endl;

        cout<<"********************************************"<<endl;
       cout <<"Enter Your Choice : ";
        cin>>choice;

        switch(choice)
        {   case 1:
            cout<<endl<<"Enter the Number To PUSH "<<endl;
            cin >>dat;
            mystack.PUSH(dat);
            break;
        case 2:
            mystack.POP();
            break;
        case 3:
            mystack.peak();
            break;
        case 4:
            mystack.display_();
            break;
        case 5:
            mystack.sizeofstack();
            break;
        case 6:
           cout<<"Enter a Value to Find Its Location "<<endl;
           cin>>dat;
            mystack.finder(dat);
           break;
            default:
                cout<<"Wrong Choice "<<endl;

        }  //switch End
        cout<<"Do You Want To Continue : (y/n) : ";
        cin>>ch;
        cout <<endl<<endl;
    }
    while(ch!='n');
    }
    return 0;
}
