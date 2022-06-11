#include <gui/screen3_screen/Screen3View.hpp>
#include <BitmapDatabase.hpp>
#include <touchgfx/Utils.hpp>

Screen3View::Screen3View():
	img(BITMAP_BATTERY_3Q_MIC_ID), counter(0)
{

}


void Screen3View::handleTickEvent()
{

    counter++;

    if(counter%120 == 0) // every 2 s
    {
    	image2.setBitmap(touchgfx::Bitmap(img));

    	img++;
    	if (img >= (BITMAP_BATTERY_3Q_MIC_ID+4)){
    		img = BITMAP_BATTERY_3Q_MIC_ID;
    	}
    counter = 0;
    }
}

void Screen3View::updateBattery(float voltagePercent)
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


void Screen3View::updateTime(uint32_t hour, uint32_t minute, uint32_t second)
{
	digitalClock1.setTime24Hour(hour, minute, second);
}

void Screen3View::updatePM25(uint16_t pm25, uint32_t color)
{
	Unicode::snprintf(txtBufferPM25, 5, "%4d", pm25);
	textArea1.setColor(color);
	//textArea1.resizeToCurrentText();
	textArea1.invalidate();
}

void Screen3View::updateCO2TempHum(uint16_t co2, uint32_t color, float temperature, float humidity)
{
	Unicode::snprintf(txtBufferCO2, 5, "%4d", co2);
	textArea2.setColor(color);
	textArea2.invalidate();

	Unicode::snprintfFloat(txtBufferTemp, 5, "%.2f", temperature);
	textArea3.invalidate();

	Unicode::snprintfFloat(txtBufferHum, 5, "%.2f", humidity);
	textArea4.invalidate();
}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();

    //memset(txtBufferPM25, 0, 4);
    textArea1.setWildcard(txtBufferPM25);
	textArea1.invalidate();

    textArea2.setWildcard(txtBufferCO2);
	textArea2.invalidate();

    textArea3.setWildcard(txtBufferTemp);
	textArea3.invalidate();

    textArea4.setWildcard(txtBufferHum);
	textArea4.invalidate();
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}
