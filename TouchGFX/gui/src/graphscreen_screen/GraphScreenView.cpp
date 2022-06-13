#include <gui/graphscreen_screen/GraphScreenView.hpp>
#include <BitmapDatabase.hpp>

GraphScreenView::GraphScreenView()
{

}

void GraphScreenView::setupScreen()
{
    GraphScreenViewBase::setupScreen();
}

void GraphScreenView::tearDownScreen()
{
    GraphScreenViewBase::tearDownScreen();
}

void GraphScreenView::startConsoleOverlay() {
    modalWindow1.show();
    modalWindow1.invalidate();
    textArea5.setVisible(true);
    textArea5.invalidate();
    textArea6.setVisible(true);
    textArea6.invalidate();

}

void GraphScreenView::stopConsoleOverlay() {

    modalWindow1.hide();
    modalWindow1.invalidate();
    textArea5.setVisible(false);
    textArea5.invalidate();
    textArea6.setVisible(false);
    textArea6.invalidate();

}

void GraphScreenView::updateBattery(float voltagePercent)
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


void GraphScreenView::updateTime(uint32_t hour, uint32_t minute, uint32_t second)
{
	digitalClock1.setTime24Hour(hour, minute, second);
}

void GraphScreenView::updatePM25(uint16_t pm25, uint32_t color, uint8_t circle)
{
	dynamicGraph1.addDataPoint(pm25);
	dynamicGraph1Area1Painter.setColor(color);
	dynamicGraph1.invalidate();
}

void GraphScreenView::updateCO2TempHum(uint16_t co2, uint32_t color, uint8_t circle, float temperature, float humidity)
{
	dynamicGraph2.addDataPoint(co2);
	dynamicGraph2Area1Painter.setColor(color);
	dynamicGraph2.invalidate();
	dynamicGraph3.addDataPoint(temperature);
	dynamicGraph3.invalidate();
	dynamicGraph4.addDataPoint(humidity);
	dynamicGraph4.invalidate();

}
