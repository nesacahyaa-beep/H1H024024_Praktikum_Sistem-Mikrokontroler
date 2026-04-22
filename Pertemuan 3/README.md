# Percobaan 3A: Komunikasi Serial (UART) 

## 1. Jelaskan proses dari input keyboard hingga LED menyala/mati! 
Proses diawali ketika pengguna menekan tombol pada keyboard melalui Serial Monitor di komputer, sehingga karakter yang diketik diubah menjadi data digital oleh sistem operasi. Data tersebut kemudian dikirimkan melalui kabel USB menggunakan komunikasi serial (UART) menuju papan Arduino. Sesampainya di Arduino, data tidak langsung diproses, melainkan terlebih dahulu disimpan di dalam memori sementara yang disebut Serial Receive Buffer. Dalam program, fungsi Serial.read() digunakan untuk mengambil data dari buffer tersebut, kemudian data dibandingkan dengan logika kondisi yang telah ditentukan, seperti if atau switch-case. Apabila karakter yang diterima sesuai dengan perintah untuk menyalakan LED, maka mikrokontroler akan memberikan sinyal tegangan sebesar 5V pada pin digital yang terhubung ke LED. Tegangan ini menyebabkan arus listrik mengalir melalui rangkaian hingga ke kaki anoda LED, sehingga energi listrik berubah menjadi energi cahaya dan LED pun menyala.

## 2. Mengapa digunakan Serial.available() sebelum membaca data? Apa yang terjadi jika baris tersebut dihilangkan?
Fungsi Serial.available() memiliki peran penting dalam proses komunikasi data antara komputer dan Arduino, karena berfungsi sebagai pengecek jumlah byte data yang telah diterima dan tersimpan di dalam buffer serial. Ketika nilai yang dihasilkan lebih dari nol, hal tersebut menandakan bahwa terdapat data yang siap untuk diproses oleh program.
Jika fungsi ini tidak digunakan, Arduino akan terus menjalankan Serial.read() pada setiap perulangan (loop), meskipun tidak ada data yang masuk. Kondisi ini dapat menimbulkan masalah, karena Serial.read() akan menghasilkan nilai -1 saat buffer kosong, yang dapat terbaca sebagai data tidak valid atau karakter acak oleh program. Akibatnya, sistem dapat mengalami gangguan seperti LED berkedip tidak stabil, program menjadi tidak responsif, atau perintah dieksekusi secara keliru karena mikrokontroler memproses data yang sebenarnya tidak ada.
Dengan adanya Serial.available(), Arduino hanya akan mengeksekusi pembacaan data ketika benar-benar terdapat informasi di dalam buffer. Hal ini membuat proses kerja mikrokontroler menjadi lebih efisien, stabil, dan terhindar dari kesalahan dalam eksekusi program.

## 3. Modifikasi program agar LED berkedip (blink) ketika menerima input '2' dengan kondisi jika ‘2’ aktif maka LED akan terus berkedip sampai perintah selanjutnya diberikan dan berikan penjelasan disetiap baris kode nya dalam bentuk README.md!
Untuk mendapatkan kondisi di mana LED tetap berkedip secara terus-menerus hingga menerima perintah baru, diperlukan sebuah variabel status (state) yang berfungsi untuk menyimpan kondisi terakhir dari sistem.

## Logika Program
Program ini menggunakan variabel `mode` untuk menyimpan status terakhir yang diterima dari Serial Monitor.

## Kode Program
int ledPin = 13;
char mode = '0'; // Menyimpan status perintah

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Cek input baru tanpa menghapus status lama jika tidak ada input
  if (Serial.available() > 0) {
    mode = Serial.read();
  }

  if (mode == '1') {
    digitalWrite(ledPin, HIGH); // Nyala terus
  } 
  else if (mode == '2') {
    // Mode Blink
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  } 
  else {
    digitalWrite(ledPin, LOW); // Mati
  }
}

## Penjelasan Kode Per Baris
1. `char mode = '0';`: Mendeklarasikan variabel untuk menyimpan perintah terakhir (default '0' atau mati).
2. `void setup()`: Inisialisasi pin 13 sebagai OUTPUT dan memulai komunikasi Serial pada baud rate 9600.
3. `if (Serial.available() > 0)`: Mengecek apakah ada input baru dari keyboard.
4. `mode = Serial.read();`: Jika ada input, variabel `mode` diperbarui dengan karakter baru tersebut.
5. `if (mode == '1')`: Jika mode adalah '1', LED menyala statis.
6. `else if (mode == '2')`: Jika mode adalah '2', LED masuk ke logika blink.
7. `digitalWrite(13, HIGH); delay(500); ...`: Logika kedip dengan jeda 500ms. Karena berada di dalam `loop()`, ini akan berulang terus selama variabel `mode` masih bernilai '2'.
8. `else`: Mematikan LED jika menerima input selain '1' atau '2'.

