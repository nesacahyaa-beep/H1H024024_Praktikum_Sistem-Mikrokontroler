# Laporan Praktikum Sistem Mikrokontroler - Percobaan 1A

## Alat dan Bahan
- Arduino Uno
- Resistor 220ohm
- LED 7 buah
- Kabel Jumper & Breadboard

## Kode Program (modul1_percobaan1.ino)
```cpp
const int ledPin = 6; 
int timeDelay = 1000; 

void setup() { 
pinMode(ledPin, OUTPUT); 
} 

void loop() { 
    // Nyalakan LED 
    digitalWrite(ledPin, HIGH); 
    delay(timeDelay); 
    
    // Matikan LED 
    digitalWrite(ledPin, LOW); 
    delay(timeDelay); 

    // Baru ubah delay (setelah 1 siklus kedip) 
    if (timeDelay <= 100) { 
    delay(3000);        // jeda sebelum reset 
    timeDelay = 1000;   // reset ke awal 
    } else { 
    timeDelay -= 100;   // percepatan bertahap 
    }
}
```

## Pertanyaan Percobaan 1A
1. Pada kondisi apa program masuk ke blok if? \
Jawab: Program akan menjalankan blok if ketika kondisi atau ekspresi logika yang terdapat di dalam tanda kurung if (...) menghasilkan nilai benar (true). Dalam pemrograman Arduino, hal ini terjadi apabila variabel, kondisi pin, maupun hasil perhitungan memenuhi kriteria atau syarat tertentu yang telah ditetapkan sebelumnya.
2. Pada kondisi apa program masuk ke blok else? \
Jawab: Program akan menjalankan blok else ketika seluruh kondisi pada blok if (serta else if apabila ada) menghasilkan nilai salah (false). Blok ini berfungsi sebagai alternatif otomatis untuk mengeksekusi perintah ketika tidak ada kondisi utama yang memenuhi syarat.
3. Apa fungsi dari perintah delay(timeDelay)? \
Jawab: Perintah `delay(timeDelay);` digunakan untuk menghentikan sementara proses eksekusi program selama waktu tertentu yang diukur dalam satuan milidetik (seperseribu detik) sesuai dengan nilai pada variabel timeDelay. Pada rangkaian LED, jeda ini berfungsi mempertahankan kondisi LED, baik saat HIGH maupun LOW, sehingga pola nyala dan matinya dapat terlihat dengan jelas oleh penglihatan manusia.
4. Jika program yang dibuat memiliki alur mati → lambat → cepat → reset (mati), 
ubah menjadi LED tidak langsung reset → tetapi berubah dari cepat → sedang → 
mati dan berikan penjelasan disetiap baris kode nya \
Jawab: 
```cpp
void loop() {
  digitalWrite(ledPin, LOW);   delay(1000); // 1. Mati
  
  digitalWrite(ledPin, HIGH);  delay(1000); // 2. Lambat
  digitalWrite(ledPin, LOW);   delay(1000);
  
  digitalWrite(ledPin, HIGH);  delay(200);  // 3. Cepat
  digitalWrite(ledPin, LOW);   delay(200);
  
  digitalWrite(ledPin, HIGH);  delay(500);  // 4. Sedang (Tambahan Modifikasi)
  digitalWrite(ledPin, LOW);   delay(500);
}
```
Menambahkan kode Fase Sedang menggunakan delay(500) setelah fase cepat. Penambahan ini membuat perubahan pola kedipan LED berlangsung lebih bertahap, yaitu dari kondisi cepat → sedang → mati, sebelum program kembali mengulang dari awal, sehingga transisi tidak terjadi secara tiba-tiba langsung menuju kondisi mati.