// Struct.h: interface for the CStruct class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRUCT_H__2ACF5D29_612D_4465_A332_EDC33EBFF8BA__INCLUDED_)
#define AFX_STRUCT_H__2ACF5D29_612D_4465_A332_EDC33EBFF8BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//#include "OXY_Value.h"

#include "Interfaces/ICloneCreated.h"

class CStruct : public CBLContext //, public Utils1cpp::ICloneCreated
{
	DECLARE_DYNCREATE(CStruct);
public:
	CStruct(int iPar = 1);
	~CStruct();
	
	static struct paramdefs
	{
		char * Names[2];
		int HasReturnValue;
		int NumberOfParams;
	}  defFnNames[];
	
	virtual int  CallAsFunc(int,CValue &,CValue * *);	//935
	virtual int  CallAsProc(int,CValue * *);	//937
// 	virtual void  DecrRef(void);	//1086
	virtual int  FindMethod(char const *)const;	//1366
	virtual int  FindProp(char const *)const;	//1369
	virtual char const *  GetCode(void)const;	//1544
	virtual int  GetDestroyUnRefd(void)const;	//1657
// 	virtual void  GetExactValue(CValue &);	//1708
	virtual class CObjID   GetID(void)const;	//1804
// 	virtual class CBLContextInternalData *  GetInternalData(void);	//1826
	virtual char const *  GetMethodName(int,int)const;	//1964
	virtual int  GetNMethods(void)const;	//2005
	virtual int  GetNParams(int)const;	//2008
	virtual int  GetNProps(void)const;	//2015
	virtual int  GetParamDefValue(int,int,CValue *)const;	//2122
	virtual char const *  GetPropName(int,int)const;	//2187
	virtual int  GetPropVal(int,CValue &)const;	//2221
	virtual long  GetTypeID(void)const;	//2505
	virtual char const *  GetTypeString(void)const;	//2513
	virtual CType   GetValueType(void)const;	//2547
	virtual int  HasRetVal(int)const;	//2657
// 	virtual void  IncrRef(void);	//2668
// 	virtual void  InitObject(CType const &);	//2721
// 	virtual void  InitObject(char const *);	//2722
	virtual int  IsExactValue(void)const;	//2808
	virtual int  IsOleContext(void)const;	//2846
	virtual int  IsPropReadable(int)const;	//2863
	virtual int  IsPropWritable(int)const;	//2865
	virtual int  IsSerializable(void);	//2874
	virtual int  SaveToString(CString &);	//3295
// 	virtual void  SelectByID(class CObjID,long);	//3350
	virtual int  SetPropVal(int,CValue const &);	//3694
	
	static class CObjID ObjID;

	//// ��������� Utils1cpp::ICloneCreated

	//virtual CBLContext* Clone(LPCSTR szClassName) const;
	
private:
    struct InnerNode
	{
		LPSTR szName;
		int nIndex;
		bool bIsPtrVal;
		CValue value;
		CValue* ptr_value;

		InnerNode(int iCurIndex, LPCSTR szKey) : szName(NULL), nIndex(iCurIndex), bIsPtrVal(false), ptr_value(NULL)
		{
			int len =strlen(szKey) +1;
			szName = new char[len];
			strcpy(szName, szKey);
		};

		~InnerNode()
		{ if (szName) delete szName; };
    }; 
	
	InnerNode* AddNewNode(LPCSTR szKey);
	void RemoveNode(LPCSTR szKey);
	void Clear();
	
	//  mutable CString m_strCur;
	int m_nCurIndex;
	//  CMapStringToPtr m_mapProperty;
	CIStringMapToPtr m_mapProperty;
	CArray<InnerNode*, InnerNode*> m_Array;
};

#endif // !defined(AFX_STRUCT_H__2ACF5D29_612D_4465_A332_EDC33EBFF8BA__INCLUDED_)
