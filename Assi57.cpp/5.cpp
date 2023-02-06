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
    
   void remove_duplicates() {
    node *s, *temp, *t;
    s = head;
   
    while (s->next != NULL) {
        temp = s;
        while (temp->next != NULL) {
            
            if (s->value == temp->next->value) {
                t = temp->next;
                temp->next = temp->next->next;
                delete (t);
            } else
                temp = temp->next;
        }
        s = s->next;
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
    d.insert_Element(3);
    d.insert_Element(3);
    d.insert_Element(5);
    d.insert_Element(3);
    d.insert_Element(22);
    d.remove_duplicates();
    d.Print();

}