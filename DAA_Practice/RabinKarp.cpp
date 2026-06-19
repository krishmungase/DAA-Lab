#include<iostream>
using namespace std;

int calculateHash(string str){
	
	int hash = 0;

    for(int i = 0; i < str.size(); i++){
        hash += (str[i] % 7);
    }

    return hash;
	
}

int RabinKarp(string text, string pattern){
	int n = text.size();
	int m = pattern.size();
	
	int hPattern = calculateHash(pattern);
	
	bool found = false;
	
	for(int i=0; i<=n-m; i++){
		
		string temp = text.substr(i, m);

		int htext = calculateHash(temp);
		
		if(htext == hPattern){
			if(temp == pattern){
                cout << "Pattern found at index: " << i << endl;
                found = true;
            }
		}
	}
	
	if(!found){
		cout<<"Pattern not found"<<endl;
	}
	
	return 0;
}

int main(){
	string text, pattern;
	
	cout<<"Enter text: "<<endl;
	cin>>text;
	
	cout<<"Enter pattern: "<<endl;
	cin>>pattern;
	
	RabinKarp(text, pattern);
	
	return 0;
}
