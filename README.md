# Sayısal İntegrasyon Yöntemleri / Numerical Integration Methods

Sayısal integrasyon veya integral alma işlemi, analitik olarak bir integralin alınmasının çok zor
veya olanaksız olduğu durumlarda veya bir işlevin değerlerinin sadece belirli noktalarda
bilinmesi durumlarında önem kazanır. Ayrıca integrasyon işlemlerini içeren veya gerektiren
problemlerin bilgisayarla çözümünde kullanılan programlarda sayısal integrasyon yöntemlerinin
kullanılması kaçınılmazdır. Gerçekte analitik integral, sayısal integrale göre çözülebilme
kolaylığı ve sonucunun kesinliği ile üstünlük gösterir. Uzunluk, alan, hacim, enerji, ... gibi
pekçok büyüklüğün hesabında tek ve çok katlı integrasyondan yararlanılır. Bu bölümde bu gibi
amaçlar için kullanılabilecek tek ve çok katlı belirli integrallerin sayısal çözüm yöntemleri
açıklanmıştır.</br>

En basit tanımıyla, bir f(x) fonksiyonunun [a,b] aralığındaki integrali f(x) fonksiyonu ile x
ekseni arasında kalan, a ve b ile sınırlanan alandır.</br>

![image](https://user-images.githubusercontent.com/81113873/112179840-14b78600-8c0c-11eb-83af-61d9d13e7aa9.png)

Nümerik integrasyonda temel fikir, alanı küçük alt alanlara bölmek, alt alanların her birini
yaklaşık olarak hesaplamak ve bu alanları toplamaktan ibarettir.

Yapmış olduğu kodlamada kullandığım yöntemler ise şu şekildedir:</br>
* Dikdörtgen Kuralı</br>
* Dikdörtgen Orta Nokta Kuralı</br>
* Yamuk(Trapez) Kuralı</br>
* Simpson Kuralı</br>

### Dikdörtgen Kuralı</br>
![image](https://user-images.githubusercontent.com/81113873/112180446-9effea00-8c0c-11eb-928a-ac54c0f2d36b.png)

### Dikdörtgen Orta Nokta Kuralı</br>
![image](https://user-images.githubusercontent.com/81113873/112180551-b63ed780-8c0c-11eb-9cbc-d439e9d4fd9e.png)

### Yamuk(Trapez) Kuralı</br>
![image](https://user-images.githubusercontent.com/81113873/112180613-c35bc680-8c0c-11eb-8606-c70fb54124f5.png)

### Simpson Kuralı</br>
![image](https://user-images.githubusercontent.com/81113873/112180681-cf478880-8c0c-11eb-9e5a-c78e2a6d3e45.png)

## Proje Özellikleri / Project Features
* 4 farklı yöntemden herhangi birini seçerek hesaplama yaptırabilme.</br>
* Girilen ifadenin polinom olup olmadığının kontrolü.</br>
* Polinomdaki katsayı, üs ve sabit değerlerin kaç basamaklı olursa olsun algılanabilmesi.</br>

## Projeyi Çalıştırma / Running the Project
* Proje aşağıdaki gibi derlendikten sonra çalıştırılmadan önce argümanlar girilmelidir.</br>
```
gcc main.c -o out
```
* Argümanların sırası ve anlamları aşağıda açıklanmıştır.</br>
1- Hesaplanacak polinom ifadesi</br>
2- İntegralin başlangıç değeri</br>
3- İntegralin bitiş değeri</br>
4- Girilen polinom kaç adıma ayrılarak çözülecek</br>
5- Hangi integral alma yöntemi kullanılacak</br>
    - Dikdörtgen Kuralı(0 numarası ile temsil edilir.)</br>
    - Dikdörtgen Orta Nokta Kuralı(1 numarası ile temsil edilir.</br>
    - Yamuk(Trapez) Kuralı(2 numarası ile temsil edilir.)</br>
    - Simpson Kuralı(3 numarası ile temsil edilir.)</br>

* Argümanları obje dosyamız ile çalıştırmak için aşağıdaki komutu uygulayabiliriz.
```
./out 3x^4+2x^2+10 0 3 1000 1
```
* Örnek olarak derleme ve çalıştırma yaparak sonucu görelim.
```
gcc main.c -o out
```
```
./out 3x^4+2x^2+10 0 3 1000 1
```
```
Girilen Polinom Ifadesi :3x^4+2x^2+10
Baslangic Degeri        :0.00 
Bitis Degeri            :3.00
Parcalama Miktari       :1000
Hangi Yontem            :Dikdortgen Orta Nokta Kurali
1.Terimin Katsayi Degeri:3
1.Terimin Us Degeri     :4
2.Terimin Katsayi Degeri:2
2.Terimin Us Degeri     :2
Sabit Sayi Degeri       :10
Integralin Sonucu       :193.80
```
