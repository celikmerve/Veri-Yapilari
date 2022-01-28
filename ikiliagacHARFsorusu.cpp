#include<stdlib.h>
#include<iostream>
#include <math.h>
using namespace std;

class ELEMAN
{
	public:
		char data;
		ELEMAN* right;
		ELEMAN* left;
		ELEMAN()
		{
			data=' ';
			right=NULL;
			left=NULL;
		};
		ELEMAN(char x)
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
		ELEMAN* _eleman_ekle(char x,ELEMAN* r);/*BU*/
		void _in_yaz(ELEMAN* r);/*BU*/
		void _post_yaz(ELEMAN* r);/*BU*/
		int _elsay(ELEMAN* r);
		int _minimum(ELEMAN* r);
		ELEMAN* _delete_key(char x,ELEMAN* r);
	    int _yukseklik(char x,ELEMAN* r);
	    int _agac_yuksekligi(ELEMAN* r);
	public:
		Tree()
		{
			root=NULL;
		};
	    void eleman_ekle(char x);/*BU*/
		void in_yaz();/*BU*/
		void post_yaz();/*BU*/
		int elsay();
		int minimum();
		void delete_key(char x);	
		int yukseklik(char x);
		int agac_yuksekligi();
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

void AGAC::eleman_ekle(char x)
{
	root= _eleman_ekle(x,root);
}

ELEMAN* AGAC::_eleman_ekle(char x,ELEMAN *r)
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
		cout<<r->data;
		_in_yaz(r->right);
	}
}


void AGAC::post_yaz()
{
	_post_yaz(root);	
}

void AGAC::_post_yaz(ELEMAN *r)
{
	if(r==NULL)
	    return;
	else
	{
		_in_yaz(r->left);
		_in_yaz(r->right);
        cout<<r->data;
	}
}
/*
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


void AGAC::delete_key(char x)
{
	root=_delete_key(x,root);
}

ELEMAN* AGAC::_delete_key(char x,ELEMAN* r)
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
*/

int main()
{
	AGAC agac;
	for(char x='A';x<='Z';x=x+1)
	{
		
		agac.eleman_ekle(x);
		
	}
	

	agac.in_yaz();
	cout<<endl;

}





