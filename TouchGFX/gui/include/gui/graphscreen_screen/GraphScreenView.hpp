#ifndef GRAPHSCREENVIEW_HPP
#define GRAPHSCREENVIEW_HPP

#include <gui_generated/graphscreen_screen/GraphScreenViewBase.hpp>
#include <gui/graphscreen_screen/GraphScreenPresenter.hpp>

class GraphScreenView : public GraphScreenViewBase
{
public:
    GraphScreenView();
    virtual ~GraphScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void startConsoleOverlay();

    void stopConsoleOverlay();

    void updateTime(uint32_t hour, uint32_t minute, uint32_t second);

    void updatePM25(uint16_t pm25, uint32_t color, uint8_t circle);

    void updateCO2TempHum(uint16_t co2, uint32_t color, uint8_t circle, float temperature, float humidity);

    void updateBattery(float voltagePercent);

protected:

};

#endif // GRAPHSCREENVIEW_HPP
