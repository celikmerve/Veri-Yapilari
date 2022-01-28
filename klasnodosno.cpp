#include<stdlib.h>
#include<iostream>

using namespace std;
class DOS_SIS_
{
	public:
		long int klas_no;
		long int dos_no;
		DOS_SIS_* Adres;
		
		DOS_SIS_()
		{
			klas_no=1;
			dos_no=1;
		}
		
		DOS_SIS_(int x,int y):klas_no(1),dos_no(1)
		{
			klas_no=x;
			dos_no=y;
		}
	
};

class Liste
{
	private:
		DOS_SIS_* head;
	public:
		List()
		{
			head= NULL;	
		}
		
		bool bosmu();
     	void basa_ekle(int X,int y);
     	void sona_ekle(int x,int y);
     	void listele();
};

bool Liste::bosmu()
{
	if(head==NULL)
	     return true;
    return false;
}
     	
     	
void Liste::basa_ekle(int x,int y)
{
	DOS_SIS_* eleman=new DOS_SIS_(x,y);
	eleman->Adres=head;
	head=eleman;
}

void Liste::sona_ekle(int x,int y)
{
	if(head==NULL)
	{
	basa_ekle(x,y);
    }
	else
	{
		DOS_SIS_* temp=head;
		while(temp->Adres!= NULL)
		{
			temp=temp->Adres;
		}
		DOS_SIS_* eleman=new DOS_SIS_();
		eleman->Adres=NULL;
		temp->Adres=eleman;
	}
}

void Liste::listele()
{
	if(head!=NULL)
	{
		DOS_SIS_* temp=head;
    	while(temp!=NULL)	 
    	{
    		cout<<temp->dos_no<<" ";
    		temp=temp->Adres;
		}
	}
}  	



int main()
{
	Liste lis1;
		
		lis1.basa_ekle(1,203);
		lis1.basa_ekle(1,202);
		lis1.basa_ekle(1,201);
		lis1.listele();
	
	}
	   	     	
     	
     	
     	
     	
     	
     	
     	
     	
     	
     	
