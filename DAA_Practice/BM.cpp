#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<char, int> BuildBadTable(string pattern){

    unordered_map<char, int> mismatchShiftTable;

    int lp = pattern.length();

    for(int index = 0; index < lp; index++){

        char C = pattern[index];

        int maxshift = max(1, lp-index-1);

        mismatchShiftTable[C] = maxshift;
    }

    return mismatchShiftTable;
}

void BMPattern(string text, string pattern){

    unordered_map<char, int> mismatchShiftTable = BuildBadTable(pattern);

    int lt = text.length();
    int lp = pattern.length();

    int numOfSkips;

    for(int i = 0; i <= lt-lp; i += numOfSkips){

        numOfSkips = 0;

        for(int j = lp-1; j >= 0; j--){

            if(pattern[j] != text[i+j]){

                char mismatchChar = text[i+j];

                if(mismatchShiftTable.find(mismatchChar) != mismatchShiftTable.end()){

                    numOfSkips = mismatchShiftTable[mismatchChar];
                }
                else{

                    numOfSkips = lp;
                }

                break;
            }
        }

        if(numOfSkips == 0){

            cout << "Pattern found at index " << i << endl;
            return;
        }
    }

    cout << "Pattern not found";
}

int main(){
	string text, pattern;
	
	cout<<"Enter text: "<<endl;
	cin>>text;
	
	cout<<"Enter pattern: "<<endl;
	cin>>pattern;
	
	BMPattern(text, pattern);
	
	return 0;
}
