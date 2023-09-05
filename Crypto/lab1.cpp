//caesar cipher encryption
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int i,n,key;
	string input,output;
	cout<<"enter the text:"<<endl;
	cin>>input;
    cout<<"enter the key:"<<endl;
	cin>>key;
	for(i=0;i<input.size();i++)
	{
	
		output+=(input[i]-'A'+key)%26+'A';
	}
	cout<<"the encrypted message is:"<<output<<'\n';
	
}