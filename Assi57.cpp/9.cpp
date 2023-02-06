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
    int getSum(int v)
    {
        int s=0;
        while(v!=0)
        {
            s =s+v%10;
            v = v/10;
        }
        return s;
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
    
    void Find_Sum()
    {
        node *temp = head;
        while(temp!=NULL)
        {
            if(getSum(temp->value)% 2 == 0)
            {
                Function_Delete(temp->value);
            }
            
            temp= temp->next;
        }
    }
    int Search(int v)
    {
        node *temp = head;
        int c=0;
        while(temp!=NULL)
        {
            c++;
            if(temp->value == v)
                break;
            temp= temp->next;
        }
        return c;
    }
    
    void Function_Delete(int v)
    {
        int n = Search(v);
        node *t = head;
        if(n == 1)
        {
            head = head->next;
            head ->pre = NULL;
            delete t;
        }
        else {
            while(n>2)
            {
                n--;
                if(t->next!=NULL)
                t= t->next;

            }
           node *r = t->next;
           t->next = r->next;
           r->next->pre = t;
           delete r;     
        }
    }
    
};
int main()
{
    Double_list d;
    d.insert_Element(8);
    d.insert_Element(22);
    d.insert_Element(16);
    d.insert_Element(29);
    d.Find_Sum();
    d.Print();

}
