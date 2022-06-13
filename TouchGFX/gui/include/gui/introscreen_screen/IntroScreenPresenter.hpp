#ifndef INTROSCREENPRESENTER_HPP
#define INTROSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class IntroScreenView;

class IntroScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    IntroScreenPresenter(IntroScreenView& v);

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

    virtual ~IntroScreenPresenter() {};

    void updateTime(uint32_t hour, uint32_t minute, uint32_t second);

    void updateBattery(float voltagePercent);

private:
    IntroScreenPresenter();

    IntroScreenView& view;
};

#endif // INTROSCREENPRESENTER_HPP
