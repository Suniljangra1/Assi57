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
    void find_sum(int x)
    { 
        node *slow= head;
        node *fast= head;
        node *temp = head;
        
        while(fast->next!=NULL)
        {
          fast=fast->next;
        }
    while(fast!=NULL){
        while( slow!=NULL)
        {
             int p = slow->value;
             int r = fast->value;
             int n = r+p;
            //  cout<<" "<<n;
            if(n == x){
                   cout<<slow->value<<" -> "<<fast->value<<endl;
                   slow = slow->next;
                }      
             fast = fast->pre;   
        }
         slow = slow->next;
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
    d.insert_Element(4);
    d.insert_Element(5);
    d.insert_Element(6);
    d.insert_Element(7);
    d.insert_Element(8);
    d.find_sum(7);
    // d.Print();
}