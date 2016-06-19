#include "..\_SettingsTemplate.h"

#define IDD_MySettings

#define MY_NESTED MyNested

#define XST XSDT(MY_NESTED, 1)

#define XSS XSDI(bool, BNested) \
			XSDI(bool, BNestedI, true) \
			XSDD(bool, BNestedD, true, CStatic) \
			XSDDI(bool, BNestedDID, true, CStatic, IDD_MySettings)

#ifndef __XSNested
#define __XSNested

XSC(MY_NESTED)

#include "..\_SettingsGenerator.h"

};

#endif