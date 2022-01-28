#include<stdlib.h>
#include<iostream>

using namespace std;
class Node
{
	public:
		int data;
		Node* next;
		
		Node()
		{
			data=0;
		}
		Node(int x)
		{
			data=x;
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
		void basa_ekle(int x);
		void sona_ekle(int x);
		void araya_ekle(int x,int sira);
		void sirali_ekle(int x);
		void listele();
		void bastan_sil();
		bool bos_mu();
		void sondan_sil();
		void aradan_sil(int sira);
		void sil(int x);
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

void List::basa_ekle(int x)
{
	Node* eleman=new Node(x);
	eleman->next=head;
	head=eleman;
}

void List::sona_ekle(int x)
{
	if(head==NULL)
	{
	basa_ekle(x);
    }
	else
	{
		Node* temp=head;
		while(temp->next != NULL)
		{
			temp=temp->next;
		}
		Node* eleman=new Node(x);
		eleman->next=NULL;
		temp->next=eleman;
	}
}

void List::araya_ekle(int x,int sira)
{
	if(sira==1)
    	basa_ekle(x);
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
			 	Node* eleman=new Node(x);
			 	eleman->next=temp->next;
			 	temp->next=eleman;
			 }
	         else
	         {
	         	sona_ekle(x);/*öyþe bir sýra yok yazdýrýlabilir*/
			 }
        }
}

void List::sirali_ekle(int x)
{
	if(bos_mu()||head->data >x)
	{
		basa_ekle(x);
	}
	else
	{
		Node* temp=head;
		while(temp->next!=NULL && temp->next->data< x)
		{
			temp=temp->next;
		}
		Node* eleman=new Node(x);
		eleman->next=temp->next;
		temp->next=eleman;
	}
}

void List::listele()
{
	if(head!=NULL)
	{
		Node* temp=head;
    	while(temp!=NULL)	 
    	{
    		cout<<temp->data<<" ";
    		temp=temp->next;
		}
	}
}

void List::bastan_sil()
{
	Node* temp=head;
	head=head->next;;
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

void List::sil(int x)
{
	if(head->data==x)
	{
		bastan_sil();
	}
	else
	{
		Node* temp=head;
		while(temp->next!=NULL&&temp->next->data!=x)
		{
			temp=temp->next;
		}
		if(temp->next->data==x)
		{
			Node* silinecek=temp->next;
			temp->next=temp->next->next;
			delete silinecek;
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
     		delete silinecek;
		}
		else
		cout<<"listede öyle bir sira yok.";
    }      
	
}



int main()
{
	List liste;
    liste.basa_ekle(5);
    liste.basa_ekle(7);
    liste.basa_ekle(45);
    liste.basa_ekle(54);
    liste.listele();
    cout<<endl;
    liste.aradan_sil(2);
    liste.listele();
    cout<<endl;
    liste.kac_tane();
}

