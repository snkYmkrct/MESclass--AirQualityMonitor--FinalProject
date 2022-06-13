#ifndef INTROSCREENVIEW_HPP
#define INTROSCREENVIEW_HPP

#include <gui_generated/introscreen_screen/IntroScreenViewBase.hpp>
#include <gui/introscreen_screen/IntroScreenPresenter.hpp>

class IntroScreenView : public IntroScreenViewBase
{
public:
    IntroScreenView();
    virtual ~IntroScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void updateTime(uint32_t hour, uint32_t minute, uint32_t second);

    void updateBattery(float voltagePercent);

protected:
};

#endif // INTROSCREENVIEW_HPP
