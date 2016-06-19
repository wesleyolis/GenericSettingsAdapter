#undef XST
#undef XSS

#ifndef SettingsTemplate
#define SettingsTemplate

//#include <vector>

#include "_SettingsGenerator_XSIni.h"

// Type define you drivers here.
//typedef CString XS_Ini;
typedef int XS_JSon;

template<typename A, typename B>
class XSTestMacro {
};

enum XSLoadSave {
	eXS_Load,
	eXS_Save,
};

#define XSVAR(_varName) m_ ## _varName

#define XSDT(tagName, version)

#define XSD(_typeName, _varName)
#define XSDI(_typeName, _varName, _defaultValue)
#define XSDCI(_typeName, _varName, _defaultValue)
#define XSDD(_typeName, _varName, _defaultValue, _mfcControl)
#define XSDDI(_typeName, _varName, _defaultValue, _mfcControl, _dlgIdc)

#define XSVC(_varName, ...)
#define XSVCI(_varName, _containerType, ...)
#define XSVCXS(_varName, _containerType, ...)
#define XSCXS(_xsTypeName, _varName)

	#ifdef __DEBUG
		#define SettingesTemplateDoCheck
	#endif

	#ifdef SettingesTemplateDoCheck
		// Ensure that all the flesh for the class exist.
#define XSC(name) class name : virtual public IXSTemplateBase { \
			public: name () {Init();}
	#else
		#define XSC(name) class name  { \
			public: name () {Init();}
	#endif


class IXSTemplateBase
	{
		IXSTemplateBase() {
		}

		virtual ~IXSTemplateBase() {
		}
		template<typename TClassSave>
		void LoadSave(XSLoadSave eLoadSave, TClassSave obj) = 0;

		// Ensure that the class was generated using the Settings Generator
		virtual void UseTheSettingsGenerator() = 0;

	};

#endif
