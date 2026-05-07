# Dokumentasi Praktikum 4B

![Percobaan4B](<Percobaan 4B.jpeg>)

## Komponen
1. Arduino Uno R3: Berperan sebagai unit pemroses utama untuk membaca input analog dan mengontrol dua jenis output (mekanik dan visual).
2. Potensiometer (Analog Input): Digunakan sebagai pembagi tegangan variabel untuk mengatur posisi servo dan status nyala LED melalui pin A0.
3. Motor Servo SG90 (Output 1): Bertindak sebagai aktuator yang bergerak (0° - 180°) sesuai dengan hasil konversi nilai potensiometer.
4. LED (Output 2): Berperan sebagai indikator visual tambahan yang intensitas atau statusnya (ON/OFF) dikontrol berdasarkan nilai input analog.
5. Breadboard & Jumper Wires: Jalur distribusi daya serta penghubung sinyal antar komponen.

## Penjelasan Dokumentasi
1. Input: Pin tengah potensiometer terhubung ke pin A0 Arduino untuk membaca perubahan tegangan analog (0-1023).
2. Output 1 (Servo) : Kabel sinyal servo (warna oranye) terhubung ke pin 9 (PWM) untuk menerima instruksi posisi sudut.
3. Output 2 (LED): Kaki positif (anoda) LED terhubung ke salah satu pin digital (seperti pin 13) untuk memberikan respon visual saat sistem bekerja.
4. Power: Seluruh komponen mendapatkan suplai daya 5V dan GND yang stabil dari Arduino melalui *rail* distribusi pada breadboard.