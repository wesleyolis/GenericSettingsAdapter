#include "TestingSettingsNested.h"
#include "..\_SettingsTemplate.h"
#define IDD_MySettings

#define TEST_SETTINGS TestSettings

#define XST XSDT(TEST_SETTINGS, 1)


#define XSS XSD(bool, BTest) \
			XSDI(bool, BTestI, true) \
			XSDD(bool, BTestD, true, CStatic) \
			XSDDI(bool, BTestDID, true, CStatic, IDD_MySettings) \
			XSVCXS(MyNested, TestingNeasted, std::vector<TestingNeasted>) \
			XSVCXS(MyNested2, TestingNeasted, std::vector<TestingNeasted>)

#ifndef __XSMySettings
#define __XSMySettings

XSC(TEST_SETTINGS)

#include "..\_SettingsGenerator.h"

};

#endif