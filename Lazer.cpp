#include <cstdio>
#include <cmath>
#include <iostream>
#include <map>

#define fi first
#define se second

using namespace std;

int N,K;

map<double,int> cnt;

int main(){
	
	scanf("%d%d",&N,&K);
	
	for( int x,y,i=0 ; i<N ; i++ ){
		scanf("%d%d",&x,&y);
		cnt[atan2(y,x)]++; // (x,y) noktasının eğimini belirten yeri 1 arttırıyoruz.
	}
	
	for( map<double,int>::iterator it=cnt.begin() ; it!=cnt.end() ; it++ )
		if( it->se>=K ){ // Eğer aynı eğime sahip K'den büyük eşit sayıda nokta varsa "Yes" yazdırıyoruz
			puts("Yes");
			return 0;
		}
	
	puts("No"); // Hiç yoksa "No"
	return 0;
}