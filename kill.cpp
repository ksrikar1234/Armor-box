#include<iostream>
using namespace std;
class NODE
{
public:
  bool state = true;
  NODE* next;
};

class circular_array
{
public:
  NODE *circle;
  circular_array(int x = 6)
  {
   circle = new NODE[x];
   circle[x-1].next = &circle[0];
   for(int i = 0; i < x-1 ; i++)
      {
        circle[i].next = &circle[i+1];
      }
  }
  void kill_next_guy(NODE* x)
  {
    x->next = (x->next)->next;
  }

  void shift(NODE* x , int k)
  {



  }
  void print_help()
  {
   cout << "name of circular_array node is circle . \n call using object.circle";
  }

};

int main()
{
  int n ,k;
  NODE *head;
  cin >> n >> k;
    circular_array a(n);
    head->state =  (a.circle[0]).state;
    head->next  = &(a.circle[0]);
    bool go_flag = true;

  while(go_flag)
      {
         go_flag = false;
         a.shift(head->next , k-1);
          if(((head->next)->next)->state)
            {
              go_flag = true;
              a.kill_next_guy(head->next);
            }
      }




}
