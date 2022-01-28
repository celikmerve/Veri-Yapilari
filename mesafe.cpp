#include<stdlib.h>
#include<iostream>
#include <math.h>
using namespace std;
class node
{
	public:
		int data1,data2;
		node* next;
		
		node()
		{
			data1=0;
			data2=0;
		}
		node(int x,int y):data1(1),data2(1)
		{
			data1=x;
			data2=y;
		}
};

class List
{
	private:
		node* head;
	public:
		
		List()
		{
			head= NULL;	
		}
		
     	int mesafe(int p1,int p2);
     	void k_ekleme(int x, int y);
     	void yaz();
};

int List::mesafe(int p1,int p2)
{
	cout<< sqrt(((p1 - head->data1)*(p1 - head->data1))+((p2 - head->data2)*(p2 - head->data2)));
	cout<<endl;
}

void List::k_ekleme(int x,int y)
{
	node* eleman=new node(x,y);
	eleman->next=head;
	head=eleman;
	
}

void List::yaz()
{
	cout<<"nesne="<<"("<<head->data1<<","<<head->data2<<")"<<endl;
}

int main()
{
	List liste;
	liste.k_ekleme(1,2);
	liste.yaz();
	liste.mesafe(2,3);

}







