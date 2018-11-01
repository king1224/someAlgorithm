#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

struct Trie{
	Trie *next[26];
	int n;

	Trie(){
		memset(next, 0, sizeof(Trie*)*26);
		n = 0;
	}
};

struct Letter{
	char letter;
	Letter *next;

	Letter(){
		next = NULL;
	}
}*tmpLetter;

struct SamePoint{
	int x,y;
	char letter;
}tmpPoint;

struct Node{
	int lcs;
	bool s1;

	Node(){
		s1 = false;
		lcs = 0;
	}
};

int main(){
	string A;
	string B;
	cin >> A >> B;

	int lenA, lenB, maxlen;
	Node D[101][101];
	vector<SamePoint> v[101];
	lenA = A.length();
	lenB = B.length();

	for(int i=0; i<lenA; ++i){
		for(int j=0; j<lenB; ++j){
			if(A[i] == B[j]){
				if(i==0 || j==0)
					D[i][j].lcs = 1;
				else
					D[i][j].lcs = D[i-1][j-1].lcs+1;
				D[i][j].s1 = true;
				tmpPoint.x = i;
				tmpPoint.y = j;
				tmpPoint.letter = A[i];
				v[D[i][j].lcs].push_back(tmpPoint);
			}
			else if(D[i-1][j].lcs < D[i][j-1].lcs){
				D[i][j].lcs = D[i][j-1].lcs;
			}
			else{
				D[i][j].lcs = D[i-1][j].lcs;
			}
		}
	}

	maxlen = D[lenA-1][lenB-1].lcs;

	for(int i=1;i<maxlen;++i){
		for(int j=0;j<v[i+1].size();++j){
			for(int k=0;k<v[i].size();++k){
				if(v[i][k].x >= v[i+1][j].x)
					break;
				if(v[i][k].y >= v[i+1][j].y)
					continue;
				// init trie
				for(int l=0;l<i;++l){
					//trie construct
				}
			}
		}
	}

	for(int i=1;i<=maxlen;++i){
		for(int j=0;j<v[i].size();++j){
			printf("(%d,%d,%c) ", v[i][j].x, v[i][j].y, v[i][j].letter);
		}
		puts("");
	}
	puts("");
	puts("");

	for(int i=0; i<lenA; ++i){
		for(int j=0; j<lenB; ++j){
			printf("%d ",D[i][j].lcs);
		}
		puts("");
	}
	puts("");
	puts("");

	for(int i=0; i<lenA; ++i){
		for(int j=0; j<lenB; ++j){
			if(D[i][j].s1)
				printf("%d ",D[i][j].lcs);
			else
				printf("0 ");
		}
		puts("");
	}
	puts("");
	puts("");

	cout << A << endl << B << endl;
	return 0;
}
