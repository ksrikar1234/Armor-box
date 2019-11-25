#include<iostream>
#include<string>
using namespace std;
class neural_node
{
public:
   string         meta_data;
   neural_node*   upper_node;
   neural_node*   right_node;
   neural_node*   lower_node;
   neural_node*   left_node;
};
class core_base_constructor
{
protected:
    neural_node    core;
    neural_node*   base_shell;
public:
    core_base_constructor()
    {
           const short x = 4;
           static int  c = 0;
           base_shell = new neural_node[x];
           cout << "constructing and locking the core and base shell " << ++c << endl;
      //+-------------------------------------------------------------------------+

           core.upper_node = &base_shell[0]; base_shell[0].lower_node = &core;
           core.right_node = &base_shell[1]; base_shell[1].left_node  = &core;
           core.lower_node = &base_shell[2]; base_shell[2].upper_node = &core;
           core.left_node  = &base_shell[3]; base_shell[3].right_node = &core;

      //+-----------------CONNECT BASE SHELL NODE-ELEMENTS INTERNALLY-------------+

       for (short i = 0 ; i < x ; ++i)
            {
               (i == x-1) ? base_shell[i].right_node = &base_shell[0]   : base_shell[i].right_node = &base_shell[i+1];
               (i == 0)   ? base_shell[i].left_node  = &base_shell[x-1] : base_shell[i].left_node  = &base_shell[i-1];
            }
           cout << "core and base shell construction completed " << endl;
           core.meta_data  = "Now u are at core node";
           cout << core.meta_data << endl;
           base_shell[1].meta_data = "Hello world";
           cout << endl << base_shell[1].meta_data;
           (base_shell[3].left_node)->meta_data = "i am previous";
           cout << (base_shell[3].left_node)->meta_data;
      }
};
class allocate: protected core_base_constructor
{
public:
   neural_node    shell[4];
   neural_node*   node;
   const short x   = 4;
   //shell = new neural_node[x];
   allocate()
   {
    for(short i = 0 ; i < x ; ++i)
        {
           (i == x-1) ? shell[i].right_node = &shell[0]   : shell[i].right_node = &shell[i+1];
           (i == 0)   ? shell[i].left_node  = &shell[x-1] : shell[i].left_node  = &shell[i-1];
        }

                   base_shell[0].upper_node = &shell[0]; shell[0].lower_node = &base_shell[0];
                   base_shell[1].right_node = &shell[1]; shell[1].left_node  = &base_shell[1];
                   base_shell[2].lower_node = &shell[2]; shell[2].upper_node = &base_shell[2];
                   base_shell[3].left_node  = &shell[3]; shell[3].right_node = &base_shell[3];
    }

};
int main()
{
 core_base_constructor a;
 return 0;
}
