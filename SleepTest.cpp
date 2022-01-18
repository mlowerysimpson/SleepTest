//#include "cv.h"
//include "cvaux.hpp"
//#include "TFMini.h" //--> uncomment if using TF Mini
#include "../RemoteControlTest/DiagnosticsSensor.h"
#include "../RemoteControlTest/Util.h"
#include <wiringPi.h>
#include <wiringSerial.h>
#include <errno.h>
#include <cstring>

#include <iostream>


using namespace std;

void ShowUsage() {
	printf("SleepTest\n");
	printf("Usage: SleepTest <N>\n");
	printf("The SleepTest program accepts a single arguement, which is the length of time to put AMOS to sleep, in minutes.\n");
}

int main(int argc, const char* argv[])
{
	const int MIN_SLEEP_TIME = 2; //minimum length of time to go to sleep
	int MAX_SLEEP_TIME = 24*60;
	if (wiringPiSetup () == -1) {
		printf ("Unable to start wiringPi.\n");
		return -1 ;
	}
	bool bContainsHelpFlag = Util::ContainsHelpFlag(argc, argv);
	if (bContainsHelpFlag||argc!=2) {
		ShowUsage();
		return 1;
	}
	int nSleepTimeMinutes = 0;
	if (sscanf(argv[1],"%d",&nSleepTimeMinutes)<1) {
		printf("Invalid sleep time.\n");
	}
	if (nSleepTimeMinutes<MIN_SLEEP_TIME||nSleepTimeMinutes>MAX_SLEEP_TIME) {
		printf("Invalid sleep time, must be between %d and %d minutes.\n",MIN_SLEEP_TIME,MAX_SLEEP_TIME);
		return 2;
	}
	printf("About to go to sleep for %d minutes.\n",nSleepTimeMinutes);
	DiagnosticsSensor diag(nullptr);
	diag.EnterSleepMode(60*nSleepTimeMinutes);
	//halt Pi to make sure that it can be safely powered off by the RFU220SU
	system("halt");
	return 0;
}
