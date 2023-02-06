#include<iostream>
using namespace std;
class node
{
    public:
    int value;
    node *pre;
    node *next;
    node()
    {
        value = 0;
        pre = NULL;
        next = NULL;
    }

};
class Double_list
{
    node *head;
   
    public:
    Double_list()
    {
        head = NULL;
    }
    void insert_Element(int v)
    {
        node *temp = new node();
        temp->value =v;
        if(head == NULL)
        {
            head = temp;
        }
        else {
            
           node *s = head;
           while(s->next!=NULL)
           {
             s= s->next;
           }
           s->next = temp;
           temp->pre = s; 
        }
    }
    void Delete_middle(int n)
    {
        node *temp = head;
        if(n == 1)
        {
            temp= temp->next;
            temp->pre = NULL;
            head = temp;
        }
        else {
            while(n>1)
            {
                n--;
                if(temp->next!=NULL)
                temp = temp->next;
            }
            
            temp->pre->next= temp->next;
            temp->next = temp->pre;
        }
    }
     void duplicate()
     {
        node *temp = head;
        while(temp->next!=NULL)
        {
          
            if(temp->value == temp->next->value)
            {
                temp->pre->next= temp->next;
                temp->next = temp->pre;
            }
            // else
            temp=temp->next;
        }
     }
    void Print()
    {
        node *s = head;
        while(s!= NULL)
        {
            cout<<s->value<<" <=> ";
            s = s->next;
        }
    }
};
int main()
{
    Double_list d;
    d.insert_Element(1);
    
    d.insert_Element(2);
    d.insert_Element(3);
    d.insert_Element(3);
    d.insert_Element(5);
    d.insert_Element(22);
    d.insert_Element(22);
    
    d.duplicate();
    d.Print();

}