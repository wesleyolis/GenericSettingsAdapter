#include "ExampleOfSettingsNested.h"
#include "..\_SettingsTemplate.h"
#define IDD_MySettings

#define MY_SETTINGS MySettings

#define XST XSDT(MY_SETTINGS, 1)

/*
This should be used only to validate macros generation at this point in time.
Otherwise the following containers should be commented out.
/XSVC(TestStdVector, std::vector<int>) \
//XSVC(TestXSMacro, XSTestMacro<int,int>) \
*/

#define XSS XSD(bool, BTest) \
			XSDI(bool, BTestI, true) \
			XSDD(bool, BTestD, true, CStatic) \
			XSDDI(bool, BTestDID, true, CStatic, IDD_MySettings) \
			XSVC(TestStdVector, std::vector<int>) \
			XSVC(TestXSMacro, XSTestMacro<int,int>) \
			XSVC(MyNested, std::vector<MyNested>)


#define XSS XSD(bool, BTest) \
			XSDI(bool, BTestI, true) \
			XSDD(bool, BTestD, true, CStatic) \
			XSDDI(bool, BTestDID, true, CStatic, IDD_MySettings)\
			XSVC(MyNested, std::vector<MyNested>)

#ifndef __XSMySettings
#define __XSMySettings

XSC(MY_SETTINGS)

#include "..\_SettingsGenerator.h"

};

#endif