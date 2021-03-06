#include "stdafx.h"
#include "vis1cpp.h"
#include "vis1cpp_my.h"

#include "txtget.h"


// HINSTANCE CTxtGet::m_h7;
// CTxtGet::PIDTOTEXT CTxtGet::m_pIdToText;
// CTxtGet::PIDTOPATH CTxtGet::m_pIdToPath;
// CTxtGet::PGETTD CTxtGet::m_pGetTD;
// CTxtGet::PGETWB CTxtGet::m_pGetWB;

void CTxtGet::Init()
{
// 	m_h7 = GetModuleHandle("seven.dll");
// 	
// 	m_pIdToText = (PIDTOTEXT)GetProcAddress(m_h7,"?IDToTextModule@CConfigCont@@SAHJPBDAAVCString@@PAPAVCModuleCont@@H@Z");
// 	m_pIdToPath = (PIDTOPATH)GetProcAddress(m_h7,"?IDToPath@CConfigCont@@SAHJPBDAAVCString@@PAPAVCTypedCont@@H@Z");
// 	
// 	PtrConv c;
// 	c.pV = GetProcAddress(m_h7,"?GetTextDocument@CModuleCont@@QAEPAVCDocument@@XZ");
// 	m_pGetTD = c.pGetTextDoc;
// 	
// 	c.pV = GetProcAddress(m_h7,"?GetWorkBook@CTypedCont@@QAEPAVCWorkBookDoc@@XZ");
// 	m_pGetWB = c.pGetWorkBook;
}

// CString CTxtGet::GetText(const CString& path)
// {
// 	return "";
// }

CString CTxtGet::GetGMText() const
{
	// ������ ����� GetGlobalModule() � ����� pGlobalModule->GetInternalData()->mSource �� �����������, �������� ������ ������

	CString src="";
	CModuleCont* pCont=NULL;
	//BOOL res=(*m_pIdToText)(1,"ModuleText",src,&pCont,0);
	BOOL res = CConfigCont::IDToTextModule(1,"ModuleText",src,&pCont,0);
	if(res && pCont)
	{
		//CBodyTextDoc* pDoc=(pCont->*m_pGetTD)();
		CBodyTextDoc* pDoc = static_cast<CBodyTextDoc*>( pCont->GetTextDocument() );
		if(pDoc)
			pDoc->GetText(src);
	}
	return src;
}


/*
// ��� ������� ����� GetProcAddress, ���� � ���� 1�headers �� ��������� � seven.dll
// ��� ��� CWorkBookDoc ���������, � �� 14 ������ ������, deb �� 20.
// ��������� ��:
HINSTANCE h7=GetModuleHandle("seven.dll");
PIDTOTEXT pFunc=(PIDTOTEXT)GetProcAddress(h7,"?IDToTextModule@CConfigCont@@SAHJPBDAAVCString@@PAPAVCModuleCont@@H@Z");
if(pFunc)
{
	CString path,src;
	CModuleCont* pCont;
	BOOL res=(*pFunc)(1,"ModuleText",path,&pCont,0);
	PtrConv c;
	c.pV=GetProcAddress(h7,"?GetTextDocument@CModuleCont@@QAEPAVCDocument@@XZ");
	// ��������� ������
	CBodyTextDoc* pDoc=(pCont->*c.pGetTextDoc)();
	pDoc->GetText(src);
	// �������� ����
	((COpenDoc*)pDoc)->Open();
}
��� ������ ������� ���������� �� id & kind:
Transact - ������ ����������
UserHelp - ��������
������ �� ����������.


// ������ � ������� (�� ������� ������������� �����������
PIDTOPATH pFunc=(PIDTOPATH)GetProcAddress(h7,"?IDToPath@CConfigCont@@SAHJPBDAAVCString@@PAPAVCTypedCont@@H@Z");
if(pFunc)
{
	CString id;
	CTypedCont* pCont;
	int res=(*pFunc)(13,"Subconto",id,&pCont,0);
	// �������� �����
	PtrConv c;
	c.pV=GetProcAddress(h7,"?GetWorkBook@CTypedCont@@QAEPAVCWorkBookDoc@@XZ");
	CWorkBookDoc* pDoc=(pCont->*c.pGetWorkBook)();
	((COpenDoc*)pDoc)->Open();
	// ��������� ������ � �������� ������ ��������
	CBodyTextDoc *pTxt=(CBodyTextDoc*)pDoc->GetTextDocument();
	CString src;
	pTxt->GetText(src);
	((COpenDoc*)pTxt)->Open();
}
*/