#include <gui/screen3_screen/Screen3View.hpp>
#include <BitmapDatabase.hpp>

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
    	image2.invalidate();
    	img++;
    	if (img >= (BITMAP_BATTERY_3Q_MIC_ID+4)){
    		img = BITMAP_BATTERY_3Q_MIC_ID;
    	}
    counter = 0;
    }
}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}
