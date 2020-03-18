#include<iostream>
#include<cmath>
using namespace std;
//-----------------------------------------
class DATA
{
  public:
  bool state = true;
};
class NODE: public DATA
{
public:
  unsigned int index  ;
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
     circle[x-1].index = x;
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
       if(num==0) ++num;
       while(num)
            {
             count += 1; num = num/10;
            }
         for(int i = 0; i < ceil((size_of_block-count)/2); ++i)
           {
             cout <<" ";
           }
           if(number+1) cout << number;
           else cout <<" ";
          for(int i = 0; i < floor((size_of_block-count)/2) ; ++i)
              {
                cout <<" ";
              }
    }
//------------------------------------------------------------------------------------
 void print(int n)
 {
    static unsigned int round = 0;
    if(!(round))
     {
       cout << " INDEX     ----> ";
       for(int i = 0 ; i < n ; i++)
          auto_spaced_number(i+1 , 5);
       cout << endl << endl;
     }

    cout << " ROUND" ;
    auto_spaced_number(round++ , 5);
    cout << "----> ";
    for(int i = 0 ; i < n; i++)
    {
      circle[i].state ? auto_spaced_number(1 , 5): auto_spaced_number(-1,5);
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
    system("clear");
    cout << " initial states of individual persons" << endl;
    a.print(n);
    cout << " Starting execution" << endl;
    while(head->next != (head->next)->next)
         {
           a.print(n);
           a.shift(head , k-1);
           a.kill_next_guy(head->next);
         }
    cout << "survivor is " << (head->next)->index;
    return 0;
}
