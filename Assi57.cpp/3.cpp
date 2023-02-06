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
    void sort_element(node *head)
    {
        node *s = head;
        node *r=head;
        while(r!=NULL)
        {
            while(s->next!=NULL)
            {
                if(s->value > s->next->value)
                {
                    int t = s->value;
                    s->value = s->next->value;
                    s->next->value = t;
                }
                s=s->next;
            }
            r=r->next;
        }
    }  
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
        sort_element(head);
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
    
    d.insert_Element(7);
    d.insert_Element(5);
    d.insert_Element(6);
    d.insert_Element(7);
    d.insert_Element(222);
    d.insert_Element(99);
    d.Print();
    // d.Print();

}