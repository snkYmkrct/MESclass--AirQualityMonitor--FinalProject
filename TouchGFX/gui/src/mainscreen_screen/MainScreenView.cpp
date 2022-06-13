#include <gui/mainscreen_screen/MainScreenView.hpp>
#include <BitmapDatabase.hpp>
#include <touchgfx/Utils.hpp>

MainScreenView::MainScreenView()
{

}

void MainScreenView::startConsoleOverlay() {
    modalWindow1.show();
    modalWindow1.invalidate();
    textArea5.setVisible(true);
    textArea5.invalidate();
    textArea6.setVisible(true);
    textArea6.invalidate();

}

void MainScreenView::stopConsoleOverlay() {

    modalWindow1.hide();
    modalWindow1.invalidate();
    textArea5.setVisible(false);
    textArea5.invalidate();
    textArea6.setVisible(false);
    textArea6.invalidate();
}

void MainScreenView::updateBattery(float voltagePercent)
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


void MainScreenView::updateTime(uint32_t hour, uint32_t minute, uint32_t second)
{
	digitalClock1.setTime24Hour(hour, minute, second);
}

void MainScreenView::updatePM25(uint16_t pm25, uint32_t color, uint8_t circle)
{
	Unicode::snprintf(txtBufferPM25, 5, "%4d", pm25);
	textArea1.setColor(color);
	textArea1.invalidate();

	circle1.setVisible(false);
	circle1_1.setVisible(false);
	circle1_2.setVisible(false);
	circle1_3.setVisible(false);
	circle1_4.setVisible(false);
	circle1_5.setVisible(false);
	if (circle == 1){
		circle1.setVisible(true);
	}
	if (circle == 2){
		circle1_1.setVisible(true);
	}
	if (circle == 3){
		circle1_2.setVisible(true);
	}
	if (circle ==4){
		circle1_3.setVisible(true);
	}
	if (circle == 5){
		circle1_4.setVisible(true);
	}
	if (circle == 6){
		circle1_5.setVisible(true);
	}
	circle1.invalidate();
	circle1_1.invalidate();
	circle1_2.invalidate();
	circle1_3.invalidate();
	circle1_4.invalidate();
	circle1_5.invalidate();
}

void MainScreenView::updateCO2TempHum(uint16_t co2, uint32_t color, uint8_t circle, float temperature, float humidity)
{
	Unicode::snprintf(txtBufferCO2, 5, "%4d", co2);
	textArea2.setColor(color);
	textArea2.invalidate();

	Unicode::snprintfFloat(txtBufferTemp, 5, "%.2f", temperature);
	textArea3.invalidate();

	Unicode::snprintfFloat(txtBufferHum, 5, "%.2f", humidity);
	textArea4.invalidate();

	circle3.setVisible(false);
	circle3_1.setVisible(false);
	circle3_2.setVisible(false);
	if (circle == 1){
		circle3.setVisible(true);
	}
	if (circle == 2){
		circle3_1.setVisible(true);
	}
	if (circle == 3){
		circle3_2.setVisible(true);
	}
	circle3.invalidate();
	circle3_1.invalidate();
	circle3_2.invalidate();

}

void MainScreenView::setupScreen()
{
	MainScreenViewBase::setupScreen();

    textArea1.setWildcard(txtBufferPM25);
	textArea1.invalidate();

    textArea2.setWildcard(txtBufferCO2);
	textArea2.invalidate();

    textArea3.setWildcard(txtBufferTemp);
	textArea3.invalidate();

    textArea4.setWildcard(txtBufferHum);
	textArea4.invalidate();
}

void MainScreenView::tearDownScreen()
{
	MainScreenViewBase::tearDownScreen();
}
