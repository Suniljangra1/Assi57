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
   int Fabbinic(int n)
   {
     int a =0;
     int b =1;
     if(a==n || b==n)
     return 1;
     int c = a+b;
     while(c<=n)
     {
        if(c == n)
        return 1;
        a = b;
        b = c;
        c = a+b;
     }
     return 0;
   }
   void Remove_Fib()
   {
     node *t = head;
     while(t->next!=NULL)
     {
        if(Fabbinic(t->value))
        {
            Function_Delete(t->value);
        }
        t= t->next;
     }
   }
};
int main()
{
    Double_list d;
    d.insert_Element(5);
    d.insert_Element(3);
    d.insert_Element(4);
    d.insert_Element(2);
    d.insert_Element(9);
    d.Remove_Fib();
    d.Print();

}