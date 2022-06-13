#ifndef MODEL_HPP
#define MODEL_HPP

#include <touchgfx/hal/Types.hpp>
#include <touchgfx/Color.hpp>

#ifdef USE_HAL_DRIVER
extern "C" {
#include "peripheral_data.h"
}
extern uint8_t isConsoleStarted;
#endif

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
protected:
    ModelListener* modelListener;

private:

    uint16_t cntTim, cntAQI, cntCO2, cntBat;
    uint32_t hour, minute, second;
    uint16_t pm25;
    uint16_t co2;
    float temperature, humidity;
    uint32_t colorPM25, colorCO2;
    float voltageValue, voltagePercent;
    uint8_t circleCo2, circlePM25;
};

#endif // MODEL_HPP
