#include<stdlib.h>
#include<iostream>

using namespace std;
class Node
{
	public:
		int koordinatx;
		int koordinaty;

		Node* next;
		Node* onceki;
		
		Node()
		{
			koordinatx=0;
			koordinaty=0;
		}
		Node(int x,int y)
		{
			koordinatx=x;
			koordinaty=y;
		}
};

class List
{
	private:
		Node* head;
	public:
		List()
		{
			head= NULL;	
		}
		void basa_ekle(int x,int y);
		void sona_ekle(int x,int y);
		void araya_ekle(int x,int y,int sira);
		void sirali_ekle(int x,int y);
		void listele();
		void bastan_sil();
		bool bos_mu();
		void sondan_sil();
		void aradan_sil(int sira);/*istenilen sýradakini siler*/
		void sil(int x,int y);/*istenilen sayýyý siler*/
		int kac_tane();
};
bool List::bos_mu()
{
	if(head==NULL)
	     return true;
    return false;
}

int List::kac_tane()
{
	int sayac=1;
	Node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		sayac=sayac+1;
	}
	cout<<sayac<<endl;
}

void List::basa_ekle(int x,int y)
{
	Node* eleman=new Node(x,y);
	eleman->next=head;
	eleman->onceki=NULL;
	if(eleman->next!=NULL)
    	eleman->next->onceki=eleman;
	head=eleman;
}

void List::sona_ekle(int x,int y)
{
	if(head==NULL)
	{
	basa_ekle(x,y);
    }
	else
	{
		Node* temp=head;
		while(temp->next != NULL)
		{
			temp=temp->next;
		}
		Node* eleman=new Node(x,y);
		eleman->next=NULL;
		temp->next=eleman;
		eleman->onceki=temp;
	}
}

void List::araya_ekle(int x,int y,int sira)
{
	if(sira==1)
    	basa_ekle(x,y);
    else
    	{
    		
	         Node* temp=head;
	         int i=1;
	         while(i<sira-1&&temp->next!=NULL)
	         {
	         	temp=temp->next;
	         	i=i+1;
			 }
			 if(i=sira-1)
			 {
			 	Node* eleman=new Node(x,y);
			 	eleman->next=temp->next;
			 	temp->next=eleman;
			 	eleman->onceki=temp;
			 	eleman->next->onceki=eleman;
			 }
	         else
	         {
	         	sona_ekle(x,y);/*öyþe bir sýra yok yazdýrýlabilir*/
			 }
        }
}

void List::sirali_ekle(int x,int y)
{
	if(bos_mu()||head->koordinatx >x)
	{
		basa_ekle(x,y);
	}
	else
	{
		Node* temp=head;
		while(temp->next!=NULL && temp->next->koordinatx< x)
		{
			temp=temp->next;
		}
		Node* eleman=new Node(x,y);
		eleman->next=temp->next;
		temp->next=eleman;
		eleman->onceki=temp;
		eleman->next->onceki=eleman;
	}
}

void List::listele()
{
	if(head!=NULL)
	{
		Node* temp=head;
    	while(temp!=NULL)	 
    	{
    		cout<<temp->koordinatx<<","<<temp->koordinaty<<" ";
    		temp=temp->next;
		}
	}
}

void List::bastan_sil()
{
	Node* temp=head;
	head=head->next;
	head->onceki=NULL;
	head->next->onceki=head;
	delete temp;
}

void List::sondan_sil()
{
	if(head==NULL)
	{
		cout<<"Liste bos";
	}
	else if(head->next==NULL)
	{
		head=NULL;/*bastan_sil*/
	}
	else
	{
    	Node* temp=head;
    	while(temp->next->next!=NULL)
    	{
    		temp=temp->next;
		}
    delete temp->next;
    temp->next=NULL;
	}
}

void List::sil(int x,int y)
{
	if(head->koordinatx==x&&head->koordinaty==y)
	{
		bastan_sil();
	}
	else
	{
		Node* temp=head;
		while(temp->next!=NULL&&temp->next->koordinatx!=x&&temp->next->koordinaty!=y)
		{
			temp=temp->next;
		}
		if(temp->next->koordinatx==x&&temp->next->koordinaty==y)
		{
			Node* silinecek=temp->next;
			temp->next=temp->next->next;
			delete silinecek;
			temp->next->onceki=temp;
		}
		else
		{
			cout<<"Aranan eleman bulunamadý";
		}
	}
}

void List::aradan_sil(int sira)
{
	if(bos_mu())
	{
		cout<<"Listede eleman yok";
	}
	else if(sira==1)
    	bastan_sil();
	
	else
	{
		Node* temp=head;
		int i=1;
    	while(i<sira-1&&temp->next!=NULL)
	    {
	    	temp=temp->next;
	    	i=i+1;
     	}
     	if(i==sira-1)
     	{
     		Node* silinecek=temp->next;
     		temp->next=silinecek->next;
     		temp->next->onceki=temp;
     		delete silinecek;
		}
		else
		cout<<"listede öyle bir sira yok.";
    }      
	
}



int main()
{
	List liste;
    liste.basa_ekle(5,4);
    liste.basa_ekle(7,7);
    liste.basa_ekle(45,8);
    liste.basa_ekle(54,5);
    liste.listele();
    cout<<endl;
    liste.aradan_sil(2);
    liste.listele();
    cout<<endl;
    liste.kac_tane();
}

