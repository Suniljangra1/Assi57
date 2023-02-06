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
    node *head1;
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
    void insert_Element_for_Head_1(int v)
    {
        node *temp = new node();
        temp->value =v;
        if(head == NULL)
        {
            head1 = temp;
        }
        else {
           node *s = head1;
           while(s->next!=NULL)
           {
             s= s->next;
           }
           s->next = temp;
           temp->pre = s;
        }
    }
   
    // void Clon_()
    // {
    //     node *temp=head;
    //     int count=0;
    //     while(temp->next!=NULL)
    //     {
    //         insert_Element_for_Head_1(temp->value);
    //         temp=temp->next;
    //         count++;
    //     }
    //     cout<<count;
    // }
   
    void Print()
    {
        node *s = head;
        while(s!= NULL)
        {
            cout<<s->value<<" <=> ";
            insert_Element_for_Head_1(s->value);
            s = s->next;
        }
    }
    void Print_head1()
    {
        node *s = head1;
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
    d.insert_Element(9);
    d.insert_Element(7);
    d.insert_Element(3);
    d.insert_Element(6);
    d.insert_Element(15);
    d.Print();
    cout<<"\n--------------------------------------------------------\n";
    // d.Clon_();
    d.Print_head1();
}