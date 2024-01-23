#pragma once
#include <string>
#include <string.h>
#include <xiosbase>
#include <iostream>
#include "Win.h"

class SystemMechanisms
{	
private:

	std::string GetOS() {
#ifdef _WIN32
		return this->OS = "WinOS";
#elif __linux__
		this->OS = "LinuxOS";

#endif
		
	}
	int* WHArrMonitorGet()
	{
		if (OS == "WinOS") {
			WHArrMonitor[0] = GetSystemMetrics(0);  // Set width
			WHArrMonitor[1] = GetSystemMetrics(1);  // Set height
		}
		return WHArrMonitor;
	}
	int  MonitorFrequencyGet() {
		int refreshRate = 60;
		if (OS == "WinOS") {
			HDC hdc = GetDC(NULL);
			refreshRate = GetDeviceCaps(hdc, VREFRESH);
			ReleaseDC(NULL, hdc);
		}
		return monitorFrequency = refreshRate;
	}
	
	public:
		int WHArrMonitor[2];
		int monitorFrequency;
		std::string OS;
	
	

	void PCanalysis() {
		GetOS();
		WHArrMonitorGet();
		MonitorFrequencyGet();

	}
	void Kill() {
		delete[] &WHArrMonitor[0];
		delete[] &WHArrMonitor[1];
		delete WHArrMonitor;
		delete this;
	}
	
};

