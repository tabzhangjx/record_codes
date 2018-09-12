#include <iostream>

using namespace std;

template <typename T>
inline T const& max(T const& a, T const& b){
	if(a==b)
		return a;
	else
		return a>b?a:b;
}

template <typename T1, typename T2>
inline T1 max2(T1 const& a, T2 const& b){
	if(a==b)
		return a;
	else
		return a>b?a:b;
}

//deduction

template <typename T1, typename T2, typename RT>
inline RT max3(T1 const& a, T2 const& b){
	if(a==b)
		return a;
	else
		return a>b?a:b;
}

template <typename RT, typename T1, typename T2>
inline RT max4(T1 const& a, T2 const& b){
	if(a==b)
		return a;
	else
		return a>b?a:b;
}

int main(){
	cout<<::max(4, 5)<<endl;
	cout<<::max(4.2, 4.3)<<endl;
	cout<<::max((double)4, 4.3)<<endl;
	cout<<::max<double>(4.2, 5)<<endl;

	cout<<max2(4.3, 4)<<endl;
	cout<<max2(3, 4.3)<<endl;

	cout<<max3<int, double, double>(4, 4.3)<<endl;
	cout<<max4<double>(4, 4.3)<<endl;//if is max3 -> note: candidate template ignored: couldn't infer template argument 'RT'
	return 0;
}