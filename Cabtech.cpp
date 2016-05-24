#include <cstdio>
#include <iostream>

using namespace std;

typedef long long int Lint;

const int MAXN=111;
const Lint MOD=1e9+7;

int N,S;
int mx[MAXN];
int beg[MAXN];
int sum[MAXN];

Lint dn[MAXN][MAXN*MAXN];
Lint cm[MAXN*MAXN][MAXN];

Lint comb( int n , int r ){ // Kombinasyon hesaplama fonksiyonu
	
	if( cm[n][r] ) // Eğer bu n ve r değerine göre daha önce hesap yaptıysak tekrar hesap yapmaya gerek yok
		return cm[n][r];
	
	if( r>n )
		return 0LL;
	if( n==r || !r )
		return cm[n][r]=1;
	if( r==1 || r==n-1LL )
		return cm[n][r]=n;
	
	return cm[n][r]=(comb(n-1,r)+comb(n-1,r-1))%MOD; // Bu fonksiyonda da fazla işlem yapmayı engellemek için dinamik programlama kullanıyoruz
}

Lint f( int pl , int cur ){
	
	// pl: Şu an kaçıncı katta olduğumuz
	// cur: Bu kattan itibaren ikinci toplantılara yerleştirmemiz gereken kaç kişinin olduğu
	
	if( pl==N+1 )
		return cur ? 0LL : 1LL; // Bütün katlar bittiğinde herkesi yerleştirebildiysek bu doğru bir yerleşimdir
	
	Lint &rev=dn[pl][cur];
	
	if( rev!=-1 ) // Eğer bu pl ve cur değerine göre daha önce hesap yaptıysak tekrar hesap yapmaya gerek yok
		return rev;
	
	rev=0LL;
	cur+=beg[pl]; // İlk toplantısını bu katta yapanlar da artık ikinci toplantılara yerleştireceğimiz kişilere dahiller
	
	for( int i=0 ; i<=min(cur,mx[pl]) ; i++ ) // Elimizdeki kişilerin bir kısmı ikinci toplantılarına bu katta girecekler kalanlar ise yukarı katlara çıkacaklar. Bu şekildeki her türlü durumu hesaplamamız gerekiyor
		rev=(rev+f(pl+1,cur-i)*comb(cur,i))%MOD; // Bu katta i kişi bırakıp kalanları yukarı katlara gönderiyoruz. Her kişi birbirinden farklı olduğu için bu katta kalanları da kombinasyon hesabı ile seçmemiz gerekiyor
	
	return rev;
}

int main(){
	
	for( int i=0 ; i<MAXN ; i++ )
		for( int j=0 ; j<MAXN*MAXN ; j++ )
			dn[i][j]=(Lint)-1; // Kodlama kolaylığı için bütün dinamik dizisini başta -1 ile dolduruyoruz
	
	scanf("%d",&N);
	
	for( int i=1 ; i<=N ; i++ ){ // Kişi sayısı olan S'i, ilk toplantılara katılan kişi sayılarını toplayarak elde ediyoruz
		scanf("%d",beg+i);
		S+=beg[i];
	}
	for( int i=1 ; i<=N ; i++ )
		scanf("%d",mx+i);
	
	Lint res=f(1,0); // İkinci toplantılar için tüm dağılım durumlarını hesaplayan fonksiyon. Daha sonra ilk toplantı durumlarını da hesaplayıp bu sayıyla çarpacağız
	
	for( int i=1 ; i<=N ; i++ ){ // İlk toplantılardaki her türlü durumu da hesaba katmak lazım. S kişinin ilk toplantılardaki her türlü dağılımını hesaplıyoruz
		res=(res*comb(S,beg[i]))%MOD;
		S-=beg[i];
	}
	
	printf("%lld\n",res);
	return 0;
}