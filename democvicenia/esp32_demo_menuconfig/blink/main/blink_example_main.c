#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"

#define LED_GPIO CONFIG_BLINK_GPIO
#define LED_PERIOD CONFIG_BLINK_PERIOD

void app_main() {
    gpio_pad_select_gpio(LED_GPIO);

    /* Set the LED_GPIO port as output */
    ESP_ERROR_CHECK(gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT));

    int value = 0;
    while(1) {
        /* Blink switch */
        ESP_ERROR_CHECK(gpio_set_level(LED_GPIO, value));
        vTaskDelay(LED_PERIOD / portTICK_RATE_MS); // wait for LED_PERIOD ms
        value = 1 - value;
    }
}
