#ifndef SCREEN3VIEW_HPP
#define SCREEN3VIEW_HPP

#include <gui_generated/screen3_screen/Screen3ViewBase.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>
#include <touchgfx/hal/Types.hpp>

class Screen3View : public Screen3ViewBase
{
public:
    Screen3View();
    virtual ~Screen3View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();

    void updateTime(uint32_t hour, uint32_t minute, uint32_t second);

    void updatePM25(uint16_t pm25, uint32_t color, uint8_t circle);

    void updateCO2TempHum(uint16_t co2, uint32_t color, uint8_t circle, float temperature, float humidity);

    void updateBattery(float voltagePercent);

protected:
    Unicode::UnicodeChar txtBufferPM25[5];
    Unicode::UnicodeChar txtBufferCO2[5];
    Unicode::UnicodeChar txtBufferTemp[6];
    Unicode::UnicodeChar txtBufferHum[6];
    uint8_t img;
    uint16_t counter;
};

#endif // SCREEN3VIEW_HPP
