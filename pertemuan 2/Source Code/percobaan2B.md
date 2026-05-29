 Laporan Praktikum Sistem Mikrokontroler - Percobaan 2B

## Alat dan Bahan
- Arduino Uno
- Push Button
- Seven Segment
- Resistor 220ohm
- Kabel Jumper & Breadboard

## Kode Program (modul4_percobaan1.ino)
```cpp
#include <Arduino.h>

// Pin 7-Segment (a b c d e f g dp)
const int segmentPins[8] = {7, 6, 5, 11, 10, 8, 9, 4};

// Push button
const int buttonPin = 2;

// Counter
int counter = 0;

// State button
bool lastButtonState = HIGH;

// Pola digit 0-F
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

// Tampilkan digit
void displayDigit(int num)
{
  for(int i=0; i<8; i++)
  {
    digitalWrite(segmentPins[i], !digitPattern[num][i]);
  }
}

void setup()
{
  for(int i=0; i<8; i++)
  {
    pinMode(segmentPins[i], OUTPUT);
  }

  pinMode(buttonPin, INPUT_PULLUP);

  displayDigit(counter); // tampilkan awal
}

void loop()
{
  bool currentButtonState = digitalRead(buttonPin);

  // deteksi tekan (HIGH -> LOW)
  if (lastButtonState == HIGH && currentButtonState == LOW)
  {
    counter++;
    if(counter > 15) counter = 0;

    displayDigit(counter); // update hanya saat ditekan

    delay(200); // debounce sederhana
  }

  lastButtonState = currentButtonState;
}
```

## Pertanyaan Percobaan 2B
1. Mengapa pada push button digunakan mode INPUT_PULLUP pada Arduino Uno? Apa keuntungannya dibandingkan rangkaian biasa? \
Jawab: Mode `INPUT_PULLUP` digunakan untuk mengaktifkan resistor pull-up internal pada Arduino Uno sehingga tidak memerlukan resistor eksternal tambahan. Penggunaan mode ini membuat rangkaian lebih sederhana, mengurangi penggunaan kabel, serta mencegah kondisi floating akibat gangguan noise. Dengan demikian, pin digital dapat membaca logika secara stabil, yaitu HIGH saat tombol tidak ditekan dan LOW saat tombol ditekan.
2. Jika salah satu LED segmen tidak menyala, apa saja kemungkinan penyebabnya dari sisi hardware maupun software? \
Jawab: Dari sisi hardware, masalah dapat disebabkan oleh kabel jumper yang longgar atau salah pemasangan, kontak breadboard yang kurang baik, pin Arduino yang rusak, atau LED segmen yang terbakar akibat arus berlebih tanpa resistor pembatas. Dari sisi software, penyebabnya bisa berupa pin yang belum diatur sebagai `OUTPUT`, kesalahan pemetaan pin, atau data pada array pola angka yang tidak sesuai.
3. Modifikasi rangkaian dan program dengan dua push button yang berfungsi sebagai penambahan (increment) dan pengurangan (decrement) pada sistem counter dan berikan penjelasan disetiap baris kode nya. \
Jawab: Modifikasi program menambahkan tombol kedua untuk fungsi hitung mundur (decrement) selain tombol pertama sebagai hitung maju (increment), di mana Arduino membaca kedua tombol pada `loop`, memperbarui nilai `hitungan` dengan batas 0–9, menampilkan perubahan pada 7-segment, serta menggunakan delay singkat untuk mengurangi efek debouncing.