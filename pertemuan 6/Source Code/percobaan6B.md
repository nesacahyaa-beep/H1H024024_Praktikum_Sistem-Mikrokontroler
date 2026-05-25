# Laporan Praktikum Sistem Mikrokontroler - Percobaan 6B

## Alat dan Bahan
- Arduino Uno
- LED 2
- Push Button
- Resistor 220ohm
- Resistor 10kohm
- Kabel Jumper & Breadboard

## Kode Program (modul6_percobaan2.ino)
```cpp
#include <Arduino.h>

unsigned long previousMillis = 0; // Waktu terakhir LED berubah
const long interval = 1000;       // Interval kedip 1 detik

bool ledState = false;            // Status LED

void setup() {

  // Pin 13 sebagai output
  pinMode(13, OUTPUT);

}

void loop() {

  // Ambil waktu saat ini
  unsigned long currentMillis = millis();

  // Cek apakah interval sudah tercapai
  if (currentMillis - previousMillis >= interval) {

    // Simpan waktu sekarang
    previousMillis = currentMillis;

    // Toggle LED
    ledState = !ledState;

    // Tulis ke LED
    digitalWrite(13, ledState);
  }

}
```

## Pertanyaan Percobaan 6B
1. Jelaskan bagaimana fungsi millis() bekerja pada program tersebut! \
Jawab: Fungsi `millis()` bekerja sebagai penghitung waktu internal yang mencatat waktu dalam milidetik sejak Arduino dinyalakan. Program memanfaatkannya dengan membandingkan waktu saat ini dengan waktu terakhir aksi dilakukan. Jika selisih waktunya telah mencapai interval yang ditentukan, maka kondisi LED akan berubah tanpa menghentikan proses program lainnya.
2. Apa perbedaan utama antara delay() dan millis()? \
Jawab: Perbedaan utama keduanya terletak pada cara kerja CPU. Fungsi `delay()` bersifat blocking karena menghentikan sementara seluruh aktivitas mikrokontroler selama waktu tunggu berlangsung, sedangkan `millis()` bersifat non-blocking karena hanya memeriksa waktu berjalan sehingga Arduino tetap dapat menjalankan tugas atau proses lain secara bersamaan.
3. Mengapa metode millis() disebut non-blocking? \
Jawab:Metode `millis()` disebut non-blocking karena tidak menghentikan jalannya fungsi `loop()` saat menghitung jeda waktu. Program tetap berjalan normal sehingga mikrokontroler dapat menjalankan beberapa tugas sekaligus, seperti membaca sensor atau mengontrol beberapa LED dengan interval berbeda secara bersamaan.
4. Modifikasi program agar: 
• LED pertama berkedip setiap 1 detik 
• LED kedua berkedip setiap 500 ms 
• Tanpa menggunakan delay() 
Berikan penjelasan setiap baris program \
Jawab:Program ini diawali dengan deklarasi pin output, variabel status LED, dan variabel waktu bertipe `unsigned long` untuk menyimpan waktu kedipan masing-masing LED. Di dalam `loop()`, fungsi `millis()` terus membaca waktu berjalan, lalu kondisi `if` memeriksa apakah selisih waktu telah mencapai interval yang ditentukan. Jika terpenuhi, status LED akan dibalik menggunakan operator `!` dan diperbarui melalui `digitalWrite()` tanpa menghentikan jalannya program utama.
