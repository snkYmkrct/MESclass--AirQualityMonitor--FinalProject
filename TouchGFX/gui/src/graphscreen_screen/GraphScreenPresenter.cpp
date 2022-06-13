#include <gui/graphscreen_screen/GraphScreenView.hpp>
#include <gui/graphscreen_screen/GraphScreenPresenter.hpp>

GraphScreenPresenter::GraphScreenPresenter(GraphScreenView& v)
    : view(v)
{

}

void GraphScreenPresenter::activate()
{

}

void GraphScreenPresenter::deactivate()
{

}

void GraphScreenPresenter::startConsoleOverlay(){
	view.startConsoleOverlay();
}

void GraphScreenPresenter::stopConsoleOverlay(){
	view.stopConsoleOverlay();
}

void GraphScreenPresenter::updateTime(uint32_t hour, uint32_t minute, uint32_t second)
{
	view.updateTime(hour, minute, second);
}

void GraphScreenPresenter::updatePM25(uint16_t pm25, uint32_t color, uint8_t circle)
{
	view.updatePM25(pm25, color, circle);
}

void GraphScreenPresenter::updateCO2TempHum(uint16_t co2, uint32_t color, uint8_t circle, float temperature, float humidity)
{
	view.updateCO2TempHum(co2, color, circle, temperature, humidity);
}

void GraphScreenPresenter::updateBattery(float voltagePercent)
{
	view.updateBattery(voltagePercent);
}
