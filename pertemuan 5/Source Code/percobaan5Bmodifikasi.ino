#include <Arduino_FreeRTOS.h>
#include <queue.h>
#include <DHT.h>

#define DHTPIN 2     
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

struct readings {
    float temp; 
    float h;
};

QueueHandle_t my_queue;

void setup() {
    Serial.begin(9600);
    dht.begin(); 

    my_queue = xQueueCreate(1, sizeof(struct readings));

    xTaskCreate(read_data, "read sensors", 128, NULL, 0, NULL);
    xTaskCreate(display, "display", 128, NULL, 0, NULL);
}

void loop() {}

void read_data(void *pvParameters) {
    struct readings x;

    for(;;) {
        x.temp = dht.readTemperature(); 
        x.h = dht.readHumidity();       

        xQueueSend(my_queue, &x, portMAX_DELAY);
        vTaskDelay(2000 / portTICK_PERIOD_MS); 
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
        }
    }
}