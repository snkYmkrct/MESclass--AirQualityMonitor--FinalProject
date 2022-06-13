// ConsoleCommands.c
// This is where you add commands:
//		1. Add a protoype
//			static eCommandResult_T ConsoleCommandVer(const char buffer[]);
//		2. Add the command to mConsoleCommandTable
//		    {"ver", &ConsoleCommandVer, HELP("Get the version string")},
//		3. Implement the function, using ConsoleReceiveParam<Type> to get the parameters from the buffer.

#include <string.h>
#include "consoleCommands.h"
#include "console.h"
#include "consoleIo.h"
#include "version.h"
#include "main.h"
#include "peripheral_data.h"

#define IGNORE_UNUSED_VARIABLE(x)     if ( &x == &x ) {}

static eCommandResult_T ConsoleCommandVer(const char buffer[]);
static eCommandResult_T ConsoleCommandHelp(const char buffer[]);
static eCommandResult_T ConsoleCommandParamExampleInt16(const char buffer[]);
static eCommandResult_T ConsoleCommandParamExampleHexUint16(const char buffer[]);
static eCommandResult_T ConsoleCommandToggleGreenLED(const char buffer[]);
static eCommandResult_T ConsoleCommandToggleRedLED(const char buffer[]);
static eCommandResult_T ConsoleCommandPrintAQIValues(const char buffer[]);
static eCommandResult_T ConsoleCommandPrintCO2Values(const char buffer[]);
static eCommandResult_T ConsoleCommandPrintBatteryValues(const char buffer[]);
static eCommandResult_T ConsoleCommandPrintDateAndTime(const char buffer[]);
static eCommandResult_T ConsoleCommandSetDateAndTime(const char buffer[]);
static eCommandResult_T ConsoleCommandTestNeopixelChangeToGivenColor(const char buffer[]);
static eCommandResult_T ConsoleCommandTestNeopixelChangeToRandomColor(const char buffer[]);
static eCommandResult_T ConsoleCommandExitConsole(const char buffer[]);

static const sConsoleCommandTable_T mConsoleCommandTable[] =
{
    {"help", &ConsoleCommandHelp, HELP("Lists the commands available")},
    {"ver", &ConsoleCommandVer, HELP("Get the version string")},
    {"int", &ConsoleCommandParamExampleInt16, HELP("How to get a signed int16 from params list: int -321")},
    {"u16h", &ConsoleCommandParamExampleHexUint16, HELP("How to get a hex u16 from the params list: u16h aB12")},
	{"tgl", &ConsoleCommandToggleGreenLED, HELP("Toggle the on board Green LED")},
	{"trl", &ConsoleCommandToggleRedLED, HELP("Toggle the on board Red LED")},
	{"aqi", &ConsoleCommandPrintAQIValues, HELP("Print values from the AQI sensor")},
	{"co2", &ConsoleCommandPrintCO2Values, HELP("Print values from the CO2 sensor")},
	{"bat", &ConsoleCommandPrintBatteryValues, HELP("Print values from the battery")},
	{"gdate", &ConsoleCommandPrintDateAndTime, HELP("Print date and time from RTC")},
	{"stime", &ConsoleCommandSetDateAndTime, HELP("Set RTC time and date")},
	{"neo", &ConsoleCommandTestNeopixelChangeToGivenColor, HELP("Test the neopixels, change screen to a given color.")},
	{"rneo", &ConsoleCommandTestNeopixelChangeToRandomColor, HELP("Test the neopixels, change screen to a random color.")},
	{"exit", &ConsoleCommandExitConsole, HELP("Exit the console.")},

	CONSOLE_COMMAND_TABLE_END // must be LAST
};

static eCommandResult_T ConsoleCommandHelp(const char buffer[])
{
	uint32_t i;
	uint32_t tableLength;
	eCommandResult_T result = COMMAND_SUCCESS;

    IGNORE_UNUSED_VARIABLE(buffer);

	tableLength = sizeof(mConsoleCommandTable) / sizeof(mConsoleCommandTable[0]);
	for ( i = 0u ; i < tableLength - 1u ; i++ )
	{
		ConsoleIoSendString(mConsoleCommandTable[i].name);
#if CONSOLE_COMMAND_MAX_HELP_LENGTH > 0
		ConsoleIoSendString(" : ");
		ConsoleIoSendString(mConsoleCommandTable[i].help);
#endif // CONSOLE_COMMAND_MAX_HELP_LENGTH > 0
		ConsoleIoSendString(STR_ENDLINE);
	}
	return result;
}

