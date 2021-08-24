#include<bits/stdc++.h>
using namespace std;

int BirthdayParadox(double per)
{
	 return ceil(sqrt(2*365*log(1/(1-per))));
}

int main()
{
	double per;
	cout<<"Enter the probability( 0> x <1 ) that two persons have b'day on same day : "<<endl;
	cin>>per;
	cout<<"Number of person will be : "<<endl<<BirthdayParadox(per)<<endl;
	return 0;
}


