// DynamicMView.h : interface of the CDynamicMView class
//
/////////////////////////////////////////////////////////////////////////////
//#include"shape.h"
#include"dibapi.h"
#if !defined(AFX_DYNAMICMVIEW_H__9E5CA2B1_0052_46FA_8816_DFEC2A787B2A__INCLUDED_)
#define AFX_DYNAMICMVIEW_H__9E5CA2B1_0052_46FA_8816_DFEC2A787B2A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CDynamicMDoc;

class CDynamicMView : public CView
{
protected: // create from serialization only
	
	DECLARE_DYNCREATE(CDynamicMView)

// Attributes
public:
	CDynamicMDoc* GetDocument();
	CDynamicMView();

// Operations
public:

	HANDLE m_Buf;
	UINT m_Off;
	CRect pprect;
	CString m_sSaveFileName;
    CRect  m_rtCnvsPos;
public:
	HANDLE m_DibMem;
	CPoint MyPoint;
    int m_Length_v,m_Width_v;
	int *DNStr,*DNFront;
	float *DNHeight;
	int NN_Ting;
	int *Ting;
    double *DNPore;
	int   *Str;
	int m_Color;
	int m_Widtha,m_Lengtha;
	CString m_Data;
protected:
		HDIB  m_hDIB;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynamicMView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void UpdateCurHDIB();
	BOOL OnSaveImage();
	virtual ~CDynamicMView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif



// Generated message map functions
protected:
	//	HDIB m_hDIB;
	//{{AFX_MSG(CDynamicMView)
	afx_msg void OnIpGravity();
	afx_msg void OnIniFront();
	afx_msg void OnIniStr();
	afx_msg void OnMoveHei();
	afx_msg void OnIndenpedentMig();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnNormal();
	afx_msg void OnTest();
	afx_msg void OnFlowAllpore();
	afx_msg void OnSectionSimulate();
	afx_msg void OnPlan();
	afx_msg void OnNewContour();
	afx_msg void OnTest1();
	afx_msg void Ondrawpou();
	afx_msg void OnDataCompose();
	afx_msg void OnNewPential();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DynamicMView.cpp
inline CDynamicMDoc* CDynamicMView::GetDocument()
   { return (CDynamicMDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNAMICMVIEW_H__9E5CA2B1_0052_46FA_8816_DFEC2A787B2A__INCLUDED_)
