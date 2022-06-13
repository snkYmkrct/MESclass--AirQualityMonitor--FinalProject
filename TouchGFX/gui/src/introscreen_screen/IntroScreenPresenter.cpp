#include <gui/introscreen_screen/IntroScreenView.hpp>
#include <gui/introscreen_screen/IntroScreenPresenter.hpp>

IntroScreenPresenter::IntroScreenPresenter(IntroScreenView& v)
    : view(v)
{

}

void IntroScreenPresenter::activate()
{

}

void IntroScreenPresenter::deactivate()
{

}

void IntroScreenPresenter::updateTime(uint32_t hour, uint32_t minute, uint32_t second)
{
	view.updateTime(hour, minute, second);
}

void IntroScreenPresenter::updateBattery(float voltagePercent)
{
	view.updateBattery(voltagePercent);
}
