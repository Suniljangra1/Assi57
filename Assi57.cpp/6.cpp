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
    node* find_Mid()
    {
         node *slow=head,*fast=head->next;
         while(fast!=NULL && fast->next!=NULL)
         {
            slow =slow->next;
            fast = fast->next->next;
         }
         return slow;
    }
    void Sorting()
    {
        node *i,*j;
        node *mid = find_Mid();
        for(i=head; i->next!=mid->next; i=i->next)
        {
            for(j=i->next; j!=mid->next; j=j->next)
            {
                if(i->value > j->value)
                {
                    int temp = i->value;
                    i->value = j->value;
                    j->value = temp;
                }
            }
        }
         for(i=mid; i->next!=NULL; i=i->next)
        {
            for(j=i->next; j!=NULL; j=j->next)
            {
                if(i->value < j->value)
                {
                    int temp = i->value;
                    i->value = j->value;
                    j->value = temp;
                }
            }
        }
        
    }
    void Print()
    {
        node *s = head;
        // this->Sorting();
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
    d.insert_Element(8);
    d.insert_Element(17);
    d.insert_Element(6);
    d.insert_Element(5);
    d.insert_Element(1);
    d.insert_Element(4);
    d.insert_Element(3);
    d.insert_Element(2);
    d.Sorting();
    d.Print();
   

}