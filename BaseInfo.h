#if !defined(AFX_BASEINFO_H__30D95844_BFC5_442C_918B_8616737BDDA9__INCLUDED_)
#define AFX_BASEINFO_H__30D95844_BFC5_442C_918B_8616737BDDA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BaseInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBaseInfo form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif


class CBaseInfo : public CFormView
{
protected:
	 

          // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CBaseInfo)

// Form Data
public:
	//{{AFX_DATA(CBaseInfo)
	enum { IDD = IDD_FORMVIEW };
	int		m_Length;
	int		m_Width;
	float	m_Oil_Density;
	float	m_Water_Density;
	float	m_Interface_Tension;
	float  	m_Gravity;
	float	 m_Contact_Angle;
	COLORREF m_color_Set;
	long	 m_Color;
	long	m_Step;

	double	m_Grain_Size;
	double	m_Grain_Var;
	
	//}}AFX_DATA

// Attributes
public:
   	CBaseInfo();
	virtual ~CBaseInfo();
// Operations
public:
    
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CBaseInfo)
	afx_msg void OnButtonSet();
	afx_msg void OnButtonLithology();
	afx_msg void OnSetPoint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASEINFO_H__30D95844_BFC5_442C_918B_8616737BDDA9__INCLUDED_)
