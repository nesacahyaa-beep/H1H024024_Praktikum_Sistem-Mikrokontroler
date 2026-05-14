# Laporan Praktikum Sistem Mikrokontroler - Percobaan 5B

## Alat dan Bahan
- Arduino Uno
- LED
- Potensiometer
- Resistor 220ohm
- Sensor DHT
- Kabel Jumper & Breadboard

## Kode Program (modul5_percobaan2.ino)
```cpp
#include <Arduino_FreeRTOS.h> 
#include <queue.h>           

struct readings { 
  int temp; 
  int h; 
}; 

QueueHandle_t my_queue; 
 
void setup() { 
  Serial.begin(9600); 
  
  my_queue = xQueueCreate(1, sizeof(struct readings)); 
  
  xTaskCreate(read_data, "read sensors", 128, NULL, 1, NULL); 
  xTaskCreate(display, "display", 128, NULL, 1, NULL);      
} 
 
void loop() {
} 
 
void read_data(void *pvParameters) { 
  struct readings x; 
  for(;;) { 
    x.temp = 54; // Data simulasi suhu
    x.h = 30;    // Data simulasi kelembapan
    
    // Mengirim data struktur ke dalam queue
    xQueueSend(my_queue, &x, portMAX_DELAY); 
    
    // Delay task selama 100 ticks (memberikan waktu task lain berjalan)
    vTaskDelay(100 / portTICK_PERIOD_MS); 
  } 
} 
 
void display(void *pvParameters) { 
  struct readings x; 
  for(;;) { 
    if(xQueueReceive(my_queue, &x, portMAX_DELAY) == pdPASS) { 
      Serial.print("temp = "); 
      Serial.println(x.temp); 
      Serial.print("humidity = "); 
      Serial.println(x.h); 
      Serial.println("-------------------");
    } 
  } 
}
```

## Pertanyaan Percobaan 5B
1. Apakah kedua task berjalan secara bersamaan atau bergantian? Jelaskan mekanismenya! \
Jawab: Secara teknis, pada Arduino Uno kedua task tersebut berjalan secara bergantian (sequential), tetapi karena prosesnya sangat cepat, keduanya terlihat berjalan bersamaan (concurrent). Arduino Uno menggunakan prosesor single-core, sehingga hanya mampu mengeksekusi satu instruksi dalam satu waktu. Program akan menjalankan perintah untuk LED 1 terlebih dahulu, kemudian lanjut ke LED 2 secara berurutan. Karena kecepatan clock mencapai 16 MHz maka, perpindahan antar instruksi terjadi sangat cepat dalam hitungan nanodetik. Akibatnya, mata manusia melihat kedua LED seolah menyala secara bersamaan.
2. Apakah program ini berpotensi mengalami race condition? Jelaskan! \
Jawab: Pada rangkaian tersebut kemungkinan terjadinya race condition sangat kecil karena mikrokontroler bekerja secara sekuensial. Semua instruksi dijalankan satu per satu dalam sistem single-thread, sehingga tidak ada dua proses yang benar-benar saling berebut mengakses Pin 12 atau Pin 13 secara bersamaan. Race condition biasanya muncul pada sistem yang lebih kompleks, misalnya saat menggunakan interrupt (ISR) atau RTOS. Contohnya, jika sebuah variabel global untuk mengatur delay LED diubah oleh interrupt ketika program utama sedang membacanya, maka data bisa menjadi tidak konsisten. Jika program hanya berjalan di dalam fungsi `loop()` tanpa interrupt atau multitasking khusus, urutan eksekusi akan tetap aman dan konflik data umumnya tidak terjadi.
3. Modifikasilah program dengan menggunakan sensor DHT sesungguhnya sehingga 
informasi yang ditampilkan dinamis. Bagaimana hasilnya? \
Jawab: Diubah pada bagian:
- Tipe data struct: 
struct readings {
    float temp; // Diubah dari int ke float
    float h;    // Diubah dari int ke float
};
- Pembacaan sensor pada taks:
x.temp = dht.readTemperature(); // Mengganti nilai statis 54
x.h = dht.readHumidity();       // Mengganti nilai statis 30
- Delay taks:
vTaskDelay(2000 / portTICK_PERIOD_MS); // Diubah dari 100ms menjadi 2000ms
Nilai tetap diganti dengan pembacaan sensor DHT secara langsung, tipe data diubah menjadi `float` agar dapat menyimpan nilai desimal, dan delay diperpanjang menjadi 2000 ms supaya proses pembacaan sensor lebih stabil serta sesuai dengan waktu respon sensor DHT.
