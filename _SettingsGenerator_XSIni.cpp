#include "_SettingsGenerator_XSini.h"

using namespace std;

	XS_Ini::XS_Ini() {
		Constructor();
	}

	XS_Ini::XS_Ini(CString& csInitValues) {
		Constructor();

		m_csValues = csInitValues;
	}

	XS_Ini::~XS_Ini() {}
	
	void XS_Ini::Constructor() {
		m_stPos = 0;
	}

	void XS_Ini::operator += (const CString& csVal) {

		ASSERT(csVal.Find(m_csComma) == -1);
		m_csValues += csVal;
		m_csValues += m_csComma;
	}
	
	void XS_Ini::operator += (const bool bVal) {
		
		if (bVal) {
			m_csValues += XS_Ini_BTrue;
			m_csValues += m_csComma;
		}
		else {
			m_csValues += XS_Ini_BFalse;
			m_csValues += m_csComma;
		}
	}

	void XS_Ini::operator += (const int iVal) {

		m_csValues += ItoC(iVal);
		m_csValues += m_csComma;
	}

	void XS_Ini::operator += (const double& dVal) {

		// This might not be host environment independent.
		m_csValues += FtoC(dVal);
		m_csValues += m_csComma;
	}

	void XS_Ini::operator += (const long& dVal) {

		// This might not be host environment independent.
		m_csValues += LtoC(dVal);
		m_csValues += m_csComma;
	}

	void XS_Ini::AddTag(const char* csVal) {

		m_csValues += "[";
		m_csValues += csVal;
		m_csValues += "]\n\r";
	}

	void XS_Ini::AddListIdent() {

		m_csValues += m_csPipe;
	}
	
	CString XS_Ini::GetCString() {

		return GetParam(m_csComma);
	}

	bool XS_Ini::GetBool() {

		CString csBool = GetParam(m_csComma);
		char cBool = csBool.GetAt(0);
		if ( cBool == XS_Ini_BTrue[0])
			return true;
		else
			return false;
	}

	int XS_Ini::GetInt() {

		CString csInt = GetParam(m_csComma);
		return CtoI(csInt);
	}

	double XS_Ini::GetDouble() {

		CString csDouble = GetParam(m_csComma);
		return CtoF(csDouble);
	}

	long XS_Ini::GetLong() {

		CString csLong = GetParam(m_csComma);
		return CtoL(csLong);
	}

	CString XS_Ini::GetTag() {

		m_stPos += sizeof(char);
		CString csTagName = GetParam(m_csCloseTag);
		m_stPos += (sizeof(char) * 2);

		return csTagName;
	}

	bool XS_Ini::IsListIdent() {
		
		if (!RangeOk())
			return false;

		char cPipe = m_csValues.GetAt(m_stPos);
		
		if (cPipe == m_csPipe) {
			m_stPos += sizeof(char);
			return true;
		}
		else {
			return false;
		}
	}

	XS_Ini::operator CString() {

		return GetCString();
	}

	XS_Ini::operator bool() {

		return GetBool();
	}

	XS_Ini::operator int() {

		return GetInt();
	}

	XS_Ini::operator double() {

		return GetDouble();
	}

	XS_Ini::operator long() {

		return GetLong();
	}

	CString*	XS_Ini::GetValues() {

		return &m_csValues;
	}

	
	CString XS_Ini::GetParam(const char cToken) {

		if (!RangeOk())
			return "";

		size_t stNextPos = m_csValues.Find(cToken, m_stPos);

		if (stNextPos == -1){
			ASSERT(FALSE);
			return "";
		}
		

		size_t stLenght = stNextPos - m_stPos;
		
		size_t stStart = m_stPos;
		m_stPos = stNextPos + 1;

		return m_csValues.Mid(stStart, stLenght);
	}

	bool XS_Ini::RangeOk() {

		return (m_stPos < m_csValues.GetLength());
	}
