#include<stdlib.h>
#include<iostream>
#include <math.h>
using namespace std;

class Node
{
	public:
		int koordinatx;
		int koordinaty;
		Node* right;
		Node* left;
		Node()
		{
			koordinatx=0;
			koordinaty=0;
			right=NULL;
			left=NULL;
		};
		Node(int x,int y)
		{
			koordinatx=x;
			koordinaty=y;
			right=NULL;
			left=NULL;
		};		
};


class Tree
{
	private:
		Node* root;
		Node* _ekle(int x,int y,Node* r);
		void _yazdirma(Node* r);
		int _size(Node* r);
		int _minimum(Node* r);
		Node* _delete_key(int x,int y,Node* r);
	    int _agac_yuksekligi(Node* r);
	    bool _yaprakk(int x,int y,Node* r);
	    int _agac_pyukseklik(int x,int y,Node* r);
	public:
		Tree()
		{
			root=NULL;
		};
	    void ekle(int x,int y);
		void yazdirma();
		int size();
		int minimum();
		void delete_key(int x,int y);	
		int agac_yuksekligi();
		bool bos_mu();
		bool yaprak();
		bool yaprakk(int x,int y);
		int agac_pyukseklik(int x,int y);
};

bool Tree::bos_mu()
{
	if(root==NULL)
	    return true;
	return false;
}

bool Tree::yaprakk(int x,int y)
{
	return _yaprakk(x,y,root);
	
}

bool Tree::_yaprakk(int x,int y,Node* r)
{
	Node* temp=r;
	while(true)
	{
	if(x>temp->koordinatx)
	    temp=temp->right;
	else if(x<temp->koordinatx)
	    temp=temp->left;
	else
	{
	    if(temp!=NULL&&temp->left==NULL&&temp->right==NULL)
	    {
	    	return true;
	        break;
	    }
	 return false;
	 break;
    }
	}
}



bool Tree::yaprak()
{
	
	if(root!=NULL&&root->left==NULL&&root->right==NULL)
	    return true;
	return false;

}

void Tree::ekle(int x,int y)
{
	root= _ekle(x,y,root);
}

Node* Tree::_ekle(int x,int y,Node *r)
{
	if(r==NULL)
	{
		Node* yeni=new Node(x,y);
		return yeni;
	}
	else
	{
		if(x>r->koordinatx)
		{
			r->right= _ekle(x,y,r->right);
		}
		else
		{
			r->left= _ekle(x,y,r->left);
		}
	}
	return r;	
}

void Tree::yazdirma()
{
	_yazdirma(root);	
}

void Tree::_yazdirma(Node *r)/*in_yaz*/
{
	if(r==NULL)
	    return;
	else
	{
		_yazdirma(r->left);
		cout<<r->koordinatx<<","<<r->koordinaty<<" ";
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
		return temp->koordinatx;
	}
}


void Tree::delete_key(int x,int y)
{
	root=_delete_key(x,y,root);
}

Node* Tree::_delete_key(int x,int y,Node* r)
{
	if(r==NULL)
	    return NULL;
	if(x>r->koordinatx)
	    r->right=_delete_key(x,y,r->right);
	else if(x<r->koordinatx)
	    r->left=_delete_key(x,y,r->left);
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
			r->koordinatx=minimum_value;
			r->right=_delete_key(minimum_value,y,r->right);
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


int Tree::agac_pyukseklik(int x,int y)
{
	return _agac_pyukseklik(x,y,root);
	
}

int Tree::_agac_pyukseklik(int x,int y,Node* r)
{
	Node* temp=r;
	while(true)
	{
	if(x>temp->koordinatx)
	    temp=temp->right;
	else if(x<temp->koordinatx)
	    temp=temp->left;
	else
	{
		if(r==NULL)
	        return -1;
    	else
        	return 1+max(_agac_yuksekligi(temp->left),_agac_yuksekligi(temp->right));
        	break;

    }
	}
}
















int main()
{
	Tree agac;
	agac.ekle(10,5);
	agac.ekle(20,7);
	agac.ekle(5,8);
	agac.ekle(6,8);
	agac.ekle(-5,6);
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
    cout<<"yukseklik:"<<agac.agac_yuksekligi()<<endl;
    cout<<"yukseklik:"<<agac.agac_pyukseklik(-5,6)<<endl;
    cout<<"yukseklik:"<<agac.agac_pyukseklik(20,7)<<endl;
    cout<<"yukseklik:"<<agac.agac_pyukseklik(5,8)<<endl;

  cout<<agac.yaprakk(10,5);
  cout<<agac.yaprakk(20,7);
  cout<<agac.yaprakk(5,8);
  cout<<agac.yaprakk(-5,6);
  cout<<agac.yaprak();
}




