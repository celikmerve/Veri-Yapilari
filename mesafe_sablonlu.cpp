#include<stdlib.h>
#include<iostream>
#include <math.h>
using namespace std;
template <class type> 
class node

{
	public:
		type data1,data2;
		node* next;
		
		node()
		{
			data1=1;
			data2=1;
		}
		node(type const&x=type(),type const&y=type())
		{
			data1=x;
			data2= y;
		}
};
template<class type>
class List

{
	private:
		node<type> * head;
	public:
		
		List()
		{
			node<type>* head;
			head= NULL;	
		}
     	type mesafe(type p1,type p2);
     	type k_ekleme(type x, type y);
     	type yaz();
};



template<class type>
type List <type>::mesafe(type p1,type p2)
{
	cout<< sqrt(((p1 - head->data1)*(p1 - head->data1))+((p2 - head->data2)*(p2 - head->data2)));
	cout<<endl;
}

template<class type>
type List <type>::k_ekleme(type x,type y)
{
	node<type>*eleman=new node<type>(x,y);
	eleman->next=head;
	head=eleman;
	
}

template<class type>
type List <type>::yaz()
{
	cout<<"nesne="<<"("<<head->data1<<","<<head->data2<<")"<<endl;
}


int main()
{
	List <double>k;
    k.k_ekleme(1,2);
	k.yaz();
	k.mesafe(1,2);

}
