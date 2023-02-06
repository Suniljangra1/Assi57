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
    node(int v)
    {
        value = v;
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
    void Print()
    {
        node *s = head;
        while(s!=NULL)
        {
            cout<<s->value<<" <=> ";
            s = s->next;
        }
    }
    void Rotate_list(int n)
    {
        node *s = head;
        node *temp= head;
       
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        while(n>=1)
        {
            n--; 
            head = head->next;
            head->pre = NULL;
            insert_Element(s->value);
            s=s->next;
        }  
    }
};
int main()
{
    Double_list d;
    d.insert_Element(8);
    d.insert_Element(17);
    d.insert_Element(6);
    d.insert_Element(5);
    d.insert_Element(1);
    d.insert_Element(4);
    d.insert_Element(3);
    d.insert_Element(2);
    d.Rotate_list(3);

   d.Print();

}