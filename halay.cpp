#include <iostream>
#include <string.h>
using namespace std;

class dugum
{
	public:
		string isim;
		dugum* sonraki;/*bir sonraki dόπόme adres tutuyor.*/	
};

class halay
{
	private:
		dugum* halay_basi;
		
	public:
		halay()
		{
			halay_basi= NULL;
		};
		bool bos_mu();/*ώ*/
		void basa_ekle(string isim); /*b*/
		void sona_ekle(string isim);/*i*/
		void araya_ekle(string isim);
		void sirali_ekle(string isim);
		void listele();/*l*/
		void bastan_cikar();/*ddd*/
		void sondan_cikar();/*i*/
		int siradan_cikar(int s);	/*ώ*/
		int kac_tane();
};

int halay::siradan_cikar(int s)
{
	dugum* gosterici;
	dugum* tutulan_dugum;
    gosterici=halay_basi;
	for(int i=1;i<=s;i=i+1)
	{
		if(i==s-1)
		{
		gosterici=tutulan_dugum;
		gosterici=gosterici->sonraki;
     	}
     	else
     	{
		gosterici=gosterici->sonraki;
	    }
    } 
    delete tutulan_dugum->sonraki;
    tutulan_dugum->sonraki=gosterici->sonraki;
    
 
	
	
}





int halay::kac_tane()
{
	int sayac=0;
	dugum* gosterici;
	gosterici=halay_basi;
	while(gosterici->sonraki!=NULL)
		{
			gosterici=gosterici->sonraki;
			sayac=sayac+1;
		}
		return sayac+1;
}


bool halay::bos_mu()
{
	if(halay_basi==NULL)
	     return true;
    return false;
}


void halay::basa_ekle(string isim)
{
	dugum* yeni_akraba=new dugum;
	yeni_akraba->isim=isim;
	
	if(bos_mu())
	{
		yeni_akraba->sonraki=NULL;
		halay_basi=yeni_akraba;
	}
	else
	{
		yeni_akraba->sonraki=halay_basi;
		halay_basi=yeni_akraba;
	}
}


void halay::listele()
{
	if(bos_mu())
	{
		cout<<"halayda kimse yok!\n";
	}
	else
	{
		dugum* gosterici;
		gosterici=halay_basi;
		while(gosterici!=NULL)
		{
			cout<<gosterici->isim<<" ";
			gosterici=gosterici->sonraki;
		}
	}
}


void halay::sona_ekle(string isim)
{
	dugum* yeni_akraba=new dugum;
	yeni_akraba->isim=isim;
	yeni_akraba->sonraki=NULL;
	if(bos_mu())
	{
		halay_basi=yeni_akraba;
	}
	else
	{
		dugum* gosterici;
		gosterici=halay_basi;
		while(gosterici->sonraki!=NULL)
		{
			gosterici=gosterici->sonraki;
		}
		gosterici->sonraki=yeni_akraba;
	}
}


void halay::bastan_cikar()
{
	if(bos_mu()==false)
	{
		delete halay_basi;
		halay_basi=halay_basi->sonraki;
	}
}


void halay::sondan_cikar()
{
	if(bos_mu()==false)
	{
	
	dugum* gosterici;
	gosterici=halay_basi;
    
    for(int n=1;n<kac_tane()-1;n=n+1)
	{
		gosterici=gosterici->sonraki;
	}
	gosterici->sonraki=NULL;
    }  
}


int main()
{
	halay halay1;
	
	halay1.basa_ekle("merve");
	halay1.basa_ekle("meryem");
	halay1.basa_ekle("metin");
	halay1.basa_ekle("ayse");
	halay1.listele();
	cout<<endl;
	
	halay1.sona_ekle("halil");
	halay1.sona_ekle("helin");
	halay1.listele();	
	cout<<endl;
	
	
	halay1.bastan_cikar();
	halay1.listele();
	cout<<endl;
	
	halay1.sondan_cikar();
	halay1.listele();
	cout<<endl;
	
	
	
	halay1.siradan_cikar(2);
	halay1.listele();
	
}
