#include<iostream>
#include<vector>
using namespace std;

int NaiveSearch(string text, string pattern){
	int n = text.size();
	int m = pattern.size();
	
	if(m>n || m==0){
		cout<<"Pattern not found"<<endl;
	}
	
	bool found = false;
	
	for(int i=0; i<=n-m; i++){
		int j = 0;
		while(j<m && text[i+j] == pattern[j]){
			j++;
		}
		if(j==m){
			cout<<"Pattern found at index: "<<i<<endl;
            found = true;
		}
	}
	
	if(!found){
        cout<<"Pattern not found"<<endl;
    }
}

int main(){
	string text, pattern;
	
	cout<<"Enter text: "<<endl;
	cin>>text;
	
	cout<<"Enter pattern: "<<endl;
	cin>>pattern;
	
	NaiveSearch(text, pattern);
	
	return 0;
}
