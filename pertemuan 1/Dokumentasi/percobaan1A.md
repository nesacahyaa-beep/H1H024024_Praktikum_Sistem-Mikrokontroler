# Dokumentasi Praktikum 1A

![Percobaan1A](<Percobaan1A.jpg>)

## Komponen
1. Arduino Uno R3: Berperan sebagai unit pemroses utama untuk mengendalikan pin digital (Output) guna mengatur kondisi menyala atau mati pada LED sesuai dengan program (Blink).
2. LED Kuning (Output): Bertindak sebagai komponen output visual yang akan menyala ketika menerima sinyal HIGH (5V) dari pin digital Arduino.
3. Resistor: Berfungsi sebagai pembatas arus (current limiter) untuk melindungi LED agar tidak rusak atau terbakar akibat arus berlebih.
4. Breadboard & Kabel Jumper: Jalur perakitan komponen serta distribusi sinyal digital kontrol dan jalur Ground (GND).

## Penjelasan Dokumentasi
1. Sinyal Output: Kabel jumper berwarna putih terhubung dari Pin Digital 13 Arduino (terindikasi dari built-in LED 'L' yang menyala) menuju ke baris input resistor pada breadboard, yang kemudian arusnya dilewatkan ke kaki positif (anode) LED kuning.
2. Jalur Ground (GND): Kabel jumper merah terhubung dari pin GND di sisi digital Arduino menuju breadboard, yang kemudian dijumper ke jalur kolom negatif (rail biru). Dari rail biru, kabel jumper ungu meneruskan koneksi ke kaki negatif (cathode) LED untuk menutup rangkaian elektronika.
3. Power: Sistem mendapatkan suplai daya utama sebesar 5V secara aman dari port USB laptop yang terhubung langsung ke Arduino Uno melalui kabel data USB type-B.