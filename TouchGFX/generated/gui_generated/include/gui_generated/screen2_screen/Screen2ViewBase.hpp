/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN2VIEWBASE_HPP
#define SCREEN2VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/containers/clock/DigitalClock.hpp>

class Screen2ViewBase : public touchgfx::View<Screen2Presenter>
{
public:
    Screen2ViewBase();
    virtual ~Screen2ViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box box1;
    touchgfx::Image image1;
    touchgfx::TextAreaWithOneWildcard textArea1;
    touchgfx::TextAreaWithOneWildcard textArea2;
    touchgfx::TextAreaWithOneWildcard textArea3;
    touchgfx::TextAreaWithOneWildcard textArea4;
    touchgfx::TextAreaWithOneWildcard textArea5;
    touchgfx::TextAreaWithOneWildcard textArea6;
    touchgfx::TextAreaWithOneWildcard textArea1_1;
    touchgfx::TextAreaWithOneWildcard textArea2_1;
    touchgfx::TextAreaWithOneWildcard textArea3_1;
    touchgfx::TextAreaWithOneWildcard textArea4_1;
    touchgfx::TextAreaWithOneWildcard textArea5_1;
    touchgfx::TextAreaWithOneWildcard textArea6_1;
    touchgfx::Button button1;
    touchgfx::DigitalClock digitalClock1;
    touchgfx::Image image2;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREA1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea1Buffer[TEXTAREA1_SIZE];
    static const uint16_t TEXTAREA2_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea2Buffer[TEXTAREA2_SIZE];
    static const uint16_t TEXTAREA3_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea3Buffer[TEXTAREA3_SIZE];
    static const uint16_t TEXTAREA4_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea4Buffer[TEXTAREA4_SIZE];
    static const uint16_t TEXTAREA5_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea5Buffer[TEXTAREA5_SIZE];
    static const uint16_t TEXTAREA6_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea6Buffer[TEXTAREA6_SIZE];
    static const uint16_t TEXTAREA1_1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea1_1Buffer[TEXTAREA1_1_SIZE];
    static const uint16_t TEXTAREA2_1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea2_1Buffer[TEXTAREA2_1_SIZE];
    static const uint16_t TEXTAREA3_1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea3_1Buffer[TEXTAREA3_1_SIZE];
    static const uint16_t TEXTAREA4_1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea4_1Buffer[TEXTAREA4_1_SIZE];
    static const uint16_t TEXTAREA5_1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea5_1Buffer[TEXTAREA5_1_SIZE];
    static const uint16_t TEXTAREA6_1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea6_1Buffer[TEXTAREA6_1_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Screen2ViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // SCREEN2VIEWBASE_HPP
