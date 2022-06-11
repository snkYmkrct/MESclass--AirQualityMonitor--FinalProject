#include <gui/screen3_screen/Screen3View.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>

Screen3Presenter::Screen3Presenter(Screen3View& v)
    : view(v)
{

}

void Screen3Presenter::activate()
{

}

void Screen3Presenter::deactivate()
{

}

void Screen3Presenter::updateTime(uint32_t hour, uint32_t minute, uint32_t second)
{
	view.updateTime(hour, minute, second);
}

void Screen3Presenter::updatePM25(uint16_t pm25, uint32_t color, uint8_t circle)
{
	view.updatePM25(pm25, color, circle);
}

void Screen3Presenter::updateCO2TempHum(uint16_t co2, uint32_t color, uint8_t circle, float temperature, float humidity)
{
	view.updateCO2TempHum(co2, color, circle, temperature, humidity);
}

void Screen3Presenter::updateBattery(float voltagePercent)
{
	view.updateBattery(voltagePercent);
}
