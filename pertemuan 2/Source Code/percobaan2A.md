# Laporan Praktikum Sistem Mikrokontroler - Percobaan 4A

## Alat dan Bahan
- Arduino Uno
- Push Button
- Seven Segment
- Resistor 220ohm
- Kabel Jumper & Breadboard

## Kode Program (modul4_percobaan1.ino)
```cpp
#include <Arduino.h>

// 7-Segment Common Anode

// Pin mapping segment: a b c d e f g dp
const int segmentPins[8] = {7, 6, 5, 11, 10, 8, 9, 4};

byte digitPattern[16][8] = {
  {1,1,1,1,1,1,0,0}, //0
  {0,1,1,0,0,0,0,0}, //1
  {1,1,0,1,1,0,1,0}, //2
  {1,1,1,1,0,0,1,0}, //3 
  {0,1,1,0,0,1,1,0}, //4
  {1,0,1,1,0,1,1,0}, //5
  {1,0,1,1,1,1,1,0}, //6
  {1,1,1,0,0,0,0,0}, //7
  {1,1,1,1,1,1,1,0}, //8
  {1,1,1,1,0,1,1,0}, //9
  {1,1,1,0,1,1,1,0}, //A
  {0,0,1,1,1,1,1,0}, //b
  {1,0,0,1,1,1,0,0}, //C
  {0,1,1,1,1,0,1,0}, //d
  {1,0,0,1,1,1,1,0}, //E
  {1,0,0,0,1,1,1,0}  //F
};

// Fungsi tampil digit (dibalik untuk CA)
void displayDigit(int num)
{
  for(int i=0; i<8; i++)
  {
    digitalWrite(segmentPins[i], !digitPattern[num][i]); // <-- dibalik
  }
}

void setup()
{
  for(int i=0; i<8; i++)
  {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop()
{
  for(int i=0; i<16; i++)
  {
    displayDigit(i);
    delay(1000);
  }
}
```

## Pertanyaan Percobaan 2A
1. Apa yang terjadi jika nilai num lebih dari 15? \
Jawab: Apabila nilai variabel num melebihi 15, tampilan pada 7-segment akan dipengaruhi oleh logika yang digunakan dalam program. Jika program memakai array standar dengan 16 elemen (indeks 0–15 untuk menampilkan karakter 0–F), maka nilai yang lebih besar dari 15 dapat memicu error index out of bounds. Akibatnya, tampilan 7-segment bisa menjadi tidak sesuai, mati, atau menunjukkan data acak yang berasal dari memori. Sebaliknya, apabila program dilengkapi mekanisme pembatas atau reset nilai, misalnya mengembalikan nilai ke 0, maka tampilan akan mengulang kembali dari awal secara normal.
2. Apakah program ini menggunakan common cathode atau common anode? Jelaskan alasanya! \
Jawab: Rangkaian pada gambar menggunakan jenis Common Cathode (katoda bersama). Identifikasi ini terlihat dari kabel jumper hitam yang menghubungkan pin common pada 7-segment (pin tengah) langsung ke pin GND pada Arduino Uno. Dalam konfigurasi Common Cathode, seluruh kaki katoda LED pada 7-segment terhubung menjadi satu ke Ground, sehingga setiap segmen akan menyala saat pin digital Arduino mengirimkan sinyal logika HIGH (5V).
3. Modifikasi program agar tampilan berjalan dari F ke 0 dan berikan penjelasan disetiap baris kode nya. \
Jawab: 
```cpp
void loop() {
  // Melakukan perulangan mundur dari indeks 15 (F) hingga indeks 0 (0)
  for (int num = 15; num >= 0; num--) {
    
    // Memanggil fungsi untuk menyalakan segmen sesuai data pola angka/huruf dari array
    tampilkanAngka(num); 
    
    // Memberikan jeda waktu selama 1000 milidetik (1 detik) sebelum berganti ke karakter berikutnya
    delay(1000); 
  }
}
```
Program dimodifikasi dengan mengubah perulangan `for` menjadi hitung mundur. Variabel `num` diawali dari 15 (karakter F) dengan kondisi `num >= 0`, lalu nilainya dikurangi menggunakan operator `num--`. Perubahan ini membuat Arduino membaca array 7-segment secara terbalik sehingga tampilan berjalan mundur dari F ke 0.