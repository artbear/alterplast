// ��������� ����� ��� ��������� ��������� � 1�-����������� CGetDoc7 �����

class CFormBrowse:public CDocTemplate
{
public:
	BOOL IsGetDoc(){return m_pDocClass->IsDerivedFrom(RUNTIME_CLASS(CGetDoc7));}
	static void Init();				// �������������
	static void Browse(CObList&);	// ���������� ������ ����������
	static CObArray m_pTemplates;	// ������ CTemplate7*, � ������� ��� ���������� �� CGetDoc7
};

// �������������
// ������������� ������������������ ������� ����� � ���������� ��,
// ������� CGetDoc7
void CFormBrowse::Init()
{
	CWinApp* pApp=AfxGetApp();
	CFormBrowse* pTemp;
	for(POSITION pos=pApp->GetFirstDocTemplatePosition();pos;)
	{
		pTemp=(CFormBrowse*)pApp->GetNextDocTemplate(pos);
		if(pTemp->IsGetDoc())
			m_pTemplates.Add(pTemp);
	}
}
// ���������� ������ �������� �����
void CFormBrowse::Browse(CObList& lst)
{
	for(int i=0,len=m_pTemplates.GetSize();i<len;i++)
	{
		CDocTemplate* pTemp=(CDocTemplate*)m_pTemplates[i];
		for(POSITION pos=pTemp->GetFirstDocPosition();pos;)
			lst.AddTail(pTemp->GetNextDoc(pos));
	}
}

/*
������ ��� ��� ������, ��������� ����, ���������� � �.�.
*/