## 4. Tentukan apakah menggunakan delay() atau milis()! Jelaskan pengaruhnya terhadap sistem 
Untuk sistem seperti ini, sangat disarankan menggunakan fungsi millis() dibandingkan delay().
Perbedaan mendasar keduanya terletak pada cara mereka memengaruhi alur eksekusi program. Fungsi delay() bersifat blocking, yang artinya ketika Arduino menjalankan waktu tunda tersebut, seluruh proses lain akan berhenti sementara. Hal ini membuat sistem menjadi tidak responsif terhadap input dari luar. Misalnya, saat LED sedang berkedip dan program berada dalam fase delay(), perintah baru seperti mematikan LED melalui Serial Monitor bisa saja tidak langsung terbaca atau terlambat diproses.
Sebaliknya, millis() bekerja secara non-blocking, yaitu dengan menghitung waktu yang telah berlalu sejak Arduino mulai berjalan tanpa menghentikan eksekusi program utama. Dengan pendekatan ini, Arduino tetap dapat menjalankan logika lain secara bersamaan, seperti membaca input dari Serial Monitor dan mengatur kedipan LED secara bersamaan berdasarkan selisih waktu yang dihitung.
Penggunaan millis() memungkinkan sistem melakukan proses seperti multitasking sederhana, sehingga Arduino dapat tetap responsif terhadap perintah pengguna secara real-time sambil menjaga pola kedipan LED tetap stabil dan akurat. Hasilnya, program menjadi lebih efisien, responsif, dan lebih andal dalam menangani input secara terus-menerus.


# Percobaan 3B: Inter-Integrated Circuit (I2C)

## 1. Jelaskan bagaimana cara kerja komunikasi I2C antara Arduino dan LCD pada rangkaian tersebut!
Komunikasi I2C (Inter-Integrated Circuit) antara Arduino dan LCD pada rangkaian tersebut bekerja dengan konsep Master–Slave menggunakan dua jalur utama, yaitu SDA (Serial Data) yang terhubung ke pin A4 dan SCL (Serial Clock) pada pin A5. Dalam konfigurasi ini, Arduino berperan sebagai Master yang mengatur seluruh proses komunikasi, sedangkan modul I2C yang terpasang di belakang LCD berfungsi sebagai Slave.
Proses komunikasi diawali ketika Arduino menghasilkan sinyal clock secara terus-menerus melalui jalur SCL sebagai bentuk sinkronisasi agar pengiriman data berlangsung teratur. Setelah itu, Arduino mengirimkan alamat unik dari modul I2C (umumnya 0x27 atau 0x3F) melalui jalur SDA untuk memilih perangkat yang akan diajak berkomunikasi. Ketika modul LCD memberikan respons, koneksi pun terbentuk dan Arduino mulai mengirimkan data berupa instruksi atau karakter teks, seperti “ADC: 356”, secara berurutan bit per bit melalui SDA.
Di sisi modul I2C, data serial yang diterima kemudian diubah menjadi format paralel yang dapat dipahami oleh LCD. Proses ini memungkinkan LCD menampilkan karakter sesuai data yang dikirim oleh Arduino. Dengan sistem ini, jumlah kabel yang dibutuhkan menjadi lebih sedikit, karena komunikasi cukup dilakukan hanya melalui dua jalur utama, sehingga rangkaian menjadi lebih sederhana dan efisien.

## 2. Apakah pin potensiometer harus seperti itu? Jelaskan yang terjadi apabila pin kiri dan pin kanan tertukar! 
Secara prinsip, pin tengah (*wiper*) harus dihubungkan ke pin analog Arduino (misalnya A0) agar perubahan nilai dapat terbaca. Sementara itu, dua pin di sisi kiri dan kanan dihubungkan ke VCC (5V) dan GND. Susunan ini membentuk rangkaian *voltage divider* (pembagi tegangan), di mana posisi pergerakan tuas akan menghasilkan variasi tegangan pada pin analog dari 0V hingga 5V.
Jika terjadi pin kiri dan pin kanan tertukar maka, rangkaian tetap aman dan tidak akan mengalami kerusakan. Perubahan yang terjadi hanya pada arah pembacaan nilainya yang menjadi terbalik (*reverse*). Jika sebelumnya putaran ke kanan (searah jarum jam) menghasilkan peningkatan nilai ADC (dari 0 menuju 1023), maka setelah pin 5V dan GND ditukar, putaran ke kanan justru akan menurunkan nilai ADC (dari 1023 menuju 0).

