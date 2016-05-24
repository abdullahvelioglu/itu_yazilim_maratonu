#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN=333;

int N;

char s[MAXN];

int main(){
	
	scanf("%s",s+1);
	
	N=strlen(s+1);
	
	for( int i=1,j=N ; i<j ; i++,j-- )
		if( s[i]!=s[j] ){
			puts("No");
			return 0;
		}
	
	puts("Yes");
	return 0;
}