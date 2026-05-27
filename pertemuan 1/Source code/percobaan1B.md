 Laporan Praktikum Sistem Mikrokontroler - Percobaan 1B

## Alat dan Bahan
- Arduino Uno
- Resistor 220ohm
- LED 7 buah
- Kabel Jumper & Breadboard

## Kode Program (modul1_percobaan1.ino)
```cpp
int timer = 100;    // delay. Semakin tinggi angkanya, semakin lambat waktunya. 
void setup() { 
// gunakan loop for untuk menginisialisasi setiap pin sebagai output: 
    for (int ledPin = 2; ledPin < 8; ledPin++) { 
        pinMode(ledPin, OUTPUT); 
    } 
} 
void loop() {     // looping dari pin rendah ke tinggi 
    for (int ledPin = 2; ledPin < 8; ledPin++) { 
    // hidupkan LED pin nya: 
        digitalWrite(ledPin, HIGH); 
        delay(timer); 
    // matikan pin LED nya: 
        digitalWrite(ledPin, LOW); 
    } 

    // looping dari pin yang tinggi ke yang rendah 
    for (int ledPin = 7; ledPin >= 2; ledPin--) { 
    // menghidupkan pin: 
        digitalWrite(ledPin, HIGH); 
        delay(timer); 
    // mematikan pin: 
        digitalWrite(ledPin, LOW); 
    } 
} 
```

## Pertanyaan Percobaan 1B
1. Jelaskan bagaimana program membuat efek LED berjalan dari kiri ke kanan! \
Jawab: Program menyalakan LED secara bergantian dan berurutan menggunakan perintah `digitalWrite(pin, HIGH)` yang disertai jeda `delay()`, kemudian LED dimatikan kembali sebelum program melanjutkan ke pin digital berikutnya yang berada di sisi kanan, misalnya dari Pin 2 hingga Pin 7.
2. Jelaskan bagaimana program membuat LED kembali dari kanan ke kiri! \
Jawab: Proses ini merupakan kebalikan dari urutan sebelumnya. Program menjalankan nomor pin digital dari nilai terbesar ke terkecil, misalnya dari Pin 7 menuju Pin 2, dengan pola nyala–jeda–mati yang sama. Akibatnya, secara visual cahaya LED tampak bergerak mundur ke arah kiri.
3. Buatkan program agar LED menyala tiga LED kanan dan tiga LED kiri secara bergantian 
dan berikan penjelasan disetiap baris kode nya. \
Jawab: 
```cpp
void setup() {
  // Mengatur Pin 2 sampai 7 sebagai OUTPUT
  for (int i = 2; i <= 7; i++) { pinMode(i, OUTPUT); }
}

void loop() {
  // --- FASE 1: 3 LED Kiri NYALA, 3 LED Kanan MATI ---
  digitalWrite(2, HIGH); digitalWrite(3, HIGH); digitalWrite(4, HIGH); // Nyalakan kelompok kiri
  digitalWrite(5, LOW);  digitalWrite(6, LOW);  digitalWrite(7, LOW);  // Matikan kelompok kanan
  delay(1000); // Tahan kondisi selama 1 detik

  // --- FASE 2: 3 LED Kiri MATI, 3 LED Kanan NYALA ---
  digitalWrite(2, LOW);  digitalWrite(3, LOW);  digitalWrite(4, LOW);  // Matikan kelompok kiri
  digitalWrite(5, HIGH); digitalWrite(6, HIGH); digitalWrite(7, HIGH); // Nyalakan kelompok kanan
  delay(1000); // Tahan kondisi selama 1 detik
}
```
Program membagi 6 LED menjadi dua kelompok, yaitu kiri (Pin 2–4) dan kanan (Pin 5–7). Pada fungsi `loop()`, LED kiri dinyalakan sementara LED kanan dimatikan selama 1 detik, kemudian kondisinya dibalik selama 1 detik. Proses ini berulang terus sehingga menghasilkan efek nyala bergantian antara sisi kiri dan kanan.
