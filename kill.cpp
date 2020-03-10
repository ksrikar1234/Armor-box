#include<iostream>
#include<cmath>
using namespace std;
//-----------------------------------------
class Data{
class NODE
{
public:
  unsigned int index  ;
  bool state = true;
  NODE* next;
};
//------------------------------------------
class circular_array //: public NODE
{
public:
  NODE *circle;
  circular_array(int x = 6)
  {
   circle = new NODE[x];
   circle[x-1].next = &circle[0];
   for(int i = 0; i < x-1 ; i++)
      {
        circle[i].index = i+1;
        circle[i].next = &circle[i+1];
      }
  }
  void kill_next_guy(NODE* x)
  {
    (x->next)->state = false;
    (x->next) = ((x->next)->next);
  }

  void shift(NODE* x , int k)
  {
   for(int i = 0 ; i < k ; i++)
     (x->next) = ((x->next)->next);
  }
//---------------------------------------------------------------------------------------------
  void auto_spaced_number(int number , int size_of_block = 9)
     {
       float count = 0; int num = number;
       if((size_of_block)%2 == 0) ++size_of_block;
       while(num)
       {
         count += 1; num = num/10;
       }
        for(int i = 0; i < ceil((size_of_block-count)/2); ++i)
           {
             cout <<" ";
           }
             cout << number;
          for(int i = 0; i < floor((size_of_block-count)/2) ; ++i)
              {
                cout <<" ";
              }
    }
//------------------------------------------------------------------------------------
 void print(int n)
 {
   static unsigned int round = 0;
    cout << "\t\t ROUND" ;
    auto_spaced_number(round++ , 4);
    cout << "----> ";
    for(int i = 0 ; i < n; i++)
    {
      circle[i].state ? cout << "1": cout << "0";
    }
     cout << endl;
 }
};
//------------------------------------------------------------------------------------
int main()
{
  int n ,k;
  NODE *head ;
  system("clear");
  cin >> n >> k;
    circular_array a(n);
    head->state =  (a.circle[0]).state;
    head->next  = &(a.circle[0]);
    cout << "      initial states of individual persons" << endl;
    a.print(n);
    cout << "      Starting execution" <<endl;
    while(head->next != (head->next)->next)
      {
         a.shift(head , k-1);
          if(((head->next)->next)->state)
            {
                a.kill_next_guy(head->next);
            }
            a.print(n);
      }
  cout << "survivor is " << ((head->next))->index;
return 0;
}
