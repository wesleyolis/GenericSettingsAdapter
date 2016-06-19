#include "..\_SettingsTemplate.h"

#define IDD_MySettings

#define MY_SETTINGS MY_SETTINGS2;

#define XST XSDT(MY_SETTINGS2, 1)

#define XSS XSDI(bool, BTest, false) \
	XSDI(bool, BTestI, true) \
	XSDD(bool, BTestD, true, CStatic) \
	XSDDI(bool, BTestDID, true, CStatic, IDD_MySettings2) \
	//XSV(TestXSVector) \
	XSVC(TestStdVector, std::vector<int>) \
	//XSVC(TestStdVector, std::vector<int,int>) Only hear for testing macro compiling

#ifndef __XSMySettings
#define __XSMySettings

XSC(MY_SETTINGS)

#include "..\_SettingsGenerator.h"

};

#endif