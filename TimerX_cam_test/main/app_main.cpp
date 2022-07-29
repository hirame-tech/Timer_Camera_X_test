#include <stdio.h>
#include <iostream>
#include "esp_camera.h"
#include "camera_func.cpp"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

using namespace std;

extern "C" void app_main(void){
    printf("Program start\n");//check
    if(ESP_OK != init_camera()) {
        return;
    }
    while (1)
    {
        ESP_LOGI(TAG, "Taking picture...");
        camera_fb_t *pic = esp_camera_fb_get();

        // use pic->buf to access the image
        ESP_LOGI(TAG, "Picture taken! Its size was: %zu bytes", pic->len);
        esp_camera_fb_return(pic);

        vTaskDelay(5000 / portTICK_RATE_MS);
    }
}