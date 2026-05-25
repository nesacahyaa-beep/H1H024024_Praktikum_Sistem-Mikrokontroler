#include <Arduino.h>

// Variabel volatile agar dapat diubah dalam ISR dengan aman
volatile bool ledState = false;

// ISR: dijalankan saat terjadi perubahan logika pada pin (ditekan atau dilepas)
void tombolInterrupt() {
  ledState = !ledState; // Toggle status LED
}

void setup() {
  // Konfigurasi pin 13 sebagai output (LED)
  pinMode(13, OUTPUT);

  // Konfigurasi pin 2 sebagai input pull-up (kondisi default HIGH)
  pinMode(2, INPUT_PULLUP);

  // Daftarkan interrupt pada pin 2
  // MODIFIKASI: Mengubah mode dari FALLING menjadi CHANGE
  attachInterrupt(
    digitalPinToInterrupt(2),
    tombolInterrupt,
    CHANGE 
  );
}

void loop() {
  // Menulis status LED sesuai variabel ledState ke pin 13
  digitalWrite(13, ledState);
}