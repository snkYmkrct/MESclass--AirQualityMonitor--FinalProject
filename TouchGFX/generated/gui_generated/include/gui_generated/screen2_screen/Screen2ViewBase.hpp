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
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/containers/clock/DigitalClock.hpp>
#include <touchgfx/containers/ScrollableContainer.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/containers/scrollers/ScrollWheelWithSelectionStyle.hpp>
#include <gui/containers/MenuElement.hpp>
#include <touchgfx/containers/scrollers/ScrollList.hpp>
#include <touchgfx/mixins/ClickListener.hpp>

class Screen2ViewBase : public touchgfx::View<Screen2Presenter>
{
public:
    Screen2ViewBase();
    virtual ~Screen2ViewBase() {}
    virtual void setupScreen();

    virtual void scrollList1UpdateItem(MenuElement& item, int16_t itemIndex)
    {
        // Override and implement this function in Screen2
    }

    virtual void scrollWheel1UpdateItem(MenuElement& item, int16_t itemIndex)
    {
        // Override and implement this function in Screen2
    }

    virtual void scrollWheel1UpdateCenterItem(MenuElement& item, int16_t itemIndex)
    {
        // Override and implement this function in Screen2
    }

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
    touchgfx::Button button1;
    touchgfx::DigitalClock digitalClock1;
    touchgfx::Image image2;
    touchgfx::ScrollableContainer scrollableContainer1;
    touchgfx::TextAreaWithOneWildcard textArea1;
    touchgfx::TextAreaWithOneWildcard textArea2;
    touchgfx::TextAreaWithOneWildcard textArea3;
    touchgfx::TextAreaWithOneWildcard textArea4;
    touchgfx::TextAreaWithOneWildcard textArea5;
    touchgfx::TextAreaWithOneWildcard textArea6;
    touchgfx::ScrollWheelWithSelectionStyle scrollWheel1;
    touchgfx::DrawableListItems<MenuElement, 3> scrollWheel1ListItems;
    touchgfx::DrawableListItems<MenuElement, 3> scrollWheel1SelectedListItems;
    touchgfx::ClickListener< touchgfx::ScrollList > scrollList1;
    touchgfx::DrawableListItems<MenuElement, 4> scrollList1ListItems;

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

private:
    touchgfx::Callback<Screen2ViewBase, touchgfx::DrawableListItemsInterface*, int16_t, int16_t> updateItemCallback;
    void updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex);

};

#endif // SCREEN2VIEWBASE_HPP
