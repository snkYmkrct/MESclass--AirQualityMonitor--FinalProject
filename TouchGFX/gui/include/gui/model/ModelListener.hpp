#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include <touchgfx/hal/Types.hpp>
#include <touchgfx/Color.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void updateTime(uint32_t hour, uint32_t minute, uint32_t second) {}

    virtual void updatePM25(uint16_t pm25, uint32_t color, uint8_t circle) {}

    virtual void updateCO2TempHum(uint16_t co2, uint32_t color, uint8_t circle, float temperature, float humidity) {}

    virtual void updateBattery(float voltagePercent) {}

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
