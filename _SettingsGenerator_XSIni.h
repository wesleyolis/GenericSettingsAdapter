#pragma once

/*
1. Their is no escaping support.

2. Reading methods just strips the additional delimiters as required
	and is totally dependent external driver reading information
	in the same layout order as when it was written.
3. Assumes that all characters are ASCII and 
4. This is a dumb class, no intelligent lifeforms to be found here.


Example of and ini file layout.

[TagName]\n\r
Value1,Value2,Value3,|[TagName]\n\r
Value1,Value,|[TagName]\n\r
Value1,Value,
*/

class XS_Ini {

#define XS_Ini_BTrue "1"
#define XS_Ini_BFalse "0"

public:
	XS_Ini();
	XS_Ini(CString& csInitValues);

	~XS_Ini();

	void Constructor();

	void operator += (const CString& csVal);

	void operator += (const bool bVal);

	void operator += (const int iVal);

	void operator += (const double& dVal);

	void operator += (const long& dVal);

	void AddTag(const char* csVal);

	void AddListIdent();

	CString GetCString();

	bool GetBool();

	int GetInt();

	double GetDouble();

	long GetLong();

	CString GetTag();

	bool IsListIdent();

	operator CString();

	operator bool();

	operator int();

	operator double();

	operator long();

	CString*	GetValues();

private:
	CString m_csValues;
	size_t m_stPos;

	const char m_csOpenTag = '[';
	const char m_csCloseTag = ']';
	const char* m_csNewLine = "\n\r";
	const char m_csComma = ',';
	const char m_csPipe = '|';

	CString GetParam(const char cToken);

	bool RangeOk();
};
