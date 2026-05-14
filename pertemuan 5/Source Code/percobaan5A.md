# Laporan Praktikum Sistem Mikrokontroler - Percobaan 5A

## Alat dan Bahan
- Arduino Uno
- LED
- Potensiometer
- Resistor 220ohm
- Sensor DHT
- Kabel Jumper & Breadboard

## Kode Program (modul5_percobaan1.ino)
```cpp
#include <Arduino_FreeRTOS.h>

void TaskBlink1( void *pvParameters );
void TaskBlink2( void *pvParameters );
void Taskprint( void *pvParameters );

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  xTaskCreate(
    TaskBlink1
    , "task1"
    , 128
    , NULL
    , 1
    , NULL );

  xTaskCreate(
    TaskBlink2
    , "task2"
    , 128
    , NULL
    , 1
    , NULL );

  xTaskCreate(
    Taskprint
    , "task3"
    , 128
    , NULL
    , 1
    , NULL );

  vTaskStartScheduler();
}

void loop()
{
}

void TaskBlink1(void *pvParameters) {
  pinMode(8, OUTPUT);

  while(1)
  {
    Serial.println("Task1");
    digitalWrite(8, HIGH);
    vTaskDelay( 200 / portTICK_PERIOD_MS );
    digitalWrite(8, LOW);
    vTaskDelay( 200 / portTICK_PERIOD_MS );
  }
}

void TaskBlink2(void *pvParameters)
{
  pinMode(7, OUTPUT);

  while(1)
  {
    Serial.println("Task2");
    digitalWrite(7, HIGH);
    vTaskDelay( 300 / portTICK_PERIOD_MS );
    digitalWrite(7, LOW);
    vTaskDelay( 300 / portTICK_PERIOD_MS );
  }
}

void Taskprint(void *pvParameters) {
  int counter = 0;

  while(1)
  {
    counter++;
    Serial.println(counter);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}
```

## Pertanyaan Percobaan 5A
1. Apakah ketiga task berjalan secara bersamaan atau bergantian? Jelaskan mekanismenya! \
Jawab: Secara teknis, ketiga task tersebut berjalan secara bergantian.
Mekanismenya:
Arduino Uno menggunakan arsitektur single-core, sehingga hanya dapat menjalankan satu instruksi dalam satu waktu. Semua proses dalam program dikerjakan berurutan di dalam fungsi `void loop()`, misalnya membaca potensiometer, mengatur LED, lalu membaca LDR secara bergantian. Dengan clock speed 16 MHz, perpindahan antar proses berlangsung sangat cepat (mikrodetik), sehingga respons sistem tampak real-time bagi pengamatan manusia.
2. Bagaimana cara menambahkan task keempat? Jelaskan langkahnya! \
Jawab: Untuk menambahkan task keempat diperlukan perubahan pada hardware dan software.
Pada bagian hardware, yaitu memilih komponen baru, dan pasang di breadboard, lalu hubungkan pin VCC ke 5V, GND ke ground Arduino, dan pin sinyal ke pin digital/analog yang masih tersedia (misalnya pin 4 atau A2).
Pada bagian software, tambahkan deklarasi pin di awal program, kemudian set sebagai OUTPUT atau INPUT pada `void setup()`. Setelah itu, masukkan logika task keempat di dalam `void loop()` bersama task lainnya.
Dengan penambahan ini, Arduino tetap menjalankan semua task secara berurutan (sekuensial), tetapi akan terlihat seperti berjalan bersamaan karena eksekusinya sangat cepat.
3. Modifikasilah program dengan menambah sensor (misalnya potensiometer), lalu 
gunakan nilainya untuk mengontrol kecepatan LED! Bagaimana hasilnya? \
Jawab: Diubah pada bagian:
delayLed = map(potValue, 0, 1023, 100, 1000);
Karena fungsi map() digunakan untuk mengubah nilai analog potensiometer dari rentang 0–1023 menjadi nilai delay baru antara 100 ms hingga 1000 ms. Nilai hasil konversi tersebut disimpan pada variabel delayLed dan dipakai oleh TaskLED untuk mengatur kecepatan kedipan LED secara otomatis. Semakin besar nilai potensiometer, maka kecepatan kedipan LED dapat menjadi lebih cepat atau lebih lambat sesuai pengaturan program.

