// BaseInfo.cpp : implementation file
//

#include "stdafx.h"
#include "DynamicM.h"
#include "BaseInfo.h"
#include"data.h"
#include"DynamicMView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseInfo

IMPLEMENT_DYNCREATE(CBaseInfo, CFormView)

CBaseInfo::CBaseInfo()
	: CFormView(CBaseInfo::IDD)
{
	//{{AFX_DATA_INIT(CBaseInfo)
	m_Length = 513;
	m_Width  = 550;
	m_Oil_Density = 0.8f;
	m_Water_Density = 1.0f;
	m_Interface_Tension = 40.0f;
	m_Gravity = 0.8f;
	m_Contact_Angle = 0.0f;
	m_Color=255;
	m_Step = 1000;
	m_Grain_Size = 0.18;
	m_Grain_Var = 0.116;
	//}}AFX_DATA_INIT
}

CBaseInfo::~CBaseInfo()
{
}

void CBaseInfo::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBaseInfo)
	DDX_Text(pDX, IDC_EDIT1, m_Length);
	DDX_Text(pDX, IDC_EDIT2, m_Width);
	DDX_Text(pDX, IDC_EDIT33, m_Oil_Density);
	DDX_Text(pDX, IDC_EDIT44, m_Water_Density);
	DDX_Text(pDX, IDC_EDIT55, m_Interface_Tension);
	DDX_Text(pDX, IDC_EDIT66, m_Gravity);
	DDX_Text(pDX, IDC_EDIT77, m_Contact_Angle);
	DDX_Text(pDX, IDC_EDIT3, m_Color);
	DDX_Text(pDX, IDC_STEP, m_Step);
	DDX_Text(pDX, IDC_EDIT11, m_Grain_Size);
	DDX_Text(pDX, IDC_EDIT22, m_Grain_Var);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBaseInfo, CFormView)
	//{{AFX_MSG_MAP(CBaseInfo)
	ON_BN_CLICKED(IDC_BUTTON1, OnButtonSet)
	ON_BN_CLICKED(IDC_BUTTON2, OnButtonLithology)
	ON_COMMAND(ID_SET_POINT, OnSetPoint)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseInfo diagnostics

#ifdef _DEBUG
void CBaseInfo::AssertValid() const
{
	CFormView::AssertValid();
}

void CBaseInfo::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseInfo message handlers

void CBaseInfo::OnButtonSet() 
{
	// TODO: Add your control notification handler code here
   
	double x,y;
	x=m_Grain_Size;
	y=m_Grain_Var;
     UpdateData(TRUE);
	 FILE *fp;
	 fp=fopen("E:\\973Ä£Äâ\\last p\\DynamicM\\set.data","w");
fprintf(fp,"%d %d %f %f %f %f %f %f",m_Length,m_Width,m_Grain_Size,m_Grain_Var,m_Gravity,m_Interface_Tension,m_Oil_Density,m_Water_Density);
	 fclose(fp);

	 fp=fopen("E:\\973Ä£Äâ\\last p\\DynamicM\\set2.data","w");
	 fprintf(fp,"%d",m_Step);
	 fclose(fp);
     
	MessageBox("hi my baby, the set work is finished");	
}

void CBaseInfo::OnButtonLithology() 
{
	// TODO: Add your control notification handler code here
		FILE *fp;
		int tmp;
//*
	fp=fopen("E:\\973Ä£Äâ\\last p\\DynamicM\\setcolor.data","r");
	fscanf(fp,"%d",&m_Color);
	fclose(fp);
	tmp=m_Color;
//*/
	UpdateData(FALSE);
	
}

void CBaseInfo::OnSetPoint() 
{
	// TODO: Add your command handler code here
	CPoint mypoint;
	
}
