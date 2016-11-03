Make komutu çalıştırıldığında ilk olarak "harici.c" dosyası derlenir ve
çalıştırılabilir dosya oluşturulur. Bunun yapılmasının nedeni ana programın
icrası esnasında "harici" çalıştırılabilir dosyasına ihtiyaç duymasıdır.

Ana program çalıştırıldığında kullanıcıdan tam sayı tipinde bir değer alır.
Değerin istenildiği mesaj ile beraber ekrana işlemin ebeveyn işlem olduğu bilgisi
de verilir. Bu değer girildiğinde program fork komutu ile iki uca çatallanır.
Ebeveyn işlem wait komutu ile yavru işlemin sonlanması için beklemeye geçer.

Çatallamadan sonra yavru işlem exec komutu ile "harici" programını çağırır.
Program işlemi gerçekleştirebilmek için gereken sayıyı komut satırı parametresi
olarak alır. Bu parametre yavru işlem tarafından exec komutuna parametre olarak
girilir. Parametre olarak gönderilecek olan sayı ana program çalıştıktan sonra
kullanıcıdan alınan değerdir.

harici programı çalıştırıldığında gelen parametredeki karakter dizisinden anlamlı
sayı değerini alır. Bu sayıya kadar olan pozitif çift sayıların toplamını veren
matematiksel işlemi gerçekleştirir ve sonucu ekrana yazdırır.
Sonrasında yavru işlemin icrasını tamamladığını ekrana yazdırır.
Bu iki ekran mesajında da yavru işlem tarafından gerçekleştirildiği bilgisi yer alır.

harici programı icrasını tamamladığında yavru işlem de tamamlanmış olur.
Ebeveyn program bekleme modundan çıkar ve programın sonlandırılacağını bildiren
mesajı ebeveyn işlem tarafından yazıldığı bilgisi ile beraber ekrana yazdırır.
