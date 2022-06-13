#include <gui/mainscreen_screen/MainScreenView.hpp>
#include <gui/mainscreen_screen/MainScreenPresenter.hpp>

MainScreenPresenter::MainScreenPresenter(MainScreenView& v)
    : view(v)
{

}

void MainScreenPresenter::activate()
{

}

void MainScreenPresenter::deactivate()
{

}

void MainScreenPresenter::startConsoleOverlay(){
	view.startConsoleOverlay();
}

void MainScreenPresenter::stopConsoleOverlay(){
	view.stopConsoleOverlay();
}

void MainScreenPresenter::updateTime(uint32_t hour, uint32_t minute, uint32_t second)
{
	view.updateTime(hour, minute, second);
}

void MainScreenPresenter::updatePM25(uint16_t pm25, uint32_t color, uint8_t circle)
{
	view.updatePM25(pm25, color, circle);
}

void MainScreenPresenter::updateCO2TempHum(uint16_t co2, uint32_t color, uint8_t circle, float temperature, float humidity)
{
	view.updateCO2TempHum(co2, color, circle, temperature, humidity);
}

void MainScreenPresenter::updateBattery(float voltagePercent)
{
	view.updateBattery(voltagePercent);
}
