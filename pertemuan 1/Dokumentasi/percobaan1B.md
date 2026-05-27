# Dokumentasi Praktikum 1B

![Percobaan1B](<Percobaan1B.jpg>)

## Komponen
1. Arduino Uno R3: Berperan sebagai unit pemroses utama untuk mengendalikan beberapa pin digital (Output) secara sekuensial atau bersamaan guna mengatur pola menyala beberapa LED (seperti pola Running LED / Traffic Light).
2. Multi-LED (Merah, Kuning, Hijau) (Output): Bertindak sebagai komponen output visual multi-kanal yang menampilkan indikasi status atau variasi pola pencahayaan sesuai dengan algoritma program.
3. Resistor: Berfungsi sebagai pembatas arus (current limiter) pada masing-masing jalur LED untuk memastikan setiap komponen bekerja pada batas arus yang aman.
4. Breadboard & Kabel Jumper: Jalur perakitan kompleks untuk mendistribusikan banyak sinyal kontrol digital secara paralel serta mengabungkan seluruh kaki katode ke jalur Ground bersama (Common Ground).

## Penjelasan Dokumentasi
1. Sinyal Output: Deretan kabel jumper dengan berbagai warna (kuning, putih, merah, biru) dihubungkan dari pin-pin digital output Arduino secara berurutan menuju ke baris anode masing-masing LED melalui resistor pembatas arus di breadboard.
2. Jalur Ground (GND): Seluruh kaki negatif (cathode) dari setiap LED dihubungkan ke kolom negatif (rail biru) breadboard secara paralel. Jalur rail negatif ini kemudian dihubungkan kembali ke pin GND (Ground) Arduino menggunakan kabel jumper untuk menutup loop aliran arus listrik.
3. Power: Board Arduino beserta seluruh rangkaian LED menerima suplai tegangan kerja stabil sebesar 5V yang dialirkan langsung melalui kabel USB type-B yang terhubung ke laptop.