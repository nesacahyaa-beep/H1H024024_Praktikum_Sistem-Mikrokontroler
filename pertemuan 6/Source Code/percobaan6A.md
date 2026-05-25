# Laporan Praktikum Sistem Mikrokontroler - Percobaan 6A

## Alat dan Bahan
- Arduino Uno
- LED 2
- Push Button
- Resistor 220ohm
- Resistor 10kohm
- Kabel Jumper & Breadboard

## Kode Program (modul6_percobaan1.ino)
```cpp
#include <Arduino.h>

// Variabel volatile agar dapat diubah dalam ISR
volatile bool ledState = false;

// ISR: dijalankan saat tombol ditekan
void tombolInterrupt() {
  ledState = !ledState; // Toggle status LED
}

void setup() {

  // Konfigurasi pin 13 sebagai output (LED)
  pinMode(13, OUTPUT);

  // Konfigurasi pin 2 sebagai input pull-up
  pinMode(2, INPUT_PULLUP);

  // Daftarkan interrupt pada pin 2
  attachInterrupt(
    digitalPinToInterrupt(2),
    tombolInterrupt,
    FALLING
  );
}

void loop() {

  // Menulis status LED sesuai variabel ledState
  digitalWrite(13, ledState);

}
```

## Pertanyaan Percobaan 6A
1. Jelaskan proses bagaimana tombol dapat mengubah kondisi LED menggunakan interrupt! \
Jawab: Proses perubahan kondisi LED dengan menggunakan interrupt terjadi secara otomatis melalui mekanisme perangkat keras tanpa perlu melakukan pengecekan status pin secara terus-menerus (polling). Ketika tombol ditekan, perubahan tegangan pada pin input akan menghasilkan sinyal interupsi yang secara langsung memicu mikrokontroler untuk menghentikan sementara proses yang sedang berjalan pada program utama di dalam loop().
Setelah itu, mikrokontroler segera menjalankan fungsi khusus yang disebut Interrupt Service Routine (ISR) untuk menangani perubahan kondisi, misalnya dengan mengubah status variabel LED. Setelah proses dalam ISR selesai dieksekusi, sistem akan kembali melanjutkan eksekusi program utama yang sebelumnya tertunda, sehingga alur kerja sistem tetap berjalan secara efisien dan responsif.
2. Apa fungsi attachInterrupt() pada program tersebut? \
Jawab:Fungsi `attachInterrupt()` digunakan untuk menginisialisasi serta mengaktifkan fitur interrupt eksternal pada pin tertentu di Arduino. Fungsi ini berperan dalam menghubungkan peristiwa fisik yang terjadi pada pin input dengan fungsi penanganan khusus yang disebut Interrupt Service Routine (ISR) yang telah didefinisikan oleh pengguna.
3. Mengapa pada ISR tidak disarankan menggunakan delay() dan Serial.print()? \
Jawab:Penggunaan `delay()` dan `Serial.print()` di dalam ISR (Interrupt Service Routine) sangat tidak disarankan karena ISR harus dijalankan secepat mungkin agar tidak mengganggu alur kerja sistem utama. Fungsi `delay()` bekerja menggunakan timer internal yang bergantung pada interrupt, sedangkan saat ISR sedang berjalan, interrupt lain umumnya dinonaktifkan sementara. Akibatnya, proses penghitungan waktu pada `delay()` dapat terhenti dan berpotensi menyebabkan program menjadi tidak responsif atau mengalami freeze.
Selain itu, `Serial.print()` juga kurang tepat digunakan dalam ISR karena proses pengiriman data serial membutuhkan waktu eksekusi yang relatif lama serta bergantung pada interrupt untuk mengelola buffer komunikasi. Kondisi ini dapat menyebabkan penumpukan data, keterlambatan eksekusi, bahkan berisiko menimbulkan deadlock atau gangguan pada sistem jika digunakan di dalam ISR.
4. Apa fungsi keyword volatile pada variabel ledState? \
Jawab:Keyword `volatile` pada variabel `ledState` digunakan untuk memberi tahu compiler bahwa nilai variabel tersebut dapat berubah sewaktu-waktu di luar alur eksekusi program utama, misalnya melalui Interrupt Service Routine (ISR). Dengan adanya keyword ini, compiler akan menghindari optimasi yang dapat menyimpan nilai variabel ke dalam register CPU.
Sebagai gantinya, Arduino akan selalu membaca nilai variabel secara langsung dari memori utama (RAM) setiap kali variabel tersebut diakses. Hal ini bertujuan untuk mencegah terjadinya ketidaksinkronan data antara program utama dan ISR, serta memastikan bahwa nilai yang digunakan selalu merupakan nilai terbaru yang telah diperbarui oleh interupsi.
5. Pada percobaan digunakan mode interrupt FALLING. Modifikasikan program 
menggunakan mode interrupt lain (RISING, CHANGE, atau LOW) kemudian: 
• Jelaskan perbedaan cara kerja masing-masing mode interrupt tersebut \
Jawab: Mode FALLING dan RISING pada interrupt digunakan untuk memicu interupsi hanya pada saat terjadi perubahan kondisi tertentu pada sinyal input. Mode FALLING akan memicu interrupt ketika terjadi transisi tegangan dari HIGH ke LOW (misalnya saat tombol ditekan), sedangkan mode RISING akan memicu interrupt ketika terjadi transisi dari LOW ke HIGH (misalnya saat tombol dilepas).
Sementara itu, mode CHANGE akan memicu interrupt pada kedua kondisi transisi tersebut, yaitu baik saat sinyal berubah dari HIGH ke LOW maupun dari LOW ke HIGH. Berbeda dengan itu, mode LOW akan memicu interrupt secara terus-menerus selama kondisi tegangan pada pin tetap berada pada level LOW.
• Analisis perubahan perilaku LED yang terjadi pada setiap mode \
Jawab: Pada mode `RISING`, LED hanya berubah saat tombol dilepas. Mode `CHANGE` membuat LED berubah setiap kali tombol ditekan dan dilepas, sedangkan mode `LOW` menyebabkan LED berkedip cepat atau tidak stabil karena interrupt terus aktif selama tombol ditekan.
• Sertakan source code dan penjelasan program. \
Jawab:Perubahan dari `FALLING` ke `CHANGE` membuat Arduino pada Pin 2 mendeteksi setiap perubahan sinyal. Jika sebelumnya hanya merespons saat tegangan turun dari HIGH ke LOW, kini interrupt akan aktif pada kedua kondisi, yaitu saat tombol ditekan maupun saat dilepas.
