// DynamicMDoc.cpp : implementation of the CDynamicMDoc class
//

#include "stdafx.h"
#include "DynamicM.h"
#include"dibapi.h"
#include "DynamicMDoc.h"
#include"windows.h"
#include"DynamicMView.h"
#include"math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDynamicMDoc

IMPLEMENT_DYNCREATE(CDynamicMDoc, CDocument)

BEGIN_MESSAGE_MAP(CDynamicMDoc, CDocument)
	//{{AFX_MSG_MAP(CDynamicMDoc)
	ON_COMMAND(ID_FRONT, OnFront)
	ON_COMMAND(ID_MY_ZHENG, OnMyZheng)
	ON_COMMAND(ID_COUNT, OnCount)
	ON_COMMAND(ID_ZHENG, OnZheng)
	ON_COMMAND(ID_PUBLICA, OnPublica)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDynamicMDoc construction/destruction

CDynamicMDoc::CDynamicMDoc()
{
	// TODO: add one-time construction code here

}

CDynamicMDoc::~CDynamicMDoc()
{
}

BOOL CDynamicMDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDynamicMDoc serialization



/////////////////////////////////////////////////////////////////////////////
// CDynamicMDoc diagnostics

#ifdef _DEBUG
void CDynamicMDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDynamicMDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDynamicMDoc commands

BOOL CDynamicMDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
		if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	LPVOID lpmem = NULL;
	CFile file(lpszPathName,CFile::modeRead);
	BITMAPFILEHEADER fileinfo;
//for
	file.Read(&fileinfo,sizeof(fileinfo));//a=sizeof(fileinfo);
//	file1.write(&fileinfo,sizeof(fileinfo));
//	file.Read(pbuf,54);
/*	if(fileinfo.bfType != (('M'<<8)+'B'))
	{
		AfxMessageBox("Not BMP File!");
		return FALSE;
	}*/
	m_Off=fileinfo.bfOffBits; 
//	m_Off=pbuf.bfOffBits; 
//	UINT length = file.GetLength() - 54;
	UINT length = file.GetLength() - sizeof(BITMAPFILEHEADER);
	if(m_Buf != NULL) 
	{
		GlobalFree(m_Buf);
		m_Buf = NULL;
	}
	m_Buf = GlobalAlloc(GMEM_MOVEABLE|GMEM_DISCARDABLE,length);
	lpmem = GlobalLock(m_Buf);
	if(length != file.ReadHuge(lpmem,length))
	{
		GlobalUnlock(m_Buf);
		GlobalFree(m_Buf);
		m_Buf = NULL;
		lpmem = NULL;
		AfxMessageBox("Reading File Error");
		return FALSE;
	}

	GlobalUnlock(m_Buf);
	return TRUE;
}



void CDynamicMDoc::Serialize(CArchive& ar) 
{
	if (ar.IsStoring())
	{	// storing code
	}
	else
	{	// loading code
	}

}

BOOL CDynamicMDoc::OnSaveDocument(LPCTSTR slpszPathName) 
{
	// TODO: Add your specialized code here and/or call the base class


	CDynamicMView m_view;
	m_view.OnSaveImage();
	return 1;
}





void CDynamicMDoc::OnFront() 
{
	// TODO: Add your command handler code here
	CString Data,Data1;
	int Size,i,j,n=0;
	float temp,Max,Min;
	Max=0.0;
	Min=500000.0;
	Size=0;
	CString F,F1;
	float *m_Front;
	FILE *fp,*fp1;

	TCHAR cc[9];TCHAR cc1[9];

   for(i=0;i<10;i++)                    // initial the array 
		cc1[i]=48+i;
	for(i=0;i<10;i++)
		cc[i]=48+i;
//*
	CFileDialog  dlg1(TRUE);        
	    dlg1.BeginModalState();
	 if(dlg1.DoModal())
	    F=Data=dlg1.GetPathName();

	CFileDialog  dlg(FALSE);        
	    dlg.BeginModalState();
	  if(dlg.DoModal())
	    F1=Data1=dlg.GetPathName();
//*/
    for(j=0;j<429;j++)
	{
	  n = Data.Insert(57, cc[(j/100)%10]);
      ASSERT(n ==Data.GetLength());
      n = Data.Insert(58, cc[(j/10)%10]);
      ASSERT(n ==Data.GetLength());
      n = Data.Insert(59, cc1[j%10]);
      ASSERT(n == Data.GetLength());
	   fp=fopen(Data,"r");
	   fscanf(fp,"%d",&Size);
       m_Front=new float[Size];

	   for(i=0;i<Size+1;i++)
	   {
		  fscanf(fp,"%f",&temp);
		  m_Front[i]=temp;
	   }
	      fclose(fp);
	   Data=F;

	   for(i=0;i<Size;i++)
	   {
          if(m_Front[i]>Max)
		  Max=m_Front[i];
          if(m_Front[i]<Min)
		  Min=m_Front[i];
	   }

      n = Data1.Insert(53, cc[(j/100)%10]);
      ASSERT(n ==Data1.GetLength());
      n = Data1.Insert(54, cc[(j/10)%10]);
      ASSERT(n ==Data1.GetLength());
      n = Data1.Insert(55,cc1[j%10] );
      ASSERT(n == Data1.GetLength());
	  
	     fp1=fopen(Data1,"w");
	     fprintf(fp1,"%f",Max-Min);
          fclose(fp1);
		  Data1=F1;
	  Max=0.0;Min=50000.0;
	}
}

