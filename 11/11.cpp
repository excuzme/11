// ֳכאגםûי DLL-פאיכ.

#include "11.h"
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
using namespace std;
class tree
{
int value; 
tree *left, *right; 
static tree* create(int *begin, int *end, int *min, int *max) 
{
int count=end-begin; 
if(count<0) 
return 0; 
int n=count/2; 
int *mid=begin+n;
tree *t=new tree(*mid); 
if(mid!=min) 
{
t->left=create(begin, mid-1, min, max);
}
if(mid!=max) 
{
t->right=create(mid+1, end, min, max);
}
return t;
}
void out(char* str) 
{
if (left) 
{
char *s=new char[strlen(str)+3];
strcpy(s, str);
strcat(s, " "); 
left->out(s); 
delete []s;
}
cout << str << value << endl; 
if (right) 
{
char *s=new char[strlen(str)+3];
strcpy(s, str);
strcat(s, " ");
right->out(s);
delete []s;
}
}
public:
tree(int val) 
{
value=val;
left=0;
right=0;
}
static tree* create(int* begin, int* end) 
{
return create(begin, end, begin, end);
}
void out()
{
out("");
}
};
int *array; 
tree* tr; 


int main() 
{
int len, a; 
cout<<"Enter the number of elements: ";
cin>>len;
array=new int[len];
for(int i=0;i<len;i++) 
{
cout<<"Enter the value of element #"<<i+1<<": ";
cin>>array[i];
}
tr=tree::create(array, array+len-1);
tr->out(); 
delete tr; 
cout<<"Enter delete elem:"<<endl;
cin>>a; 
for(int i=0;i<len;i++)
{
if(array[i]==a) 
array[i]=0;
}
cout<<"Tree without this elem "<<a<<":"<<endl;
tr=tree::create(array, array+len-1);
tr->out();
getch();
delete[] array;
system("pause");
}
