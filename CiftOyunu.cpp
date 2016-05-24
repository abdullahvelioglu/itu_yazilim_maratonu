#include <cstdio>
#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

const int MAXN=1e5+15;

int N,M,res;
int out[MAXN];

bool vis[MAXN];
bool win[MAXN];
bool loose[MAXN];

vector<int> rg[MAXN];

inline void dfs( int nd ){
	
	vis[nd]=1; // Bir nodea tekrardan gelmemek için o nodeu işaretliyoruz
	
	for( vector<int>::iterator it=rg[nd].begin() ; it!=rg[nd].end() ; it++ )
		if( !vis[*it] ){ // Eğer *it nodeuna daha önce gelinmemişse
			
			if( loose[nd] ) // Eğer şimdiki node kaybeden nodesa *it nodeu kazanan nodedur
				win[*it]=1;
			else if( !(--out[*it]) ) // *it nodeunun normal graphtaki dışarıya doğru olan edgelerini 1 azaltıyoruz. Eğer dışarı doğru bir edgei kalmadıysa ve hiçbir kaybeden nodea doğrudan ulaşamıyorsa(eğer ulaşıyor olsaydı en az 1 kere üstteki if durumu geçerli olacaktı) *it nodeu artık kaybeden nodedur
				loose[*it]=1;
			else // *it nodeunun kazanan ya da kaybeden node olduğu belli olmadan dfs fonksiyonuna o node u çağıramayız
				continue;
			
			dfs(*it);
		}
}

int main(){
	
	// Bu tarz sorular için graphlar ve oyun teorilerini incelemeniz önerilir
	
	scanf("%d%d",&N,&M);
	
	for( int a,b,i=0 ; i<M ; i++ ){ // Graphı tersten tutuyoruz. Yani A nodeundan B nodeuna yol varsa biz B nodeundan A nodeuna yol var şeklinde tutuyoruz
		scanf("%d%d",&a,&b);
		rg[b].pb(a);
		out[a]++; // Normal grahpta a nodeundan çıkan edgelerin sayısı
	}
	
	loose[1]=1; // 1 numaralı node kaybeden nodedur
	dfs(1); // Bitiş nodeu 1 numaralı node olduğu için diğer nodeların durumlarını 1 numaralı nodedan yola çıkarak hesaplayacağız
	
	for( int i=1 ; i<=N ; i++ )
		res+=win[i]; // Eğer i numaralı node kazanan node ise sonucu arttırıyoruz
	
	printf("%d\n",res);
	return 0;
}