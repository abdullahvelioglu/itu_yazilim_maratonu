#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN=1e5+15;

int N,M;
int ar[MAXN];

int main(){
	
	scanf("%d%d",&N,&M);
	
	for( int i=1 ; i<=N ; i++ ){
		scanf("%d",ar+i);
		ar[i]^=ar[i-1]; // ar[i], dizinin ilk i elemanının xorlanmış hali oluyor
	}
	
	for( int l,r,i=0 ; i<M ; i++ ){
		scanf("%d%d",&l,&r);
		printf("%d\n",ar[r]^ar[l-1]); // Sonucu veren formül
	}
	
	return 0;
}