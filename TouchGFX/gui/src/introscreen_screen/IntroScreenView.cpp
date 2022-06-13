#include <gui/introscreen_screen/IntroScreenView.hpp>
#include <BitmapDatabase.hpp>

IntroScreenView::IntroScreenView()
{

}

void IntroScreenView::setupScreen()
{
    IntroScreenViewBase::setupScreen();
}

void IntroScreenView::tearDownScreen()
{
    IntroScreenViewBase::tearDownScreen();
}

void IntroScreenView::updateTime(uint32_t hour, uint32_t minute, uint32_t second)
{
	digitalClock1.setTime24Hour(hour, minute, second);
}

void IntroScreenView::updateBattery(float voltagePercent)
{
	if (voltagePercent < 25.0){
		image2.setBitmap(touchgfx::Bitmap(BITMAP_BATTERY_LOW_MIC_ID));
	}
	if ( (voltagePercent >= 25.0) && (voltagePercent < 50.0) ){
			image2.setBitmap(touchgfx::Bitmap(BITMAP_BATTERY_HALF_MIC_ID));
		}
	if ( (voltagePercent >= 50.0) && (voltagePercent < 75.0) ){
			image2.setBitmap(touchgfx::Bitmap(BITMAP_BATTERY_3Q_MIC_ID));
		}
	if (voltagePercent >= 75.0){
			image2.setBitmap(touchgfx::Bitmap(BITMAP_BATTERY_FULL_MIC_ID));
		}

	image2.invalidate();
}
