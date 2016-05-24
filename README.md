# itu_yazilim_maratonu
2016 ITU IEEE YAZILIM MARATONU

#http://ituym.ituieee.com/




#String
Verilen stringin ters çevirilmiş haliyle ilk halinin aynı olup olmadığını kontrol edebilirsiniz.




#Lazer
Her öğrencinin (0,0) noktasına göre eğimini bir diziye atıp diziyi küçükten büyüğe sıralayınız. Aynı olan sayılar, dizi sıralandıktan sonra bu dizide yanyana bulunacaklardır. Yani herhangi bir i. indis için dizinin i. elemanıyla (i+k-1). elemanı aynıysa aradaki elemanlar da aynıdır. Yani aynı doğru üzerinde bulunan en az k tane eleman vardır.

Farklı bir çözüm olarak eğimleri hazır veri yapıları içinde tutabilirsiniz( C++’daki map, Python’daki dictionary vs.). Ve bu yapılar içindeki elemanların kaçar tane olduğunu aynı yapıya ait fonksiyonlarla bulabilirsiniz.

Sonuç olarak O(NlogN) zaman karmaşıklığında bu soruyu çözebilirsiniz.



#Cab Çıldırıyor

Bu soruyu verimli bir zaman karmaşıklığında çözebilmek için bir gözleme ihtiyacımız var:

x^x = 0

Bu gözlemi yaptıktan sonra yine daha hızlı bir algoritma için şöyle bir dizi tanımlıyoruz( ilk başta verilen girdiyi ar[] dizisinde tuttuğumuzu var sayın):

dn[0]= 0
dn[i] = ar[1]^ar[2]^...ar[i-1]^ar[i]

Bu diziyi de oluşturduktan sonra verilen herhangi bir (a,b) sorgusunun cevabını şu formülle hızlıca bulabiliriz:

dn[b]^dn[a-1]

Burada ar[1]..ar[a-1]’e kadar olan elemanları iki kez xor işlemine soktuğumuz için bu elemanlar birbirlerini 0’layacak ve elimizde ar[a]’dan ar[b]’ye kadar olan elemanların xor işlemine göre sonucu kalmış olacak. Bu şekilde soruyu O(N+M) zaman karmalıklığında çözebiliriz.


#Merdopolis
Bir ağaçta birbirine en uzak konumlarda bulunan iki node şu şekilde bulunabilir:
Herhangi bir node’a en uzak olan node’u bul. Bunu birçok gezinme algoritmasıyla O(N) zaman karmaşıklığında bulabilirsini.
Aynı şekilde yeni bulduğunuz node’a en uzak olan node’u da bulduğunuzda cevabı elde etmiş olursunuz.

Bu şekilde toplam O(N) zaman karmaşıklığında soruyu çözebilriz.


#Çift Oyunu

Dışarıya doğru edge’i olmayan nodelardayken oyunun kesinlikle galibi olmadığını görebiliriz. Her node için özel bazı özellikleri göz önünde bulundurmamız gerekiyor:
Oyunu Rzgi’nin kazandığı durumları bulmaya çalıştığımız için tamamen Rzgi’nin gözünden bakacağız. Kesin olarak bildiğimiz durum 1 numaralı node’dan oyun başlandığığnda Rzgi kaybediyor. Yani 1 numaralı node kaybeden node’dur.
Eğer bir K node’undan kaybeden nodelardan herhangi birine bağlantı varsa K node’u kazanan nodedur.
Eğer bir nodedan sadece kazanan nodelara gidiş varsa o node kaybeden nodedur.
Üstteki durumlara uymayan nodelar beraberlik nodelarıdır.
Bu şekilde bütün graph’ı O(M) zaman karmaşıklığında tarayarak her node’un durumunu bulabiliriz. O(N) değil, O(M); çünkü bir node’un durumunu belirlemek için o node’dan çıkan bütün edge’lere bakmamız gerekiyor, graph’ta da toplam M tane edge var.

