//Caesar cipher decryption
#include<iostream>
#include<string>
using namespace std;
int main(){
    int i,j,k;
    string input,output;
    int key;
    cout<<"Enter the message to decrypt\n";
    cin>>input;
    cout<<"Enter the key\n";
    cin>>key;
    for(i=0;i<input.size();i++){
        output+=(input[i]-'A'-key+26)%26+'A';
    }
    cout<<"\n\nDecrypted message is "<<output<<'\n';
}