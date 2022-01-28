#include<stdlib.h>
#include<iostream>
#include <math.h>
using namespace std;

class ELEMAN
{
	public:
		int data;
		ELEMAN* right;
		ELEMAN* left;
		ELEMAN()
		{
			data=0;
			right=NULL;
			left=NULL;
		};
		ELEMAN(int x)
		{
			data=x;
			right=NULL;
			left=NULL;
		};		
};


class AGAC
{
	private:
		ELEMAN* root;
		ELEMAN* _eleman_ekle(int x,ELEMAN* r);/*BU*/
		void _in_yaz(ELEMAN* r);/*BU*/
		int _elsay(ELEMAN* r);
		int _minimum(ELEMAN* r);
		ELEMAN* _delete_key(int x,ELEMAN* r);
	    int _yukseklik(int x,ELEMAN* r);/*BU*/
	    int _agac_yuksekligi(ELEMAN* r);
	public:
		Tree()
		{
			root=NULL;
		};
	    void eleman_ekle(int x);/*BU*/
		void in_yaz();/*BU*/
		int elsay();/*BU*/
		int minimum();
		void delete_key(int x);	
		int yukseklik(int x);
		int agac_yuksekligi();/*BU*/
		bool bosmu();/*BU*/
		bool yaprak();
};

bool AGAC::bosmu()
{
	if(root==NULL)
	    return true;
	return false;
}

bool AGAC::yaprak()
{
	if(root!=NULL&&root->left==NULL&&root->right==NULL)
	    return true;
	return false;
}

void AGAC::eleman_ekle(int x)
{
	root= _eleman_ekle(x,root);
}

ELEMAN* AGAC::_eleman_ekle(int x,ELEMAN *r)
{
	if(r==NULL)
	{
		ELEMAN* yeni=new ELEMAN(x);
		return yeni;
	}
	else
	{
		if(x>r->data)
		{
			r->right= _eleman_ekle(x,r->right);
		}
		else
		{
			r->left= _eleman_ekle(x,r->left);
		}
	}
	return r;	
}

void AGAC::in_yaz()
{
	_in_yaz(root);	
}

void AGAC::_in_yaz(ELEMAN *r)
{
	if(r==NULL)
	    return;
	else
	{
		_in_yaz(r->left);
		printf("%d ",r->data);
		_in_yaz(r->right);
	}
}

int AGAC::elsay()
{
	return _elsay(root);
}

int AGAC::_elsay(ELEMAN* r)
{
	if (r==NULL)
        return 0;
	else
	    return 1+_elsay(r->right)+_elsay(r->left);
}

int AGAC::minimum()
{
	return _minimum(root);
}

int AGAC::_minimum(ELEMAN* r)
{
	if(r==NULL)
	    return 10000;
	else 
    {
    	ELEMAN* temp=r;
    	while(temp->left!=NULL)
    	{
    		temp=temp->left;
		}
		return temp->data;
	}
}


void AGAC::delete_key(int x)
{
	root=_delete_key(x,root);
}

ELEMAN* AGAC::_delete_key(int x,ELEMAN* r)
{
	if(r==NULL)
	    return NULL;
	if(x>r->data)
	    r->right=_delete_key(x,r->right);
	else if(x<r->data)
	    r->left=_delete_key(x,r->left);
	else
	{
		if(r->right==NULL)
		{
			ELEMAN* temp=r->left;
			delete(r);
			return temp;
		}
		else if(r->left==NULL)
		{
			ELEMAN* temp=r->right;
			delete(r);
			return temp;
		}
		else
		{
			int minimum_value=_minimum(r->right);
			r->data=minimum_value;
			r->right=_delete_key(minimum_value,r->right);
		}
	}
	return r;
}

int AGAC::agac_yuksekligi()
{
	return _agac_yuksekligi(root);
}

int AGAC::_agac_yuksekligi(ELEMAN* r)
{
	if(r==NULL)
	    return -1;
	else
    	return 1+max(_agac_yuksekligi(r->left),_agac_yuksekligi(r->right));
}




int main()
{
	AGAC agac;
/*	agac.eleman_ekle(27);
    agac.eleman_ekle(1);
    agac.eleman_ekle(33);
    agac.eleman_ekle(45);
    agac.eleman_ekle(43);
    agac.eleman_ekle(46);
    agac.eleman_ekle(32);
    agac.eleman_ekle(37);
    agac.eleman_ekle(4);
    agac.eleman_ekle(17);
    agac.eleman_ekle(40);
    agac.eleman_ekle(7);
    agac.eleman_ekle(12);
    agac.eleman_ekle(22);
    agac.eleman_ekle(8);
	agac.in_yaz();
	cout<<endl;*/

  for(int i = 1; i < 21; i++){
 /*   cout << rand()%50+150 << endl;*/
    agac.eleman_ekle(rand()%50+150);/*150 200 arasýnda*/
  }
  agac.in_yaz();

}