void CDynamicMDoc::OnMyZheng() 
{
	// TODO: Add your command handler code here
	
    double Ca,Var;
    int      Length,Width;
	float	m_Grain_Size;
	float	m_Interface_Tension;
	float	m_Grain_Var;
	int StrSize;
	int n,i;
//	int test;
    float Set[7];
	FILE *fp;

	fp=fopen("E:\\973Ä£Äâ\\last p\\DynamicM\\set.data","r");

	fscanf(fp,"%d %d %f %f %f %f %f %f",&Length,&Width,&Set[2],&Set[3],&Set[4],&Set[5],&Set[6],&Set[7]);
	fclose(fp);

	StrSize=Length*Width;
    m_Interface_Tension=Set[5];
	m_Grain_Size       =Set[2];
	m_Grain_Var        =Set[3];

	Ca=(2*0.00001*m_Interface_Tension)/(0.001*(m_Grain_Size-m_Grain_Var));
    Var=Ca-((2*0.00001*m_Interface_Tension)/(0.001*(m_Grain_Size+m_Grain_Var)));

	fp=fopen("E:\\article\\percolation BO discussion\\pore-type\\zhengtai\\pore.data","w");

	for(i=0;i<StrSize;i++)
	{
    	fprintf(fp,"%f\n",Ca+(Var*rand())/RAND_MAX);
	}
	fclose(fp);

}

void CDynamicMDoc::OnCount() 
{
	// TODO: Add your command handler code here
	int i;
	FILE *fp;
	CString Data,Data1,F,F1;
    float *test;
	float temp;
    float Max,Min;
	Max=0.0;Min=500000.0;
	test= new float[160000];
	CFileDialog  dlg1(TRUE);        
	    dlg1.BeginModalState();
	 if(dlg1.DoModal())
	    F=Data=dlg1.GetPathName();
   fp=fopen(Data,"r");
   for(i=0;i<160000;i++)
   {
	   fscanf(fp,"%f",&temp);
       test[i]=temp;
   }
   fclose(fp);

   for(i=0;i<160000;i++)
   {
	   if(test[i]>Max)
		   Max=test[i];
	   if(test[i]<Min)
		   Min=test[i];
   }
	CFileDialog  dlg(FALSE);        
	    dlg.BeginModalState();
	  if(dlg.DoModal())
	    F1=Data1=dlg.GetPathName();
   fp=fopen(Data1,"w");
   fprintf(fp,"%f %f",Max,Min);
   fclose(fp);

}

void CDynamicMDoc::OnZheng() 
{
	// TODO: Add your command handler code here
	 double Ca,Var,f;
    int      Length,Width;
	float	m_Grain_Size;
	float	m_Interface_Tension;
	float	m_Grain_Var;
	int StrSize;
	int n,i;
//	int test;
    float Set[7];
	FILE *fp;

	fp=fopen("E:\\973Ä£Äâ\\last p\\DynamicM\\set.data","r");

	fscanf(fp,"%d %d %f %f %f %f %f %f",&Length,&Width,&Set[2],&Set[3],&Set[4],&Set[5],&Set[6],&Set[7]);
	fclose(fp);

	StrSize=Length*Width;
    m_Interface_Tension=Set[5];
	m_Grain_Size       =Set[2];
	m_Grain_Var        =Set[3];

	Ca=(2*0.00001*m_Interface_Tension)/(0.001*(m_Grain_Size));
    Var=Ca*(Set[3]/Set[2]);



	fp=fopen("E:\\article\\percolation BO discussion\\pore-type\\zhengtai\\pore.data","w");

	for(i=0;i<StrSize;i++)
	{

		//f=10000.0*(1/sqrt(2*3.14*Var))*exp(-( pow( ((2*Ca*rand())/RAND_MAX-Ca),2))/(2*Var*Var));
        f=10000.0*(1/sqrt(2*3.14*Var))*exp(-( pow( (2*Ca*i/StrSize-Ca),2))/(2*Var*Var));
        f=50+(f*rand())/RAND_MAX;
    	
		fprintf(fp,"%f\n",f);

	}
	fclose(fp);
	
}

void CDynamicMDoc::OnPublica() 
{
	// TODO: Add your command handler code here
	FILE *fp;
	float temp;
	int i;
	float *pore;
	
	pore= new float[160000];

	fp=fopen("E:\\article\\percolation BO discussion\\pore-type\\zhengtai\\grain=0.02-var=0.01\\pore.data","r");
	for(i=0;i<160000;i++)
	{
		fscanf(fp,"%f",&temp);
		pore[i]=temp;
	}
	fclose(fp);

	fp=fopen("E:\\article\\percolation BO discussion\\pore-type\\zhengtai\\grain=0.02-var=0.01\\pore4.data","w");
    for(i=0;i<160000;i++)
	{
		fprintf(fp,"%f\n",pore[i]+100);
	
	}
}
