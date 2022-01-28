#include<stdlib.h>
#include<iostream>
#include <math.h>
using namespace std;

class Node
{
	public:
		int data;
		Node* right;
		Node* left;
		Node()
		{
			data=0;
			right=NULL;
			left=NULL;
		};
		Node(int x)
		{
			data=x;
			right=NULL;
			left=NULL;
		};		
};


class Tree
{
	private:
		Node* root;
		Node* _ekle(int x,Node* r);
		void _yazdirma(Node* r);
		int _size(Node* r);
		int _minimum(Node* r);
		Node* _delete_key(int x,Node* r);
	    int _yukseklik(int x,Node* r);
	    int _agac_yuksekligi(Node* r);
	public:
		Tree()
		{
			root=NULL;
		};
	    void ekle(int x);
		void yazdirma();
		int size();
		int minimum();
		void delete_key(int x);	
		int yukseklik(int x);
		int agac_yuksekligi();
		bool bos_mu();
		bool yaprak();
};

bool Tree::bos_mu()
{
	if(root==NULL)
	    return true;
	return false;
}

bool Tree::yaprak()
{
	if(root!=NULL&&root->left==NULL&&root->right==NULL)
	    return true;
	return false;
}

void Tree::ekle(int x)
{
	root= _ekle(x,root);
}

Node* Tree::_ekle(int x,Node *r)
{
	if(r==NULL)
	{
		Node* yeni=new Node(x);
		return yeni;
	}
	else
	{
		if(x>r->data)
		{
			r->right= _ekle(x,r->right);
		}
		else
		{
			r->left= _ekle(x,r->left);
		}
	}
	return r;	
}

void Tree::yazdirma()
{
	_yazdirma(root);	
}

void Tree::_yazdirma(Node *r)
{
	if(r==NULL)
	    return;
	else
	{
		_yazdirma(r->left);
		printf("%d",r->data);
		_yazdirma(r->right);
	}
}

int Tree::size()
{
	return _size(root);
}

int Tree::_size(Node* r)
{
	if (r==NULL)
        return 0;
	else
	    return 1+_size(r->right)+_size(r->left);
}

int Tree::minimum()
{
	return _minimum(root);
}

int Tree::_minimum(Node* r)
{
	if(r==NULL)
	    return 10000;
	else 
    {
    	Node* temp=r;
    	while(temp->left!=NULL)
    	{
    		temp=temp->left;
		}
		return temp->data;
	}
}


void Tree::delete_key(int x)
{
	root=_delete_key(x,root);
}

Node* Tree::_delete_key(int x,Node* r)
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
			Node* temp=r->left;
			delete(r);
			return temp;
		}
		else if(r->left==NULL)
		{
			Node* temp=r->right;
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

int Tree::agac_yuksekligi()
{
	return _agac_yuksekligi(root);
}

int Tree::_agac_yuksekligi(Node* r)
{
	if(r==NULL)
	    return -1;
	else
    	return 1+max(_agac_yuksekligi(r->left),_agac_yuksekligi(r->right));
}



/*
int Tree::yukseklik(int x)
{
	_yukseklik(x,root);
}

int Tree::_yukseklik(int x,Node* r)
{
    Node* temp=r;

	if(temp==NULL)
	    return -1;
	
	else if(x>temp->data)
	{
	   /* r->right=_yukseklik(x,r->right);*
	    temp=temp->right;
	    _yukseklik(x,temp); 

    }
	else if(x<temp->data)
	{
	   /* r->left=_yukseklik(x,r->left);*
	    temp=temp->left;
	    _yukseklik(x,temp);
	}
    else
	    return 1+max(_yukseklik(x,temp->left),_yukseklik(x,temp->right));  


}
*/
int main()
{
	Tree agac;
	agac.ekle(10);
	agac.ekle(20);
	agac.ekle(5);
	agac.ekle(6);
	agac.ekle(-5);
	agac.yazdirma();
	cout<<endl;
	cout<<"minimum:"<<agac.minimum()<<endl;
	cout<<"size:"<<agac.size()<<endl;
/*	agac.delete_key(6);
	agac.yazdirma();
	cout<<endl;
	agac.delete_key(5);
	agac.yazdirma();
*/
    cout<<"yukseklik:"<<agac.agac_yuksekligi();
}








