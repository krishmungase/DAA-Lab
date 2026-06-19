#include<iostream>
#include<vector>
using namespace std;

vector<int> BuildLPS(string pattern){
	int m = pattern.size();
	
	vector<int> lps(m, 0);
	
	int len = 0; 
	int i = 1;
	
	while(i<m){
		if(pattern[i] == pattern[len]){
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if(len != 0){
				len = lps[len - 1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
	
	return lps;
}

vector<int> KMPSearch(string text, string pattern){
	int n = text.size();
	int m = pattern.size();
	
	vector<int> result;
	
	vector<int> lps = BuildLPS(pattern);
	
	cout << "\nLPS Array: ";

    for(int i = 0; i < lps.size(); i++){
        cout << lps[i] << " ";
    }
    
    int i = 0;
    int j = 0;
    
    while(i<n){
    	if(text[i] == pattern[j]){
    		i++;
    		j++;
		}
		if(j==m){
			result.push_back(i-j);
			j = lps[j-1];
		}
		else if(text[i] != pattern[j] && i<n){
			if(j != 0){
				j = lps[j-1];
			}
			else{
				i++;
			}
		}
	}
	
	return result;
}

int main(){
	string text, pattern;
	
	cout<<"Enter text: "<<endl;
	cin>>text;
	
	cout<<"Enter pattern: "<<endl;
	cin>>pattern;
	
	cout<<endl;
	
	
	cout<<text<<"\n"<<pattern<<endl;
	
	vector<int> result = KMPSearch(text, pattern);
	
	if(result.empty()){
		cout<<"Pattern not found"<<endl;
	}
	else{
		cout << "\nPattern found at indexes: ";

    	for(int i = 0; i < result.size(); i++){
        	cout << result[i] << " ";
    	}
	}
	
	return 0;
}
