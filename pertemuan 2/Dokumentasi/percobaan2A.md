# Dokumentasi Praktikum 2A

![Percobaan2A](<Percobaan2A.jpg>)

## Komponen
1. Arduino Uno R3: Berperan sebagai unit pemroses utama yang menjalankan kode program dan menghasilkan sinyal output digital untuk menyalakan LED pada display.
2. Single-Digit 7-Segment Display (Output): Bertindak sebagai komponen penampil visual yang menyala membentuk angka atau karakter tertentu sesuai dengan sinyal yang diterima dari Arduino.
3. Breadboard: Papan prototyping yang digunakan untuk menancapkan komponen 7-segment agar mudah dihubungkan dengan kabel.
4. Kabel Jumper (Male-to-Male): Berfungsi sebagai jalur transmisi sinyal dari pin Arduino ke pin 7-segment, serta jalur distribusi Ground (GND).
## Penjelasan Dokumentasi
1. Output (Sinyal Data): Kabel-kabel jumper berwarna-warni menghubungkan deretan pin Digital pada Arduino (seperti pin 2 hingga 8) ke masing-masing pin segmen (A, B, C, D, E, F, G) pada 7-segment display. Kombinasi sinyal HIGH/LOW dari pin ini yang akan membentuk angka/huruf.
2. Power / Ground: Kabel jumper berwarna hitam menghubungkan pin GND pada Arduino ke pin Common (pin tengah) pada 7-segment display untuk melengkapi sirkuit kelistrikan (rangkaian ini kemungkinan menggunakan konfigurasi Common Cathode).
3. Pada gambar dokumentasi tersebut, pin 7-segment dihubungkan secara langsung ke pin mikrokontroler Arduino. Untuk keamanan jangka panjang dan mencegah kerusakan LED, sangat disarankan untuk menambahkan resistor pembatas arus (misal: 220Ω atau 330Ω) di antara pin digital Arduino dan pin input 7-segment.