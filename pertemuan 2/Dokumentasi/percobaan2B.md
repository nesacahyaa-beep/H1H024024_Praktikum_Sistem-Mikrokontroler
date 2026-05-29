# Dokumentasi Praktikum 2B

![Percobaan2B](<Percobaan2B.jpg>)

## Komponen
1. Arduino Uno R3: Berperan sebagai unit pemroses utama untuk membaca input digital dari tombol tekan (push button) dan mengontrol pola nyala LED pada 7-segment.
2. Single-Digit 7-Segment Display (Output): Bertindak sebagai penampil visual angka atau karakter, yang nilainya berubah secara dinamis berdasarkan interaksi tombol.
3. Push Button / Tactile Switch (Input): Berfungsi sebagai sakelar tombol tekan digital untuk memberikan instruksi kontrol (misalnya tombol untuk menambah/mengurangi angka atau mereset hitungan).
4. Resistor: Digunakan sebagai resistor pembatas arus atau pembentuk logika (pull-up/pull-down) pada rangkaian tombol agar pembacaan pin digital tetap stabil.
5. Breadboard & Jumper Wires: Jalur distribusi daya (5V dan GND) serta jalur transmisi sinyal data antar komponen.

## Penjelasan Dokumentasi
1. Input: Jalur kabel dari salah satu kaki masing-masing push button terhubung ke pin Digital Arduino yang dikonfigurasi sebagai input, dilengkapi dengan resistor untuk menjaga kestabilan logika saat tombol ditekan atau dilepas.
2. Output: Bundel kabel jumper berwarna-warni menghubungkan deretan pin Digital Arduino secara langsung ke pin segmen (A-G) pada komponen 7-segment untuk mengontrol visualisasi karakter (seperti angka '4' yang sedang menyala pada foto).
3. Power: Seluruh komponen mendapatkan suplai tegangan kerja dan ground melalui jalur rail positif (+) dan negatif (-) breadboard yang dijumper langsung dari pin 5V dan GND pada board Arduino Uno.