#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0), cntTim(0), cntAQI(0), cntCO2(0), cntBat(0)
{

}

void Model::tick()
{
	cntTim++;
	cntAQI++;
	cntCO2++;
	cntBat++;

    if(cntTim%60 == 0) // every 1 s
    {
		#ifdef USE_HAL_DRIVER
    	peripheralGetTime(&hour, &minute, &second);
		if (modelListener != 0)
		{
		modelListener->updateTime(hour, minute, second);
		}
		#endif
		cntTim = 0;
    }

    if(cntAQI%180 == 0) // every 3 s
    {
		#ifdef USE_HAL_DRIVER
    	pm25 = peripheralGetAQIpm25();
		if (modelListener != 0)
		{
			if (pm25 <= 12){
				colorPM25 = touchgfx::Color::getColorFromRGB(0, 228, 0);
				circlePM25 = 1;
			}
			if ( (pm25 > 12) && (pm25 <= 35) ){
				colorPM25 = touchgfx::Color::getColorFromRGB(255, 255, 0);
				circlePM25 = 2;
			}
			if ( (pm25 > 35) && (pm25 <= 55) ){
				colorPM25 = touchgfx::Color::getColorFromRGB(255, 126, 0);
				circlePM25 = 3;
			}
			if ( (pm25 > 55) && (pm25 <= 150) ){
				colorPM25 = touchgfx::Color::getColorFromRGB(255, 0, 0);
				circlePM25 = 4;
			}
			if ( (pm25 > 150) && (pm25 <= 250) ){
				colorPM25 = touchgfx::Color::getColorFromRGB(143, 63, 151);
				circlePM25 = 5;
			}
			if (pm25 > 250){
				colorPM25 = touchgfx::Color::getColorFromRGB(126, 0, 35);
				circlePM25 = 6;
			}

			modelListener->updatePM25(pm25, colorPM25, circlePM25);
		}
		#endif
		cntAQI = 0;
    }
    if(cntCO2%300 == 0) // every 5 s
    {
		#ifdef USE_HAL_DRIVER
    	peripheralGetCO2TempHum(&co2, &temperature, &humidity);
		if (modelListener != 0)
		{
			if (co2 < 900){
				colorCO2 = touchgfx::Color::getColorFromRGB(0, 228, 0);  //green
				circleCo2 = 3;
			} else{
				if (co2 > 1600){
					colorCO2 = touchgfx::Color::getColorFromRGB(255, 0, 0); // red
					circleCo2 = 1;
				}
				else {
					colorCO2 = touchgfx::Color::getColorFromRGB(255, 126, 0); // orange
					circleCo2 = 2;
				}
			}
			modelListener->updateCO2TempHum(co2, colorCO2, circleCo2, temperature, humidity);
		}
		#endif
		cntCO2 = 0;
    }

    if(cntBat%60 == 0) // every 1 s
    {
		#ifdef USE_HAL_DRIVER
    	peripheralGetBattery(&voltageValue, &voltagePercent);
		if (modelListener != 0)
		{
			modelListener->updateBattery(voltagePercent);
		}
		#endif
		cntBat = 0;
    }
}

