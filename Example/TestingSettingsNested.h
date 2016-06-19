#include "..\_SettingsTemplate.h"

#define IDD_MySettings

#define TESTING_NEASTED TestingNeasted

#define XST XSDT(TESTING_NEASTED, 1)

#define XSS XSD(bool, BNested) \
			XSDI(bool, BNestedI, true) \
			XSDD(bool, BNestedD, true, CStatic) \
			XSDDI(bool, BNestedDID, true, CStatic, IDD_MySettings)

#ifndef __XSNested
#define __XSNested

XSC(TESTING_NEASTED)

#include "..\_SettingsGenerator.h"

};

#endif