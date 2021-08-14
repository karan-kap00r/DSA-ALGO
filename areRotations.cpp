#include<bits/stdc++.h>
using namespace std;

bool areRotation(string s1,string s2)
{
	if(s1.length()==s2.length())
	{
		string temp=s1+s1;
		return (temp.find(s2) != string::npos); 
	}
}

int main()
{
	string s1,s2;
	s1="ABEF";
	s2="AdBEF";
	if(areRotation(s1,s2))
	cout<<"strings are rotations of each other "<<endl;
	else
	cout<<"strings are not rotations of each other";
	return 0;
}
