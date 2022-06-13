#ifndef MAINSCREENPRESENTER_HPP
#define MAINSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>
#include <touchgfx/hal/Types.hpp>

using namespace touchgfx;

class MainScreenView;

class MainScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MainScreenPresenter(MainScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~MainScreenPresenter() {};

    void startConsoleOverlay();

    void stopConsoleOverlay();

    void updateTime(uint32_t hour, uint32_t minute, uint32_t second);

    void updatePM25(uint16_t pm25, uint32_t color, uint8_t circle);

    void updateCO2TempHum(uint16_t co2, uint32_t color, uint8_t circle, float temperature, float humidity);

    void updateBattery(float voltagePercent);

private:
    MainScreenPresenter();

    MainScreenView& view;
};

#endif // MAINSCREENPRESENTER_HPP
