# Çift Bağlı Liste Uygulaması

Bu uygulama, C dilinde yazılmış bir **çift bağlı liste** (Doubly Linked List) kullanarak öğrenci bilgilerini ekleme, silme, arama ve listeleme işlemleri yapmaktadır. Uygulama, öğrenci numarası, adı, soyadı, bölümü ve sınıfı içeren düğümleri yönetebilmektedir.

---

## Özellikler

- **Liste Oluşturma**: Başlangıçta boş bir liste oluşturma.
- **Listeyi Yok Etme**: Listeyi ve içindeki tüm düğümleri silme.
- **Düğüm Ekleme**: Listeye yeni bir öğrenci ekleme.
- **Düğüm Silme**: Öğrenci numarasına göre bir öğrenciyi listeden silme.
- **Düğüm Arama**: Öğrenci numarasına göre bir öğrenci arama.
- **Listeyi Görüntüleme**: Listeyi eklenen tüm öğrencilerle birlikte ekranda gösterme.

---

## Kullanım

### Menüler ve Seçenekler

1. **Liste oluştur**: Boş bir çift bağlı liste oluşturur.
2. **Listeyi yok et**: Listede bulunan tüm öğrencileri siler ve listeyi yok eder.
3. **Düğüm ekle**: Yeni bir öğrenci kaydı ekler. Öğrenci bilgileri (Öğrenci numarası, adı, soyadı, bölümü, sınıfı) kullanıcıdan alınır.
4. **Düğüm sil**: Öğrenci numarasına göre bir öğrenci kaydını siler.
5. **Düğüm ara**: Öğrenci numarasına göre bir öğrenci kaydını arar.
6. **Listeyi göster**: Mevcut listeyi ekranda gösterir.
7. **Çıkış**: Uygulamadan çıkış yapar ve listeyi yok eder.

### Uygulama Akışı

1. Program başladığında kullanıcıya bir menü sunulur.
2. Kullanıcı, menüdeki seçeneklerden birini seçerek işlemlerini gerçekleştirebilir.
3. Seçilen işlem tamamlandığında kullanıcı tekrar menüye yönlendirilir.
4. Çıkış seçeneği ile uygulama sonlandırılabilir.

---

## Kod Yapısı

- **Node Yapısı**: Her öğrenci kaydını temsil eden bir düğüm yapısı (Node). Bu yapıda öğrenci numarası, adı, soyadı, bölümü, sınıfı ve bağlantılar (prev, next) yer almaktadır.
- **create_node()**: Yeni bir öğrenci düğümü oluşturur.
- **create_list()**: Listeyi oluşturur (başlangıçta boş).
- **destroy_list()**: Listeyi yok eder ve tüm düğümleri serbest bırakır.
- **add_node()**: Yeni bir öğrenci kaydı ekler.
- **delete_node()**: Öğrenci numarasına göre bir öğrenci kaydını siler.
- **search_node()**: Öğrenci numarasına göre bir kaydı arar.
- **display_list()**: Listeyi ekrana yazdırır.

---

