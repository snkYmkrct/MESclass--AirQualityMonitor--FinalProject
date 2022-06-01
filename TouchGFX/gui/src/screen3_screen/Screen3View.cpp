#include <gui/screen3_screen/Screen3View.hpp>

Screen3View::Screen3View():
	img(3), counter(0)
{

}


void Screen3View::handleTickEvent()
{

    counter++;

    if(counter%120 == 0) // every 5 s
    {
    	image2.setBitmap(touchgfx::Bitmap(img));
    	image2.invalidate();
    	img++;
    	if (img >= 7){
    		img = 3;
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