## 3. Modifikasi program dengan menggabungkan antara UART dan I2C (keduanya sebagai output) 
## Penjelasan Kode Per Baris

```cpp
#include <Wire.h> 
// Memasukkan library Wire untuk komunikasi I2C (SDA/SCL)

#include <LiquidCrystal_I2C.h> 
// Memasukkan library khusus untuk mengontrol LCD via modul I2C

LiquidCrystal_I2C lcd(0x27, 16, 2); 
// Membuat objek 'lcd' dengan alamat I2C 0x27, lebar 16 kolom, dan 2 baris

const int potPin = A0; 
// Mendeklarasikan pin A0 sebagai pin input untuk membaca potensiometer

void setup() {
  Serial.begin(9600); 
  // Memulai komunikasi UART (Serial Monitor) dengan kecepatan 9600 bps

  lcd.init(); 
  // Menginisialisasi layar LCD agar siap menerima perintah

  lcd.backlight(); 
  // Menyalakan lampu latar (backlight) pada layar LCD
}

void loop() {
  int adcValue = analogRead(potPin); 
  // Membaca nilai analog dari potensiometer (rentang 0 - 1023)

  float volt = adcValue * (5.0 / 1023.0); 
  // Menghitung tegangan. Rumus: (Nilai ADC / Resolusi Maksimal) * Tegangan Referensi (5V)

  int persen = map(adcValue, 0, 1023, 0, 100); 
  // Mengonversi skala ADC (0-1023) menjadi skala persentase (0-100) menggunakan fungsi map()

  // --- BLOK UART (SERIAL MONITOR) ---
  Serial.print("ADC: ");
  Serial.print(adcValue);
  Serial.print("\tVolt: "); // \t digunakan untuk memberikan jarak tabulasi
  Serial.print(volt);
  Serial.print(" V\tPersen: ");
  Serial.print(persen);
  Serial.println("%"); // println digunakan agar output selanjutnya pindah ke baris baru bawahnya

  // --- BLOK I2C (LCD DISPLAY) ---
  lcd.setCursor(0, 0); 
  // Mengatur kursor LCD ke baris pertama (0), kolom pertama (0)
  
  lcd.print("ADC:"); 
  lcd.print(adcValue); 
  lcd.print(" "); 
  lcd.print(persen); 
  lcd.print("%   "); 
  // Menampilkan teks "ADC: [nilai] [persen]%". Spasi di akhir digunakan untuk menimpa karakter lama jika nilai digit mengecil

  lcd.setCursor(0, 1); 
  // Mengatur kursor LCD ke baris kedua (1), kolom pertama (0) untuk menggambar Bar

  int barLevel = map(adcValue, 0, 1023, 0, 16); 
  // Memetakan nilai ADC (0-1023) menjadi jumlah blok untuk Bar (0-16 kolom maksimal di LCD)

  for (int i = 0; i < 16; i++) { 
    // Perulangan untuk mengecek dan mengisi ke-16 kolom di baris kedua
    
    if (i < barLevel) { 
      lcd.print((char)255); 
      // Jika indeks kolom lebih kecil dari barLevel, cetak karakter blok penuh (kode ASCII 255)
    } else {
      lcd.print(" "); 
      // Jika melebihi barLevel, cetak spasi kosong (menghapus blok jika potensiometer diputar turun)
    }
  }

  delay(100); 
  // Memberikan jeda 100 milidetik agar pembacaan tidak terlalu berkedip/cepat
}

## 4. Lengkapi table berikut berdasarkan pengamatan pada Serial Monitor 
### Tabel Hasil Pengamatan Serial Monitor

| ADC | Volt (V) | Persen (%) |
| :---: | :---: | :---: |
| 1 | 0.005 V | 0.10 % |
| 21 | 0.10 V | 2.05 % |
| 49 | 0.24 V | 4.79 % |
| 74 | 0.36 V | 7.23 % |
| 96 | 0.47 V | 9.38 % |



