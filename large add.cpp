#include<iostream>
using namespace std;
int main()
{
	const int N = 100;
	int num1[N+10],num2[N+10],num3[N+10];
	char n1[N+20],n2[N+20],n3[N+20];
	int i,j,n;
	int x;
	for(int p =0; p < N+10 ;++p)
	{   
	    num1[p] = 0;
	    num2[p] = 0;
		num3[p] = 0;	
	}
	cout << "Enter the value of n1 :";
	cin >> n1;
	cout << "Enter the value of n2 :";
	cin >> n2;
	
	cout << n1 << endl;
	
	for(i = 0;  n1[i]!='\0'; ++i) 
       {
       	 bool flag1 = false;
       	 x = n1[i];
       	if(x-48<=9 && x-48>=0 )
	     {
		 num1[i] = x - 48;
		
		  flag1 = true;
	     }
	     if(!flag1){  --i;  }
	   }
	    for( n =0 ; n<i; ++n)
	   {
	   	cout<<num1[n];
	   }
	   cout << endl;
 
	for(j = 0;  n2[j]!='\0'; ++j) 
       {
       	bool flag2 = false;
       	x = n2[j];
       	if( x-48<=9 && x-48>=0)
	     {
		 num2[j] = x - 48;
		 flag2 = true;
	     }
	     if(!flag2){  --j;  }
	   }
	     for( n =0 ; n<j; ++n)
	   {
	   	cout<<num2[n];
	   }
	   cout <<endl;
	   //+-----------------------------------------algorithm-----------------------------------------+
	   int t1 = i+5 ;//int t2 = j+5;
	   cout << "heloo "<<t1;
	   
	   for(int k = i ; k>=0 ; --k)
	   {
	     	    if(num3[t1]+num1[k]+num2[k]<10)
	      	       {
					 num3[t1] = num3[t1] + num1[k] + num2[k]; ++t1;
	   	           }
				  else
	   	          {
	   	            num3[t1] = num3[t1] + num1[k] + num2[k]-10;
		   	        num3[t1-1] = num3[t1-1]+1; ++t1;
	   	          }
	   }
	   for(n =0 ; n<=i+5; ++n)
	   {
	   	cout<<num3[n];
	   }
    return 0;	   
}
