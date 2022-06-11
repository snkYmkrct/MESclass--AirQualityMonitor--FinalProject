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

			modelListener->updatePM25(pm25, touchgfx::Color::getColorFromRGB(35, 242, 24));
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
				colorCO2 = touchgfx::Color::getColorFromRGB(35, 242, 24);  //green
			} else{
				if (co2 > 1800){
					colorCO2 = touchgfx::Color::getColorFromRGB(217, 4, 4); // red
				}
				else {
					colorCO2 = touchgfx::Color::getColorFromRGB(214, 158, 73); // orange
				}
			}
			modelListener->updateCO2TempHum(co2, colorCO2, temperature, humidity);
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

