#ifndef MAINSCREENVIEW_HPP
#define MAINSCREENVIEW_HPP

#include <gui_generated/mainscreen_screen/MainScreenViewBase.hpp>
#include <gui/mainscreen_screen/MainScreenPresenter.hpp>
#include <touchgfx/hal/Types.hpp>

class MainScreenView : public MainScreenViewBase
{
public:
    MainScreenView();
    virtual ~MainScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void startConsoleOverlay();

    void stopConsoleOverlay();

    void updateTime(uint32_t hour, uint32_t minute, uint32_t second);

    void updatePM25(uint16_t pm25, uint32_t color, uint8_t circle);

    void updateCO2TempHum(uint16_t co2, uint32_t color, uint8_t circle, float temperature, float humidity);

    void updateBattery(float voltagePercent);

protected:
    Unicode::UnicodeChar txtBufferPM25[5];
    Unicode::UnicodeChar txtBufferCO2[5];
    Unicode::UnicodeChar txtBufferTemp[6];
    Unicode::UnicodeChar txtBufferHum[6];
};

#endif // MAINSCREENVIEW_HPP
