```cpp
// Mendefinisikan pin Arduino (2 sampai 8) untuk mengontrol segmen A sampai G
int segmenPin[] = {2, 3, 4, 5, 6, 7, 8};
// Mendefinisikan pin 10 sebagai jalur input untuk tombol tambah (Increment)
int pinTombolNaik = 10;
// Mendefinisikan pin 11 sebagai jalur input untuk tombol kurang (Decrement)
int pinTombolTurun = 11;
// Membuat variabel penampung nilai hitungan angka yang dimulai dari 0
int hitungan = 0;

// Membuat susunan data biner (array) untuk menampilkan karakter angka 0-9 (Common Cathode)
byte polaAngka[] = {
  0b00111111, // Pola biner untuk menampilkan angka 0
  0b00000110, // Pola biner untuk menampilkan angka 1
  0b01011011, // Pola biner untuk menampilkan angka 2
  0b01001111, // Pola biner untuk menampilkan angka 3
  0b01100110, // Pola biner untuk menampilkan angka 4
  0b01101101, // Pola biner untuk menampilkan angka 5
  0b01111101, // Pola biner untuk menampilkan angka 6
  0b00000111, // Pola biner untuk menampilkan angka 7
  0b01111111, // Pola biner untuk menampilkan angka 8
  0b01101111  // Pola biner untuk menampilkan angka 9
};

void setup() {
  // Melakukan perulangan sebanyak 7 kali untuk mengatur status seluruh pin segmen
  for (int i = 0; i < 7; i++) {
    // Mengonfigurasi setiap pin segmen pada indeks ke-i menjadi mode OUTPUT
    pinMode(segmenPin[i], OUTPUT);
  }
  // Mengonfigurasi pin tombol tambah sebagai input dengan resistor pull-up internal aktif
  pinMode(pinTombolNaik, INPUT_PULLUP);
  // Mengonfigurasi pin tombol kurang sebagai input dengan resistor pull-up internal aktif
  pinMode(pinTombolTurun, INPUT_PULLUP);
  // Memanggil fungsi tampilAngka untuk memunculkan nilai awal (0) pada 7-segment
  tampilAngka(hitungan);
}

void loop() {
  // Memeriksa apakah tombol tambah sedang ditekan (menghasilkan logika LOW)
  if (digitalRead(pinTombolNaik) == LOW) {
    // Menambahkan nilai pada variabel hitungan sebesar 1 angka
    hitungan++;
    // Membatasi hitungan; jika angka melewati 9, maka nilai akan dikembalikan ke 0
    if (hitungan > 9) hitungan = 0;
    // Memperbarui visualisasi pada layar 7-segment sesuai dengan nilai hitungan terbaru
    tampilAngka(hitungan);
    // Memberikan jeda 250ms agar tombol tidak terbaca ganda akibat efek getaran mekanis (debouncing)
    delay(250);
  }
  
  // Memeriksa apakah tombol kurang sedang ditekan (menghasilkan logika LOW)
  if (digitalRead(pinTombolTurun) == LOW) {
    // Mengurangi nilai pada variabel hitungan sebesar 1 angka
    hitungan--;
    // Membatasi hitungan; jika angka turun di bawah 0, maka nilai akan diputar ke angka 9
    if (hitungan < 0) hitungan = 9;
    // Memperbarui visualisasi pada layar 7-segment sesuai dengan nilai hitungan terbaru
    tampilAngka(hitungan);
    // Memberikan jeda 250ms agar tombol tidak terbaca ganda akibat efek getaran mekanis (debouncing)
    delay(250);
  }
}

// Membuat fungsi khusus untuk menerjemahkan data biner array menjadi nyala LED segmen
void tampilAngka(int nilai) {
  // Melakukan perulangan sebanyak 7 kali untuk mengirim sinyal ke masing-masing pin segmen
  for (int i = 0; i < 7; i++) {
    // Membaca bit data dari array polaAngka dan mengirim logika HIGH/LOW ke pin segmen terkait
    digitalWrite(segmenPin[i], bitRead(polaAngka[nilai], i));
  }
}

```