#ifndef GRAPHSCREENPRESENTER_HPP
#define GRAPHSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class GraphScreenView;

class GraphScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    GraphScreenPresenter(GraphScreenView& v);

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

    virtual ~GraphScreenPresenter() {};

    void startConsoleOverlay();

    void stopConsoleOverlay();

    void updateTime(uint32_t hour, uint32_t minute, uint32_t second);

    void updatePM25(uint16_t pm25, uint32_t color, uint8_t circle);

    void updateCO2TempHum(uint16_t co2, uint32_t color, uint8_t circle, float temperature, float humidity);

    void updateBattery(float voltagePercent);

private:
    GraphScreenPresenter();

    GraphScreenView& view;
};

#endif // GRAPHSCREENPRESENTER_HPP
