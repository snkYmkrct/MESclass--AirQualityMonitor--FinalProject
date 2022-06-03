/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN3VIEWBASE_HPP
#define SCREEN3VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/canvas/Circle.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/containers/clock/DigitalClock.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Button.hpp>

class Screen3ViewBase : public touchgfx::View<Screen3Presenter>
{
public:
    Screen3ViewBase();
    virtual ~Screen3ViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box box3;
    touchgfx::Image image1;
    touchgfx::Box box1;
    touchgfx::Box box1_1;
    touchgfx::Image image2;
    touchgfx::TextArea textArea1;
    touchgfx::TextArea textArea2;
    touchgfx::Circle circle2;
    touchgfx::PainterRGB565 circle2Painter;
    touchgfx::Box box7;
    touchgfx::DigitalClock digitalClock1;
    touchgfx::Image image3;
    touchgfx::Image image5;
    touchgfx::Image image6;
    touchgfx::Box box4;
    touchgfx::TextAreaWithOneWildcard textArea3;
    touchgfx::Box box5;
    touchgfx::Image image7;
    touchgfx::TextArea textArea4;
    touchgfx::Container container1;
    touchgfx::Box box6;
    touchgfx::Box box6_1;
    touchgfx::Box box6_2;
    touchgfx::Box box6_3;
    touchgfx::Container container1_1;
    touchgfx::Box box6_4;
    touchgfx::Box box6_1_1;
    touchgfx::Box box6_2_1;
    touchgfx::Box box6_3_1;
    touchgfx::Circle circle1;
    touchgfx::PainterRGB565 circle1Painter;
    touchgfx::Button button1;
    touchgfx::Button button2;
    touchgfx::Image image2_1;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Screen3ViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 3600;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // SCREEN3VIEWBASE_HPP