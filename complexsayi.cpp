#include<iostream>

using namespace std;
template<typename Type>
class Complex{
	private:
		Type a,b;
	public:
		Complex(Type const&r=Type(),Type const&i=Type());
		Type real() const;
		Type imag() const;
	/*	Complex exp() const;*/
};

template<typename Type>
Complex<Type>::Complex(Type const&r,Type const&i):a(1),b(1){
a=r;
b=i;

}

template<typename Type>
Type Complex <Type>::real() const{
return a;
}

template<typename Type>
Type Complex <Type>::imag() const{
return b;
}

/*
template<typename Type>
Complex<Type> Complex<Type>::exp() const{
Type exp_re=exp(a);
return Complex<Type>(exp_re*cos(b),exp_re*sin(b));
}
*/


int main(){
 /*Complex <double>d(4.2,5.6);*/

Complex<double> complex_sayi(7,2);

 cout <<complex_sayi.real()<<"+"<<complex_sayi.imag()<<"i";
}