static eCommandResult_T ConsoleCommandVer(const char buffer[])
{
	eCommandResult_T result = COMMAND_SUCCESS;

    IGNORE_UNUSED_VARIABLE(buffer);

	ConsoleIoSendString(VERSION_STRING);
	ConsoleIoSendString(STR_ENDLINE);
	return result;
}

static eCommandResult_T ConsoleCommandParamExampleInt16(const char buffer[])
{
	int16_t parameterInt;
	eCommandResult_T result;
	result = ConsoleReceiveParamInt16(buffer, 1, &parameterInt);
	if ( COMMAND_SUCCESS == result )
	{
		ConsoleIoSendString("Parameter is ");
		ConsoleSendParamInt16(parameterInt);
		ConsoleIoSendString(" (0x");
		ConsoleSendParamHexUint16((uint16_t)parameterInt);
		ConsoleIoSendString(")");
		ConsoleIoSendString(STR_ENDLINE);
	}
	return result;
}
static eCommandResult_T ConsoleCommandParamExampleHexUint16(const char buffer[])
{
	uint16_t parameterUint16;
	eCommandResult_T result;
	result = ConsoleReceiveParamHexUint16(buffer, 1, &parameterUint16);
	if ( COMMAND_SUCCESS == result )
	{
		ConsoleIoSendString("Parameter is 0x");
		ConsoleSendParamHexUint16(parameterUint16);
		ConsoleIoSendString(STR_ENDLINE);
	}
	return result;
}

static eCommandResult_T ConsoleCommandToggleGreenLED(const char buffer[])
{
	// do nothing
	IGNORE_UNUSED_VARIABLE(buffer);
	HAL_GPIO_TogglePin (LD3_GPIO_Port, LD3_Pin);

	return COMMAND_SUCCESS;
}

static eCommandResult_T ConsoleCommandToggleRedLED(const char buffer[])
{
	// do nothing
	IGNORE_UNUSED_VARIABLE(buffer);
	HAL_GPIO_TogglePin (LD4_GPIO_Port, LD4_Pin);
	return COMMAND_SUCCESS;
}

static eCommandResult_T ConsoleCommandPrintAQIValues(const char buffer[])
{

	IGNORE_UNUSED_VARIABLE(buffer);
	peripheralUpdateValues();
	peripheralPrintAQI();
	return COMMAND_SUCCESS;
}

static eCommandResult_T ConsoleCommandPrintCO2Values(const char buffer[])
{

	IGNORE_UNUSED_VARIABLE(buffer);
	peripheralUpdateValues();
	peripheralPrintCo2();
	return COMMAND_SUCCESS;
}

static eCommandResult_T ConsoleCommandPrintBatteryValues(const char buffer[])
{

	IGNORE_UNUSED_VARIABLE(buffer);
	peripheralUpdateValues();
	peripheralPrintBattery();
	return COMMAND_SUCCESS;
}

static eCommandResult_T ConsoleCommandPrintDateAndTime(const char buffer[])
{

	IGNORE_UNUSED_VARIABLE(buffer);
	peripheralUpdateValues();
	peripheralPrintTime();
	return COMMAND_SUCCESS;
}

static eCommandResult_T ConsoleCommandSetDateAndTime(const char buffer[])
{

	IGNORE_UNUSED_VARIABLE(buffer);
	//TODO read the parameters to set time and date
	//peripheralSetDateANDTime();
	return COMMAND_SUCCESS;
}

static eCommandResult_T ConsoleCommandTestNeopixelChangeToGivenColor(const char buffer[])
{

	IGNORE_UNUSED_VARIABLE(buffer);
	peripheralSetAllNeopixels(0x000000);  //TODO read the parameter
	return COMMAND_SUCCESS;
}

static eCommandResult_T ConsoleCommandTestNeopixelChangeToRandomColor(const char buffer[])
{

	IGNORE_UNUSED_VARIABLE(buffer);
	peripheralSetAllNeopixelsToRandom();
	return COMMAND_SUCCESS;
}

static eCommandResult_T ConsoleCommandExitConsole(const char buffer[])
{
	// nothing to do here, just for consistency
	IGNORE_UNUSED_VARIABLE(buffer);
	return COMMAND_SUCCESS;
}


const sConsoleCommandTable_T* ConsoleCommandsGetTable(void)
{
	return (mConsoleCommandTable);
}


