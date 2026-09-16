// DynamicMDoc.h : interface of the CDynamicMDoc class
//
/////////////////////////////////////////////////////////////////////////////
#include"dibapi.h"
#if !defined(AFX_DYNAMICMDOC_H__1A74EF00_11EB_4495_96FC_593E85C45D34__INCLUDED_)
#define AFX_DYNAMICMDOC_H__1A74EF00_11EB_4495_96FC_593E85C45D34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDynamicMDoc : public CDocument
{
protected: // create from serialization only
	CDynamicMDoc();
	DECLARE_DYNCREATE(CDynamicMDoc)

// Attributes
public:
	HANDLE m_Buf;
	HANDLE view;
	UINT m_Off;

// Operations
public:
//    CBmpProc m_Dib;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynamicMDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDynamicMDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:


// Generated message map functions
protected:
	//{{AFX_MSG(CDynamicMDoc)
	afx_msg void OnFront();
	afx_msg void OnMyZheng();
	afx_msg void OnCount();
	afx_msg void OnZheng();
	afx_msg void OnPublica();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNAMICMDOC_H__1A74EF00_11EB_4495_96FC_593E85C45D34__INCLUDED_)
