#include <cstdio>
#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

const int MAXN=1e5+15;

int N,K,S,mx;

bool mark[MAXN];

vector<int> g[MAXN];

inline void dfs( int nd , int pre , int d ){
	
	// nd: Şu an bulunduğuuz durak
	// pre: Bu durağa hangi duraktan geldiğimiz
	// d: Başladığımız durakla bu durak arasındaki mesafe
	
	if( mark[nd] && d>mx ){ // Eğer burası bir Merdobüs durağıysa ve başlangıç noktamıza uzaklığı şu ana kadarki bulduklarımızdna daha büyükse en uzak mesafemizi ve durağımızı güncelliyoruz
		mx=d;
		S=nd;
	}
	
	for( vector<int>::iterator it=g[nd].begin() ; it!=g[nd].end() ; it++ ) // Ağacı gezmeye devam ediyoruz
		if( *it!=pre ) // Bir önceki durağa tekrar gitmememiz yeterli, çünkü ağaçta zaten döngü olmaz
			dfs(*it,nd,d+1);
}

int main(){
	
	scanf("%d%d",&N,&K);
	
	for( int a,b,i=1 ; i<N ; i++ ){ // Graphı oluşturuyoruz
		scanf("%d%d",&a,&b);
		g[a].pb(b);
		g[b].pb(a);
	}
	
	int a;
	
	for( int i=0 ; i<K ; i++ ){
		scanf("%d",&a);
		mark[a]=1; // Merdobüs duraklarını işaretliyoruz
	}
	
	dfs(a,0,0); // Herhangi bir Merdobüs durağına en uzak olan Merdobüs durağını buluyoruz(Bu durak S değişkenine kaydedilecek)
	mx=0; // dfs fonksiyonunda tekrar kullanılacağı için 0'a eşitliyoruz
	dfs(S,0,0); // S numaralı Merdobüs durağına en uzak Merdobüs durağını buluyoruz. Aralarındaki uzaklık bizim aradığımız cevap
	
	printf("%d\n",mx);
	return 0;
}