/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen3_screen/Screen3ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>


Screen3ViewBase::Screen3ViewBase() :
    buttonCallback(this, &Screen3ViewBase::buttonCallbackHandler)
{

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    __background.setPosition(0, 0, 240, 320);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    box3.setPosition(0, 0, 240, 320);
    box3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    image1.setXY(0, 33);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_BACKGROUND_GRAY_VERTICAL_ID));

    image2.setXY(195, -2);
    image2.setBitmap(touchgfx::Bitmap(BITMAP_BATTERY_3Q_MIC_ID));

    circle2.setPosition(-14, 253, 80, 80);
    circle2.setCenter(40, 40);
    circle2.setRadius(19);
    circle2.setLineWidth(0);
    circle2.setArc(0, 360);
    circle2Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    circle2.setPainter(circle2Painter);

    digitalClock1.setPosition(3, 5, 101, 26);
    digitalClock1.setColor(touchgfx::Color::getColorFromRGB(255, 67, 151));
    digitalClock1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_8SEC));
    digitalClock1.displayLeadingZeroForHourIndicator(true);
    digitalClock1.setDisplayMode(touchgfx::DigitalClock::DISPLAY_24_HOUR);
    digitalClock1.setTime24Hour(10, 10, 0);

    container1.setPosition(7, 50, 125, 126);

    box6.setPosition(0, 0, 37, 20);
    box6.setColor(touchgfx::Color::getColorFromRGB(0, 228, 0));
    container1.add(box6);

    box6_1.setPosition(0, 20, 37, 20);
    box6_1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 0));
    container1.add(box6_1);

    box6_2.setPosition(0, 40, 37, 20);
    box6_2.setColor(touchgfx::Color::getColorFromRGB(255, 126, 0));
    container1.add(box6_2);

    box6_3.setPosition(0, 60, 37, 20);
    box6_3.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    container1.add(box6_3);

    box6_4.setPosition(0, 80, 37, 20);
    box6_4.setColor(touchgfx::Color::getColorFromRGB(143, 63, 151));
    container1.add(box6_4);

    box6_5.setPosition(0, 100, 37, 20);
    box6_5.setColor(touchgfx::Color::getColorFromRGB(126, 0, 35));
    container1.add(box6_5);

    image6.setXY(70, -6);
    image6.setBitmap(touchgfx::Bitmap(BITMAP_AIR_POLLUTION_1_MIC_ID));
    container1.add(image6);

    textArea1.setXY(41, 16);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(35, 242, 24));
    textArea1.setLinespacing(0);
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_7Z87).getText());
    textArea1.setWildcard(textArea1Buffer);
    textArea1.resizeToCurrentText();
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_BVBX));
    container1.add(textArea1);

    circle1.setPosition(-2, -10, 39, 31);
    circle1.setCenter(20, 20);
    circle1.setRadius(6);
    circle1.setLineWidth(0);
    circle1.setArc(0, 360);
    circle1Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    circle1.setPainter(circle1Painter);
    circle1.setVisible(false);
    container1.add(circle1);

    circle1_1.setPosition(-2, 10, 39, 31);
    circle1_1.setCenter(20, 20);
    circle1_1.setRadius(6);
    circle1_1.setLineWidth(0);
    circle1_1.setArc(0, 360);
    circle1_1Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    circle1_1.setPainter(circle1_1Painter);
    circle1_1.setVisible(false);
    container1.add(circle1_1);

    circle1_2.setPosition(-2, 31, 39, 31);
    circle1_2.setCenter(20, 20);
    circle1_2.setRadius(6);
    circle1_2.setLineWidth(0);
    circle1_2.setArc(0, 360);
    circle1_2Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    circle1_2.setPainter(circle1_2Painter);
    circle1_2.setVisible(false);
    container1.add(circle1_2);

    circle1_3.setPosition(-2, 50, 39, 31);
    circle1_3.setCenter(20, 20);
    circle1_3.setRadius(6);
    circle1_3.setLineWidth(0);
    circle1_3.setArc(0, 360);
    circle1_3Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    circle1_3.setPainter(circle1_3Painter);
    circle1_3.setVisible(false);
    container1.add(circle1_3);

    circle1_4.setPosition(-2, 71, 39, 31);
    circle1_4.setCenter(20, 20);
    circle1_4.setRadius(6);
    circle1_4.setLineWidth(0);
    circle1_4.setArc(0, 360);
    circle1_4Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    circle1_4.setPainter(circle1_4Painter);
    circle1_4.setVisible(false);
    container1.add(circle1_4);

    circle1_5.setPosition(-2, 92, 39, 31);
    circle1_5.setCenter(20, 20);
    circle1_5.setRadius(6);
    circle1_5.setLineWidth(0);
    circle1_5.setArc(0, 360);
    circle1_5Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    circle1_5.setPainter(circle1_5Painter);
    circle1_5.setVisible(false);
    container1.add(circle1_5);

    container1_1.setPosition(86, 94, 149, 97);

    box1_1.setPosition(14, 38, 96, 25);
    box1_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    container1_1.add(box1_1);

    box6_1_1.setPosition(111, 0, 37, 20);
    box6_1_1.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    container1_1.add(box6_1_1);

    box6_2_1.setPosition(111, 20, 37, 20);
    box6_2_1.setColor(touchgfx::Color::getColorFromRGB(255, 126, 0));
    container1_1.add(box6_2_1);

    box6_3_1.setPosition(111, 40, 37, 20);
    box6_3_1.setColor(touchgfx::Color::getColorFromRGB(0, 228, 0));
    container1_1.add(box6_3_1);

    image5.setXY(13, 31);
    image5.setBitmap(touchgfx::Bitmap(BITMAP_CO2_MIC_ID));
    container1_1.add(image5);

    textArea2.setXY(69, 41);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(217, 4, 4));
    textArea2.setLinespacing(0);
    Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_5GAY).getText());
    textArea2.setWildcard(textArea2Buffer);
    textArea2.resizeToCurrentText();
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_UZVW));
    container1_1.add(textArea2);

    circle3.setPosition(109, -10, 39, 31);
    circle3.setCenter(20, 20);
    circle3.setRadius(6);
    circle3.setLineWidth(0);
    circle3.setArc(0, 360);
    circle3Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    circle3.setPainter(circle3Painter);
    circle3.setVisible(false);
    container1_1.add(circle3);

    circle3_1.setPosition(109, 10, 39, 31);
    circle3_1.setCenter(20, 20);
    circle3_1.setRadius(6);
    circle3_1.setLineWidth(0);
    circle3_1.setArc(0, 360);
    circle3_1Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    circle3_1.setPainter(circle3_1Painter);
    circle3_1.setVisible(false);
    container1_1.add(circle3_1);

    circle3_2.setPosition(109, 30, 39, 31);
    circle3_2.setCenter(20, 20);
    circle3_2.setRadius(6);
    circle3_2.setLineWidth(0);
    circle3_2.setArc(0, 360);
    circle3_2Painter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    circle3_2.setPainter(circle3_2Painter);
    circle3_2.setVisible(false);
    container1_1.add(circle3_2);

    button1.setXY(6, 273);
    button1.setBitmaps(touchgfx::Bitmap(BITMAP_ARROW_LEFT_MIC_ID), touchgfx::Bitmap(BITMAP_ARROW_LEFT_MIC_ID));
    button1.setAction(buttonCallback);

    button2.setXY(195, 273);
    button2.setBitmaps(touchgfx::Bitmap(BITMAP_ARROW_RIGHT_MIC_ID), touchgfx::Bitmap(BITMAP_ARROW_RIGHT_MIC_ID));

    image8.setXY(100, 273);
    image8.setBitmap(touchgfx::Bitmap(BITMAP_SETTING_MIC_ID));

    container2.setPosition(-9, 177, 136, 70);

    box4.setPosition(31, 26, 90, 25);
    box4.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    container2.add(box4);

    textArea3.setXY(40, 28);
    textArea3.setColor(touchgfx::Color::getColorFromRGB(178, 218, 255));
    textArea3.setLinespacing(0);
    textArea3.setWildcard(touchgfx::TypedText(T___SINGLEUSE_94WE).getText());
    textArea3.resizeToCurrentText();
    textArea3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_VQNR));
    container2.add(textArea3);

    image3.setXY(7, 11);
    image3.setBitmap(touchgfx::Bitmap(BITMAP_THERMOMETER_2_MIC_ID));
    container2.add(image3);

    container3.setPosition(119, 198, 118, 59);

    box5.setPosition(-2, 24, 95, 24);
    box5.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    container3.add(box5);

    textArea4.setXY(2, 25);
    textArea4.setColor(touchgfx::Color::getColorFromRGB(178, 218, 255));
    textArea4.setLinespacing(0);
    textArea4.setWildcard(touchgfx::TypedText(T___SINGLEUSE_F1QU).getText());
    textArea4.resizeToCurrentText();
    textArea4.setTypedText(touchgfx::TypedText(T___SINGLEUSE_M25P));
    container3.add(textArea4);

    image7.setXY(76, 9);
    image7.setBitmap(touchgfx::Bitmap(BITMAP_HUMIDITY_2_MIC_ID));
    container3.add(image7);

    add(__background);
    add(box3);
    add(image1);
    add(image2);
    add(circle2);
    add(digitalClock1);
    add(container1);
    add(container1_1);
    add(button1);
    add(button2);
    add(image8);
    add(container2);
    add(container3);
}

void Screen3ViewBase::setupScreen()
{

}

void Screen3ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &button1)
    {
        //Interaction1
        //When button1 clicked change screen to Screen2
        //Go to Screen2 with no screen transition
        application().gotoScreen2ScreenNoTransition();
    }
}
