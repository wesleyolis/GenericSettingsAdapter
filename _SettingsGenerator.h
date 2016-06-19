
#undef XSDT

#undef XSD
#undef XSDI
#undef XSDCI
#undef XSDD
#undef XSDDI

#undef XSV
#undef XSVC
#undef XSVCI
#undef XSVCXS
#undef XSCXS

//-------------------------------------------------------
// Settings class TagName and Versions 
//-------------------------------------------------------
public:

#define XSDT(_tagName, _version) const char* XSVAR(csTagName) = #_tagName;\
	const int XSVAR(iVersion) = _version;
XST

#undef XSDT

//-------------------------------------------------------
// Variable Declarations 
//-------------------------------------------------------

// Define Generator Functions
#define XSD(_typeName, _varName)										_typeName XSVAR(_varName);
#define XSDI(_typeName, _varName, _defaultValue)						_typeName XSVAR(_varName);
#define XSDCI(_typeName, _varName, _defaultValue, _cast )				_typeName XSVAR(_varName);
#define XSDD(_typeName, _varName, _defaultValue, _mfcControl)			_typeName XSVAR(_varName);
#define XSDDI(_typeName, _varName, _defaultValue, _mfcControl, _dlgIdc) _typeName XSVAR(_varName);

#define XSV(_varName)		XSVector XSVAR(_varName);
#define XSVC(_varName, ...) __VA_ARGS__  XSVAR(_varName);
#define XSVCI(_varName, _containerType, ...) __VA_ARGS__  XSVAR(_varName);
#define XSVCXS(_varName, _containerType,...) __VA_ARGS__  XSVAR(_varName);
#define XSCXS(_xsTypeName, _varName) _xsTypeName XSVAR(_varName);

//Generate Variable Declarations
public:
	XSS;

// UnDefine Generator Functions
#undef XSD
#undef XSDI
#undef XSDCI
#undef XSDD
#undef XSDDI

#undef XSV
#undef XSVC
#undef XSVCI
#undef XSVCXS
#undef XSCXS

//-------------------------------------------------------
// Variable Initialization Declarations 
//-------------------------------------------------------

// Generate default Initialize
private:
void Init() {

// Define Generator Functions
#define XSD(_typeName, _varName)
#define XSDI(_typeName, _varName, _defaultValue) XSVAR(_varName)  = _defaultValue;
#define XSDCI(_typeName, _varName, _defaultValue, _cast )	XSVAR(_varName)  = _defaultValue;
#define XSDD(_typeName, _varName, _defaultValue, _mfcControl) XSVAR(_varName) = _defaultValue;
#define XSDDI(_typeName, _varName, _defaultValue, _mfcControl, _dlgIdc) XSVAR(_varName) = _defaultValue;

#define XSV(_varName) 
#define XSVC(_varName, ...) 
#define XSVCI(_varName, _containerType, ...)
#define XSVCXS(_varName, _containerType,...)
#define XSCXS(_xsTypeName, _varName)

//Generate default initialization.
	XSS;

// Undefined Generator Functions
#undef XSD
#undef XSDI
#undef XSDCI
#undef XSDD
#undef XSDDI

#undef XSV
#undef XSVC
#undef XSVCI
#undef XSVCXS
#undef XSCXS
	
}


//-------------------------------------------------------
// Copy Constructor
//-------------------------------------------------------

// Generate operator =
#undef XSDT
#define XSDT(_tagName, _version) public: void operator = (const _tagName & rhs)

XST

#undef XSDT

{
	// Define Copy Constructors
	#define XSD(_typeName, _varName) XSVAR(_varName) = rhs.XSVAR(_varName);
	#define XSDI(_typeName, _varName, _defaultValue) XSVAR(_varName)  = rhs.XSVAR(_varName);
	#define XSDCI(_typeName, _varName, _defaultValue, _cast )	XSVAR(_varName)  = rhs.XSVAR(_varName);
	#define XSDD(_typeName, _varName, _defaultValue, _mfcControl) XSVAR(_varName) = rhs.XSVAR(_varName);
	#define XSDDI(_typeName, _varName, _defaultValue, _mfcControl, _dlgIdc) XSVAR(_varName) = rhs.XSVAR(_varName);

	#define XSV(_varName) 
	#define XSVC(_varName, ...) 
	#define XSVCI(_varName, _containerType, ...) XSVAR(_varName) = rhs.XSVAR(_varName);
	#define XSVCXS(_varName, _containerType,...) XSVAR(_varName) = rhs.XSVAR(_varName);
	#define XSCXS(_xsTypeName, _varName) XSVAR(_varName) = rhs.XSVAR(_varName);

		//Generate Copy Constructor
		XSS;

	// UnDefine Copy Constructors
	#undef XSD
	#undef XSDI
	#undef XSDCI
	#undef XSDD
	#undef XSDDI

	#undef XSV
	#undef XSVC
	#undef XSVCI
	#undef XSVCXS
	#undef XSCXS
}



