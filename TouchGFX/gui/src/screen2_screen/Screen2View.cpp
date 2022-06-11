#include <gui/screen2_screen/Screen2View.hpp>


Screen2View::Screen2View():
	counter(0)
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
    textArea1.setWildcard(txtBuffer[0]);
    textArea2.setWildcard(txtBuffer[1]);
    textArea3.setWildcard(txtBuffer[2]);
    textArea4.setWildcard(txtBuffer[3]);
    textArea5.setWildcard(txtBuffer[4]);
    textArea6.setWildcard(txtBuffer[5]);

}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}


void Screen2View::handleTickEvent()
{

    counter++;

    if(counter%300 == 0) // every 5 s
    {
	#ifdef USE_HAL_DRIVER
    	/*			PM25_AQI_Data data = {0};
	if (aiq_PMSA003I_i2c_read(&data)){
			Unicode::snprintf(txtBuffer[0], 10, "%d", data.pm10_standard);
			textArea1.resizeToCurrentText();
			textArea1.invalidate();
			Unicode::snprintf(txtBuffer[1], 10, "%d", data.pm25_standard);
			textArea2.resizeToCurrentText();
			textArea2.invalidate();
			Unicode::snprintf(txtBuffer[2], 10, "%d", data.pm100_standard);
			textArea3.resizeToCurrentText();
			textArea3.invalidate();

			Unicode::snprintf(txtBuffer[3], 10, "%d", data.pm10_env);
			textArea4.resizeToCurrentText();
			textArea4.invalidate();
			Unicode::snprintf(txtBuffer[4], 10, "%d", data.pm25_env);
			textArea5.resizeToCurrentText();
			textArea5.invalidate();
			Unicode::snprintf(txtBuffer[5], 10, "%d", data.pm100_env);
			textArea6.resizeToCurrentText();
			textArea6.invalidate();

			Unicode::snprintf(txtBuffer[6], 10, "%d", data.particles_03um);
			textArea1_1.resizeToCurrentText();
			textArea1_1.invalidate();
			Unicode::snprintf(txtBuffer[7], 10, "%d", data.particles_05um);
			textArea2_1.resizeToCurrentText();
			textArea2_1.invalidate();
			Unicode::snprintf(txtBuffer[8], 10, "%d", data.particles_10um);
			textArea3_1.resizeToCurrentText();
			textArea3_1.invalidate();
			Unicode::snprintf(txtBuffer[9], 10, "%d", data.particles_25um);
			textArea4_1.resizeToCurrentText();
			textArea4_1.invalidate();
			Unicode::snprintf(txtBuffer[10], 10, "%d", data.particles_50um);
			textArea5_1.resizeToCurrentText();
			textArea5_1.invalidate();
			Unicode::snprintf(txtBuffer[11], 10, "%d", data.particles_100um);
			textArea6_1.resizeToCurrentText();
			textArea6_1.invalidate();

		}*/
	#endif
    counter = 0;
    }


}

