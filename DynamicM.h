// DynamicM.h : main header file for the DYNAMICM application
//

#if !defined(AFX_DYNAMICM_H__5168538E_048A_41A4_89F9_74B5E5D1872C__INCLUDED_)
#define AFX_DYNAMICM_H__5168538E_048A_41A4_89F9_74B5E5D1872C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDynamicMApp:
// See DynamicM.cpp for the implementation of this class
//

class CDynamicMApp : public CWinApp
{
public:
	CDynamicMApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynamicMApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDynamicMApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNAMICM_H__5168538E_048A_41A4_89F9_74B5E5D1872C__INCLUDED_)