/*********************************************************************************
**********************************************************************************
IF THE COMPILER IS FALLING OVER, THEN TClassSave is missing some member functions.
TODO implement a base class from which TClassSave should inherit from.
**********************************************************************************
**********************************************************************************/

public:
template<typename TClassSave> void LoadSave(XSLoadSave eLoadSave, TClassSave& obj)
{
	ASSERT(FALSE);
}

template<> void LoadSave<XS_Ini>(XSLoadSave eLoadSave, XS_Ini& obj)
{
	if (eLoadSave == eXS_Save) {

		//-------------------------------------------------------
		// Template Specialization load function
		//-------------------------------------------------------

		// Save the settings TagName.
		obj.AddTag( XSVAR(csTagName) );
		obj += XSVAR(iVersion);

		// Define Generator Functions
		#define XSD(_typeName, _varName) obj += XSVAR(_varName);
		#define XSDI(_typeName, _varName, defaultValue) obj += XSVAR(_varName);
		#define XSDCI(_typeName, _varName, _defaultValue, _cast )	obj += XSVAR(_varName);
		#define XSDD(_typeName, _varName, defaultValue, _mfcControl) obj += XSVAR(_varName);
		#define XSDDI(_typeName, _varName, defaultValue, _mfcControl, _dlgIdc) obj += XSVAR(_varName);

		#define XSV(_varName) obj.AddTag( #_varName ); \
				obj.AddListIdent(); \
			 for (size_t i = 0; i < XSVAR(_varName).size(); i++) \
				XSVAR(_varName)[i].LoadSave<XS_Ini>( eLoadSave, obj );

		#define XSVC(_varName, ...) obj.AddTag( #_varName ); \
				obj.AddListIdent(); \
			for (size_t i = 0; i < XSVAR(_varName).size(); i++) \
				XSVAR(_varName)[i].LoadSave<XS_Ini>( eLoadSave, obj );

		#define XSVCI(_varName, _containerType,...) \
			obj.AddTag( #_varName ); \
			for (size_t i = 0; i < XSVAR(_varName).size(); i++) { obj.AddListIdent(); \
				obj += XSVAR(_varName)[i]; }

		#define XSVCXS(_varName, _containerType,...) \
				obj.AddTag( #_varName ); \
			for (size_t i = 0; i < XSVAR(_varName).size(); i++) { obj.AddListIdent(); \
				XSVAR(_varName)[i].LoadSave<XS_Ini>( eLoadSave, obj ); }

		#define XSCXS(_xsTypeName, _varName) XSVAR(_varName).LoadSave<XS_Ini>( eLoadSave, obj );

		// Generate the save functions
		XSS

		// UnDefined Generator Functions
		#undef XSD
		#undef XSDI
		#undef XSDCI
		#undef XSDD
		#undef XSDDI

		#undef XSV
		#undef XSVC
		#undef XSVCI
		#undef XSVCXS
		#undef XSCXS

	}
	else {

		//-------------------------------------------------------
		// Template Specialization load function
		//-------------------------------------------------------

		// Save the settings TagName.
		CString csTagName = obj.GetTag();
		int iVersion = obj;
		//XSVAR(iVersion) = obj; // Rather implement a type check here.
		// Define Generator Functions
		#define XSD(_typeName, _varName) XSVAR(_varName) = obj;
		#define XSDI(_typeName, _varName, defaultValue) XSVAR(_varName) = obj;
		#define XSDCI(_typeName, _varName, _defaultValue, _cast ) _cast temp = obj; XSVAR(_varName) = (_typeName) temp;
		#define XSDD(_typeName, _varName, defaultValue, _mfcControl) XSVAR(_varName) = obj;
		#define XSDDI(_typeName, _varName, defaultValue, _mfcControl, _dlgIdc) XSVAR(_varName) = obj;

		#define XSV(_varName) 
		#define XSVC(_varName, ...) 

		#define XSVCI(_varName, _containerType,...) {CString temp = obj.GetTag();}\
				while(obj.IsListIdent()) { \
				_containerType temp; \
				temp = obj;\
				XSVAR(_varName).push_back(temp); }

		#define XSVCXS(_varName, _containerType,...) {CString temp = obj.GetTag();}\
					while(obj.IsListIdent()) { \
					_containerType temp; \
					temp.LoadSave<XS_Ini>( eLoadSave, obj ); \
					XSVAR(_varName).push_back(temp); }

		#define XSCXS(_xsTypeName, _varName) XSVAR(_varName).LoadSave<XS_Ini>( eLoadSave, obj );

		// Generate the save functions
		XSS

		// UnDefined Generator Functions
		#undef XSD
		#undef XSDI
		#undef XSDCI
		#undef XSDD
		#undef XSDDI

		#undef XSV
		#undef XSVC
		#undef XSVCI
		#undef XSVCXS
		#undef XSCXS

	}
}

template<> void LoadSave<XS_JSon>(XSLoadSave eLoadSave, XS_JSon& obj)
{
	ASSERT(FALSE);
}



#ifdef SettingesTemplateDoCheck
private:
virtual void UseTheSettingsGenerator(){};
#endif

