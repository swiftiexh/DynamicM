// DynamicMView.cpp : implementation of the CDynamicMView class
//

#include "stdafx.h"
#include "DynamicM.h"
#include"math.h"
#include "DynamicMDoc.h"
#include"DynamicMView.h"
#include "BaseInfo.h"
#include"data.h"
#include "dibapi.h"

#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//int m_Length_v,m_Width_v;


/////////////////////////////////////////////////////////////////////////////
// CDynamicMView

IMPLEMENT_DYNCREATE(CDynamicMView, CView)

BEGIN_MESSAGE_MAP(CDynamicMView, CView)
	//{{AFX_MSG_MAP(CDynamicMView)
	ON_COMMAND(ID_IP_GRAVITY, OnIpGravity)
	ON_COMMAND(ID_INI_FRONT, OnIniFront)
	ON_COMMAND(ID_INI_STR, OnIniStr)
	ON_COMMAND(ID_MOVE_HEI, OnMoveHei)
	ON_COMMAND(ID_INDENPEDENT_MIG, OnIndenpedentMig)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_NORMAL, OnNormal)
	ON_COMMAND(ID_TEST, OnTest)
	ON_COMMAND(ID_FLOW_ALLPORE, OnFlowAllpore)
	ON_COMMAND(ID_SECTION_SIMULATE, OnSectionSimulate)
	ON_COMMAND(ID_PLAN, OnPlan)
	ON_COMMAND(ID_NEW_CONTOUR, OnNewContour)
	ON_COMMAND(ID_TEST1, OnTest1)
	ON_COMMAND(ID_pou, Ondrawpou)
	ON_COMMAND(ID_DATA_COMPOSE, OnDataCompose)
	ON_COMMAND(ID_NEW_PENTIAL, OnNewPential)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDynamicMView construction/destruction

CDynamicMView::CDynamicMView()
{
	// TODO: add construction code here
   pprect.left=pprect.top=10;
	pprect.bottom=pprect.right=410;
}

CDynamicMView::~CDynamicMView()
{
	 
	// delete [] DNFront;
//	 delete [] DNHeight;
	// delete [] DNPore;
//	 delete [] DNStr;
	
}

BOOL CDynamicMView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDynamicMView drawing

void CDynamicMView::OnDraw(CDC* pDC)
{
	/*	CIPDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) ;
//*/	
	CDynamicMDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
    
    CFile hFile;
	// TODO: add draw code for native data here
	m_DibMem = pDoc->m_Buf;
	
	if (m_DibMem == NULL)
	{
		AfxMessageBox("Error in m_DibMem");
		return;
	}



//if (hFile == INVALID_HANDLE_VALUE)
	UINT offset = pDoc->m_Off; 
	int xDst,yDst,dxDst,dyDst,xSrc,ySrc,dxSrc,dySrc;
	LPBITMAPINFOHEADER lpbi;
	LPVOID lpDibMem;
	LPVOID lpbits=NULL;

	// get the Windows width & height
	RECT rect;
	GetClientRect(&rect);
	xDst =10; yDst = 10;    //图像坐标

	dxDst = -1;//rect.right - rect.left;
	dyDst =-1; //rect.bottom - rect.top;

	// Get Dib info
	xSrc = ySrc =0;
	lpDibMem = GlobalLock(m_DibMem);
	lpbi = (LPBITMAPINFOHEADER)lpDibMem;
	//lpbi->biWidth;
	//CFractalCmpView m;Sizex=lpbi->biWidth;
	
   dxSrc =m_Widtha ;
   dySrc = m_Lengtha;
//  Sizey= lpbi->biHeight;

  lpbits = (LPSTR)lpDibMem + offset -sizeof(BITMAPFILEHEADER);

	// Draw Dib
	HDC hdc = NULL;
	hdc = pDC->m_hDC;



	// Set Dawing flag
	UINT wFlags;
	//wFlags = DDF_DONTDRAW;
	wFlags = DDF_HALFTONE;
		//DDF_NOTKEYFRAME;

	HDRAWDIB hdd = DrawDibOpen();
	if (hdd != NULL) 
	{
	//DrawDibBegin(hdd,hdc,dxDst,dyDst,lpbi,dxSrc,dySrc,DDF_JUSTDRAWIT);
		BOOL Suc = TRUE;
		Suc = DrawDibDraw(hdd,hdc,xDst,yDst,dxDst,dyDst,lpbi,lpbits,
					xSrc,ySrc,dxSrc,dySrc,wFlags);
	//	if(Suc == FALSE) 
	//		;
	//		//AfxMessageBox("DrawDib Failed");
		
		
		DrawDibClose(hdd);
	}
	else
		AfxMessageBox("Error in DrawDibOpen");

	
	GlobalUnlock(m_DibMem);//*/

	

}

/////////////////////////////////////////////////////////////////////////////
// CDynamicMView printing

BOOL CDynamicMView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDynamicMView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDynamicMView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDynamicMView diagnostics

#ifdef _DEBUG
void CDynamicMView::AssertValid() const
{
	CView::AssertValid();
}

void CDynamicMView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDynamicMDoc* CDynamicMView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDynamicMDoc)));
	return (CDynamicMDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDynamicMView message handlers

void CDynamicMView::OnIpGravity() 
{
	// TODO: Add your command handler code here
    int      StrSize;
//    double   OilDensity,WaterDensity,GrainMean,GrainVar;
 //   double   Density;
	double Ca,Var;
    int      Length,Width;
	float	m_Grain_Size;
	float	m_Interface_Tension;
	float	m_Grain_Var;
	int n;
	float test;
    float Set[7];
	FILE *fp;

	fp=fopen("E:\\973模拟\\last p\\DynamicM\\set.data","r");

	fscanf(fp,"%d %d %f %f %f %f %f %f",&Length,&Width,&Set[2],&Set[3],&Set[4],&Set[5],&Set[6],&Set[7]);
	fclose(fp);

    m_Interface_Tension=Set[5];
	m_Grain_Size       =Set[2];
	m_Grain_Var        =Set[3];

    StrSize=Length*Width;
//	i=m_Grain_Size;
   
    

  //  int     Width,Length;
 
 //CSetView xSet;
  


//*

/*
 Width =GetSet.m_Width;
 
 GrainMean=GetSet.m_GrainMean;
 GrainVar=GetSet.m_GrainVar;
 OilDensity=GetSet.m_OilDensity;
 WaterDensity=GetSet.m_WaterDensity;
 Density=WaterDensity-OilDensity;
 //*/
   

    m_Lengtha=Length;
	m_Widtha =Width;
    StrSize=Length*Width;
    double temp=0.0;
    FILE *fp1,*fp2,*fp3;
    int tmp;
	int i,j,k;     
	int number=5;
	int Count=0;
	int counta=0;
	int m_Filename,m_F,m_Front=0;
    float Max,Min;

	Max=0.0;
	Min=50000.0;

	TCHAR cc[9];TCHAR cc1[9];

   for(i=0;i<10;i++)                    // initial the array 
		cc1[i]=48+i;
	for(i=0;i<10;i++)
		cc[i]=48+i;
	
	double *NPore,*DNPore,*m_Front_P;                 // the value of the pore
	int    *NFront,*NStr,*Size,*Record;    // NFront: front of the cluster ; NStr: cluster structure
// iniatial the array
//
	NPore =  new double[StrSize];
	NFront=  new    int[StrSize];
	NStr  =  new    int[StrSize];
	DNPore=  new double[StrSize];

	

	fp=fopen("E:\\article\\percolation BO discussion\\pore-type\\zhengtai\\pore.data","r");
    for(i=0;i<StrSize;i++)
	{
	  fscanf(fp,"%f",&test);
	  DNPore[i]=NPore[i]=test;

	}
	fclose(fp);

	for(i=0;i<StrSize;i++)
	{
		NFront[i]=1000;                         // iniatial the front value is equal to 1000
		     // inatial the network structure
	    NStr[i]=2000;                           // iniatial the stucture size is 2000  
	}

// start the simulation

	

    for(i=0;i<Width;i++)         // inatial the front of the migration 
	{	
		NStr[StrSize-i]=3000;
	
	}
	   for(i=0;i<Width;i++) 
         NFront[i]=1003;
	   for(i=0;i<Length;i++)
		  ;
// open file to write the cluster stucture
   
	CString Data1;
 /*
	CString Data;
    CFileDialog  dlg(FALSE);
	dlg.BeginModalState();
	if(dlg.DoModal())
	Data=dlg.GetPathName();
	Sleep(1000);
// file is opened
  fp=fopen(Data,"w+b");
/*

  CString F;
  CFileDialog  dlg1(TRUE);        
	dlg1.BeginModalState();
	if(dlg1.DoModal())
	  F=Data1=dlg1.GetPathName();
//*/
  CClientDC  dc(this);
	
		dc.Rectangle(10,10,Length+10,Width+10);
  
fp=fopen("E:\\article\\percolation BO discussion\\pore-type\\zhengtai\\front.data","w");
     while(NStr[number]<2500)      // start oil migration
	 {
	      for(j=0;j<StrSize;j++)
		  {
		        if(NFront[j]==1003)
				{
			         if((200+0.04*(j/Width)-NPore[j])>temp)      //  
					 {
				       number=j;
				       temp=(200+0.04*(j/Width)-NPore[number]);
					 }
				}
		  }
	     if(!(number%Width))
		 {
		   NFront[number+Width]=1003;
	       NFront[number+1]=1003;
           NFront[number]=1002;
	       NPore[number]=3000.0;
	       temp=0.0;
		 }
        else if(!((number+1)%Width))
		{
	    	NFront[number+Width]=1003;
	    	NFront[number-1]=1003;
	    	NFront[number]=1002;
	        NPore[number]=3000.0;
	        temp=0.0;
		}
	   else
	   {
	     NFront[number+Width]=1003;
	     NFront[number+1]=1003;
	     NFront[number-1]=1003;
	     NFront[number]=1002;
	     NPore[number]=3000.0;
	     temp=0.0;
	   }
    dc.SetPixel(10+(number%Width),10+Length-(number/Width),RGB(255,0,0));
	
	counta++;

	
    fprintf(fp,"%f\n",DNPore[number]);


    
/*
	
m_Filename=counta%30;
m_F=counta/30;
    if(!m_Filename)	
	{
		n = Data1.Insert(46, cc[(m_F/100)%10]);
      ASSERT(n ==Data1.GetLength());
      n = Data1.Insert(47, cc[(m_F/10)%10]);
      ASSERT(n ==Data1.GetLength());
      n = Data1.Insert(48, cc1[m_F%10]);
      ASSERT(n == Data1.GetLength());

	  fp=fopen(Data1,"w+t");  
	  for(i=0;i<StrSize;i++)
	  {  
	       if(NFront[i]==1003)
		   {
   		      fprintf(fp, "%f\n",DNPore[i] );
              m_Front++;
		   }
	  }
	    m_Front=m_Front-1;
        fprintf(fp, "%d\n",m_Front);
	  
      fclose(fp);
        m_Front_P=new double[m_Front];

	  float test1;

      fp=fopen(Data1,"r+t");
	   for(k=0;k<m_Front;k++)
	   {
		  fscanf(fp,"%f",&test1);
	      m_Front_P[k]=test1;
	   }
	  fclose(fp);

      fp=fopen(Data1,"w+t");
	  fprintf(fp, "%d\n",m_Front );
      for(k=0;k<m_Front;k++)
	  {
		  fprintf(fp,"%f\n",m_Front_P[k]);
	      
	  }
	  fclose(fp);
   

	  Data1=F;
	  m_Front=0;

	}
//*/


	 }      //*********************************there is a special thing

	fclose(fp);

//*
CString Data;
    CFileDialog  dlg(FALSE);
	dlg.BeginModalState();
	if(dlg.DoModal())
	Data=dlg.GetPathName();
	fp=fopen(Data,"w");

	float xx;
	xx=counta;
 fprintf(fp,"%f ",xx/StrSize);

  Size=new int[Count];

  fclose(fp);
//*/
  /*
  fp1=fopen(Data,"r+b");
  for(i=0;i<Count;i++)
  {
    fscanf(fp1,"%d",&Size[i]);
  }
/*
  Record=new int[StrSize];
  for(i=0;i<StrSize;i++)
	  Record[i]=0;

  for(i=0;i<Count;i++)
  {
	  tmp=Size[i];
	  Record[tmp]=1;
  }
  
    CString Data1;
    CFileDialog  dlg1(FALSE);
	dlg1.BeginModalState();
	if(dlg1.DoModal())
	Data1=dlg1.GetPathName();

	fp2=fopen(Data1,"w");
	
	for(i=0;i<StrSize;i++)
	{
		fprintf(fp2,"%d",Record[i]);
		if(!((StrSize+1)%Width))
		fprintf(fp2,"\n");
	}
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
//*/
/*
  delete [] NFront;
  delete [] NPore;
  delete [] NStr;
//*/
/*/
CString Data2;
    CFileDialog  dlg2(FALSE);
	dlg2.BeginModalState();

	if(dlg2.DoModal())
	Data1=dlg2.GetPathName();
	CBmpProc mybmp;
	
	mybmp.Save(Data2,);
//*/
	OnSaveImage();
}

void CDynamicMView::OnIniFront() 
{
 
	int Length,Width;
    COLORREF m_color1;
    CClientDC dc(this);
	int i,StrSize;
	int test;
    test=0;
	FILE *fp;
	m_color1=RGB(0,0,0);

	fp=fopen("E:\\973模拟\\last p\\DynamicM\\set.data","r");

	fscanf(fp,"%d %d",&Length,&Width);
	fclose(fp);

    m_Lengtha=Length;
	m_Widtha =Width;
    
	StrSize=Length*Width;

	DNFront =     new  int [StrSize];

	

    for(i=0;i<StrSize;i++)
	{
    	DNFront[i]=1000;
	}

NN_Ting=0;
   for(i=0;i<StrSize;i++)
   {
	m_color1=dc.GetPixel(10+i%Width,Length+10-i/Width);
	  if(m_color1==RGB(0,0,0))
	  {
		NN_Ting++;
		
	  }
		
   }
Ting= new int[NN_Ting];
   for(i=0;i<StrSize;i++)
   {
	m_color1=dc.GetPixel(10+i%Width,Length+10-i/Width);
	  if(m_color1==RGB(0,0,0))
	  {
        
		Ting[test]=i;
		test++;
		
	  }
   }




}

//***********initial the pore structure********************
//
void CDynamicMView::OnIniStr() 
{
		long int counta;
//    FILE *fp;
    int i;
//	double test;
	counta=0;
	float ttpp;
    int tmp;
	double tmp1=0.0;
	double tmp2=0.0;
	int		m_Length;
	int		m_Width;
	double	m_Grain_Size;
	double	m_Grain_Var;
	double	m_Oil_Density;
	double	m_Water_Density;
	double	m_Interface_Tension;
	double	m_Gravity;
	double	m_Contact_Angle;
	int     StrSize;
	double Ca,Var;
	float   Set[8];

    tmp=0;
	tmp1=0.0;
	m_Length=m_Width=0;
    m_Grain_Size=m_Grain_Var=m_Oil_Density=m_Water_Density=m_Interface_Tension=m_Gravity=m_Contact_Angle=0.0;
  
    FILE *fp;
	fp=fopen("E:\\973模拟\\last p\\DynamicM\\set.data","r");
	
	fscanf(fp,"%d %d %f %f %f %f %f %f",&m_Length,&m_Width,&Set[2],&Set[3],&Set[4],&Set[5],&Set[6],&Set[7]);
	
	fclose(fp);
	StrSize=m_Length*m_Width;

    DNStr   =     new  int[StrSize];
    DNPore  =    new  double[StrSize];


    COLORREF m_color;
//	int m_color;
	int mm;
 
    CClientDC dc(this);
    CPoint myPoint;

// initial the pore structure

	
    
	m_Interface_Tension=Set[5];
	m_Grain_Size       =Set[2];
	m_Grain_Var        =Set[3];
//	i=m_Grain_Size;
   Ca=(2*0.001*m_Interface_Tension)/(0.001*(m_Grain_Var));
   Var=Ca-((2*0.001*m_Interface_Tension)/(m_Grain_Size));


//COLORREF m_color1;
 /*
   for(i=0;i<StrSize;i++)
	{
     DNPore[i]=0.0;
	}
//*/
  //*
   fp=fopen("E:\\973模拟\\last p\\DynamicM\\pore.data","r");
   
   
   for(i=0;i<StrSize;i++)
   { 
       
	   fscanf(fp,"%f",&ttpp);
       DNPore[i]=ttpp;
   }

   fclose(fp);
  //*/
   int xx=0;
   fp=fopen("E:\\973模拟\\last p\\DynamicM\\setcolor.data","r");
   fscanf(fp,"%d",&xx);
   m_Color=xx;
   fclose(fp);

   for(i=0;i<StrSize;i++)
   {
	    myPoint.x=10+(i%m_Width);
		myPoint.y=m_Length+9-(i/m_Width);

	    m_color=dc.GetPixel(myPoint.x,myPoint.y);
		mm=(m_color)/(256);

	 if(( mm<=(m_Color+30) )&&( mm>=(m_Color-30) ))
	 {	
		DNPore[i]=(Ca+(Var*rand())/RAND_MAX);
	    	
	 }
	 //if(m_Color!=m_color)
		
   }
    fp=fopen("E:\\973模拟\\last p\\DynamicM\\pore.data","w");
   for(i=0;i<StrSize;i++)
   {
     fprintf(fp,"%f\n",DNPore[i]);
   }
   fclose(fp);
   

/*/
   fp=fopen("E:\\973模拟\\last p\\DynamicM\\pore.data","w");
   for(i=0;i<160000;i++)
   {
     DNPore[i]=Ca+(Ca*2*rand())/RAND_MAX;
	 fprintf(fp,"%f",DNPore[i]);	
   }
   fclose(fp);
// initial the boudary
//*/
  for(i=0;i<StrSize;i++)
  {
	DNStr[i]=2000;
  }
  for(i=0;i<(m_Width*8);i++)
  {
	DNStr[i]=3000;
	DNStr[StrSize-i]=3000;
	
  }
 
  for(i=0;i<m_Length;i++)
  {
 
    DNStr[m_Width*(i+1)-1]=3000;
    DNStr[m_Width*(i+1)-2]=3000;
	DNStr[m_Width*i]=3000;
	DNStr[m_Width*i+1]=3000;

  }
/*
  fp=fopen("E:\\973模拟\\last p\\DynamicM\\pore.data","w");
  for(i=0;i<StrSize;i++)
  {
	fprintf(fp,"%f,",DNPore[i]);
  }
  fclose(fp);
  //*/
}

void CDynamicMView::OnMoveHei() 
{
  // 定义一般变量
    int     StrSize;                    // 网格大小定义     

	int counta;                         // 计数器定义
	double temp=0.0;                    //  定义变量
//
	float test,tmp8,tmp2;
	int i,j,k,m,n,nn,flag;     
	int number=5;
	int Count=0;

	int Length,Width;                  // 网格长宽定义
	float *DNPore_tmp;      
	int   *Str,*Str_new,*DNFront_tmp;  // 定义数组指针
	int judge=0;
	int tmp;

	n=0;
	k=0;
	nn=2;flag=0;
//    COLORREF m_color1;

     CClientDC dc(this);             // 定义描述器
	 CBitmap Bitmap;                 // 定义位图句柄

	 int Step;                       // 定义步长
	 FILE *fp;                       // 定义文件指针

	 fp=fopen("E:\\973模拟\\last p\\DynamicM\\set2.data","r");   //打开步长文件
     fscanf(fp,"%d",&Step);
	 fclose(fp);

    float   Set[8];


	fp=fopen("E:\\973模拟\\last p\\DynamicM\\set.data","r");

	fscanf(fp,"%d %d %f %f %f %f %f %f",&Length,&Width,&Set[2],&Set[3],&Set[4],&Set[5],&Set[6],&Set[7]);
	fclose(fp);

    counta=0;                                     

    m_Lengtha=Length;                              // 长度
	m_Widtha =Width;                               // 宽度
	StrSize=Length*Width;                          // 网格数

	DNFront =    new  int [StrSize];              //  前缘数组
    DNHeight=    new  float[StrSize+1];           //  构造数组
	DNPore_tmp=  new  float[StrSize];             //  孔隙临时数组
	Str       =  new   int[StrSize];              //  结构控制数组
	Str_new   =  new   int[StrSize];              //  结构存贮数组
	DNFront_tmp= new  int[StrSize];               //  前缘临时数组
	DNPore     = new  double[StrSize];             //  孔隙数组
//	int *NFront;

	 DNStr   =     new  int[StrSize];
	 for(i=0;i<StrSize;i++)
	 {
    	DNStr[i]=2000;
	 }
    for(i=0;i<(Width*8);i++)
	{
    	DNStr[i]=3000;
	    DNStr[StrSize-i]=3000;
	
	}
  for(i=0;i<Length;i++)
  {
 
    DNStr[Width*(i+1)-1]=3000;
    DNStr[Width*(i+1)-2]=3000;
	DNStr[Width*i]=3000;
	DNStr[Width*i+1]=3000;

  }
    
     fp=fopen("E:\\973模拟\\last p\\DynamicM\\pore.data","r");

   for(i=0;i<StrSize;i++)
   { 
       
	   fscanf(fp,"%f",&tmp2);
       DNPore[i]=tmp2;
   }

   fclose(fp);

/*
   for(i=0;i<160000;i++)
   {
	m_color1=dc.GetPixel(10+i%400,410-i/400);
	  if(m_color1=RGB(0,0,0))
	  {
		
		DNFront[i]=1003;
		counta++;
		
	  }
		
   }
   //*/

//  get the height data
   CString Data;
    CFileDialog  dlg(TRUE);
	dlg.BeginModalState();
	if(dlg.DoModal())
	m_Data=Data=dlg.GetPathName();
fp=fopen(Data,"r");

  for(i=0;i<StrSize;i++)
  {
//	if(!(i%400))
//	 fscanf(fp,"\n");
    test=5000;
	fscanf(fp,"%f",&tmp8);
	DNHeight[i]=tmp8;
	if(DNHeight[i]<test)
		test=DNHeight[i];


  }
 
  DNHeight[StrSize+1]=test;
  fclose(fp);


  // for(i=0;i<counta;i++)
 //  {

for(n=0;n<StrSize;n++)
		{
  	       DNPore_tmp[n]=DNPore[n];
		   DNFront_tmp[n]=DNFront[n];
		   Str[n]=0;
		}
int judge2;
judge2=0;
float height;
height=0.0;
    int m_Resource_number,m_Top_number;
    float m_Cell=Set[4];


    for(i=0;i<NN_Ting;i++)
    {

		for(n=0;n<StrSize;n++)
		{
  	       DNPore_tmp[n]=DNPore[n];
		   DNFront_tmp[n]=DNFront[n];
		   Str_new[n]=0;
		}
        judge=1;
		judge2=0;
		for(m=0;m<StrSize;m++)
		DNFront[m]=1000;
	      
	 	tmp=Ting[i];
	    DNFront_tmp[n]=DNFront[tmp]=1003;
        number=tmp;
       height=DNHeight[number];

	  while((DNStr[number]<2500)&&judge&&judge2<Step)      // start oil migration
	  {
        

		  for(j=0;j<StrSize;j++)
			{
		       if(DNFront_tmp[j]==1003)
			   {
				     test=0;
				    			     
					 if((( (100000-m_Cell*height+( (Set[7]-Set[6])*9.8*m_Cell*(DNHeight[j]) ))-DNPore_tmp[j])>temp))      // -height&&(( (Set[7]-Set[6])*9.8*(DNHeight[j]) )>DNPore_tmp[j])) 
					 {
				          number=j;
				          temp=(100000-m_Cell*height+( (Set[7]-Set[6])*9.8*m_Cell*(DNHeight[j]) ))-DNPore_tmp[number];
					 }
				 
			   }
			}
	//	   if(Str[number])
	//		 judge2++;
	      
	     if(temp!=0.0)
		 {
			DNFront_tmp[number+Width]=1003;
        	DNFront_tmp[number+1]    =1003;
	        DNFront_tmp[number-1]    =1003;
			DNFront_tmp[number-Width]=1003;

            
		    
			Str_new[number]=1;

	        DNFront_tmp[number]=1002;
	        DNPore_tmp[number]=30000.0;
			
	        
		 
          dc.SetPixel(10+(number%Width),Length+10-(number/Width),RGB(150,0,0));  // 绘制初始运移图
		  
		   temp=0.0;
		   if(!Str[number])
		   judge2++;
		   
		 }
        else 
		{
			judge=0;
		}
	
	  }

	  for(n=0;n<StrSize;n++)                                                   // 判断运移次数和步长
	  {
			  if(Str[n]&&Str_new[n])                                           //运移是否重复判断
			  {
				flag=1;
			    Str[n]=Str[n]+5; //judge2++;
			  }
			  
			  if(Str_new[n]&&(!Str[n]))                                        // 前方有无油源判断
			  {
				  Str[n]=Str_new[n];
                  
				  // judge2++;
			  }
	  }
	  
	 // if(flag)
	  // nn=nn+1;
	   flag=0;

	}
   //*
	int ccount=0;
	for(k=0;k<StrSize;k++)
	  {
		  if(Str[k]>0)
		  {
			  if(Str[k]>14)
				  Str[k]=14;
			  int mm=0;
			  mm=10*Str[k]+150;
			  dc.SetPixel(10+(k%Width),Length+10-(k/Width),RGB(250,0,0));
			  ccount++;
		  }
	  }
//*/
	fp=fopen("E:\\973模拟\\last p\\DynamicM\\Str.data","w");

	float tempx;
	tempx=(float)ccount/StrSize;

    for(i=0;i<StrSize;i++)
    { 
	   fprintf(fp,"%d",Str[i]);
    }
    fclose(fp);
	fp=fopen("E:\\973模拟\\last p\\DynamicM\\So.data","w");
	fprintf(fp,"%f",tempx);
	fclose(fp);
  //*/	
	OnSaveImage();
}



void CDynamicMView::OnIndenpedentMig() 
{
int     StrSize;
//    double   OilDensity,WaterDensity,GrainMean,GrainVar;
//    double  Density;
  //  int     Length,Width;
	int counta;
	double temp=0.0;
	double temp1=0.0;

//	FILE *fp;
//	int tmp;
	float test;
	int i,j,m,n,k;     
	int number=5;
	int Count=0;
	int Length,Width;
	int		m_Length;
	int		m_Width;


	float   Set[8];

	float *DNPore_tmp;
	
	int tmp;
	n=0;
//    COLORREF m_color1;
    CClientDC dc(this);
	

	FILE *fp;

	fp=fopen("E:\\973模拟\\last p\\DynamicM\\set.data","r");


	fscanf(fp,"%d %d %f %f %f %f %f %f",&m_Length,&m_Width,&Set[2],&Set[3],&Set[4],&Set[5],&Set[6],&Set[7]);
	fclose(fp);

    counta=0;
    
	StrSize=m_Length*m_Width;
	m_Lengtha=Width=m_Width;
	m_Widtha = Length=m_Length;

	DNFront =     new  int [StrSize];
    DNHeight=    new  float[160001];
	DNPore_tmp=  new  float[StrSize];
	Str       =  new   int[StrSize];
//	int *NFront;
	

    

/*
   for(i=0;i<160000;i++)
   {
	m_color1=dc.GetPixel(10+i%400,410-i/400);
	  if(m_color1=RGB(0,0,0))
	  {
		
		DNFront[i]=1003;
		counta++;
		
	  }
		
   }
   //*/

//  get the height data
   CString Data;
    CFileDialog  dlg(TRUE);
	dlg.BeginModalState();
	if(dlg.DoModal())
	Data=dlg.GetPathName();
fp=fopen(Data,"r");

  for(i=0;i<StrSize;i++)
  {
//	if(!(i%400))
//	 fscanf(fp,"\n");
    test=5000;
	fscanf(fp,"%f",&DNHeight[i]);
	if(DNHeight[i]<test)
		test=DNHeight[i];


  }
 
  DNHeight[StrSize+1]=test;
  fclose(fp);


  // for(i=0;i<counta;i++)
 //  {
for(i=0;i<StrSize;i++)
{
	DNPore_tmp[i]=DNPore[i];
}
       for(m=0;m<StrSize;m++)
		DNFront[m]=1000;

    for(i=0;i<NN_Ting;i++)
    {
	 	tmp=Ting[i];
	    DNFront[tmp]=1003;

        if(((  1000.0+( (Set[7]-Set[6])*9.8*DNHeight[tmp] )  )-DNPore_tmp[tmp])>=temp1)
		{
			temp1=((1000.0+( (Set[7]-Set[6])*9.8*DNHeight[tmp]) )-DNPore_tmp[tmp]);
			number=tmp;
		}


	}
	  while(DNStr[number]<2500)      // start oil migration
	  {
        	for(j=0;j<StrSize;j++)
			{
		       if(DNFront[j]==1003)
			   {
				 test=0;

					 if(((1000.0+((Set[7]-Set[6])*9.8*DNHeight[j]))-DNPore_tmp[j])>temp)      //  
					 {
				          number=j;
				          temp=1000.0+((Set[7]-Set[6])*9.8*(DNHeight[number]))-DNPore[number];
					 }
				 
			   }
			}
	      
	     
        	DNFront[number+Width]=1003;
        	DNFront[number+1]    =1003;
	        DNFront[number-1]    =1003;
			DNFront[number-Width]=1003;

            if(Str[number])
				Str[number]=1*(n++);
			else Str[number]=1;

	        DNFront[number]=1002;
	        DNPore_tmp[number]=30000.0;
			
	        temp=0.0;
		 
    dc.SetPixel(10+(number%Width),Length+10-(number/Width),RGB(100,0,0));

	
	  }
	  

 /*
for(k=0;k<StrSize;k++)
	  {
		  if(Str[k]>0)
			  dc.SetPixel(10+(k%Width),410-(k/Width),RGB(Str[k]*40,0,0));
	  }

  // */
	OnSaveImage();
	
}

void CDynamicMView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	long int tmp;
	CClientDC  dc(this);
	CBaseInfo set;
	COLORREF   m_t_color;
	m_t_color=	dc.GetPixel(point.x,point.y);
	tmp=(m_t_color)/(256);
	m_Color=tmp;

//*
  FILE *fp;
	 fp=fopen("E:\\973模拟\\last p\\DynamicM\\setcolor.data","w");
  fprintf(fp,"%d",tmp);
	 fclose(fp);
//*/
	CView::OnLButtonDown(nFlags, point);
}

void CDynamicMView::OnNormal() 
{
	// TODO: Add your command handler code here
   int i,j,tmp2;
   float tmp1;
   float tmp=0.0;
   int x,y;
   int Length,Width;
   int StrSize;
   float   Set[8];
	FILE *fp;
	double Ca,Var;
   float m_Interface_Tension,m_Grain_Size,m_Grain_Var;
	fp=fopen("E:\\973模拟\\last p\\DynamicM\\set.data","r");

	fscanf(fp,"%d %d %f %f %f %f %f %f",&Length,&Width,&Set[2],&Set[3],&Set[4],&Set[5],&Set[6],&Set[7]);
	fclose(fp);
   x=y=0;

   StrSize=Length*Width;

   m_Interface_Tension=Set[5];
	m_Grain_Size       =Set[2];
	m_Grain_Var        =Set[3];
   Ca=(2*0.00001*m_Interface_Tension)/(0.001*(m_Grain_Size-m_Grain_Var));
   Var=Ca-((2*0.00001*m_Interface_Tension)/(0.001*(m_Grain_Size+m_Grain_Var)));

	FILE *fp1;
	fp=fopen("E:\\973模拟\\last p\\DynamicM\\pore.data","w");

   for(i=0;i<StrSize;i++)
   { 
	   tmp=(Ca+(Var*rand())/RAND_MAX);
	   fprintf(fp,"%f\n",tmp);
   }
   fclose(fp);

   
   fp=fopen("E:\\973模拟\\last p\\DynamicM\\height.data","w");
   fp1=fopen("E:\\973模拟\\last p\\data\\circle.data","w");

   for(i=-200;i<200;i=i+2)
	   for(j=200;j>-200;j=j-2)
	   {
		   tmp2=i*i+(j*j)/2;
		   tmp1=(float)sqrt(tmp2);

		   fprintf(fp,"%d %d %f\n",200-j,200+i,tmp1);
		   fprintf(fp1,"%f ",tmp1);
	   }
	   fclose(fp);
	   fclose(fp1);

	fp=fopen("E:\\973模拟\\last p\\DynamicM\\pore1.data","w");

   for(i=0;i<160000;i++)
   { 
	   tmp=0.0;
	   fprintf(fp,"%f\n",tmp);
   }
   fclose(fp1);


}


void CDynamicMView::UpdateCurHDIB()
{
 CRect pRect;
    
	 pRect =m_rtCnvsPos;
	// ClientToScreen(&pRect);

	AfxGetMainWnd()->ClientToScreen(&pRect); 

	if(m_hDIB!=NULL) m_hDIB=NULL;
	m_hDIB=CopyScreenToDIB(pRect);
}

BOOL CDynamicMView::OnSaveImage()
{
   

	CRect pRect;
    CDynamicMDoc* pDoc=GetDocument();

    CClientDC dc(this);
    GetClientRect(pRect);
	
   	pRect.left=pRect.Width()/3+18;
	pRect.top=12;
	pRect.right=pRect.Width()/3+m_Widtha+129;
	pRect.bottom=m_Lengtha+12;
    m_rtCnvsPos=pRect;

    CFile file;
	CFileException fe;

	 CString Data;
    CFileDialog  dlg(FALSE);
	dlg.BeginModalState();
	
	if(dlg.DoModal())
	Data=dlg.GetPathName();

	CString lpszPathName=Data;

	if(lpszPathName=="") return FALSE;
	m_sSaveFileName=lpszPathName;
	if (!file.Open(lpszPathName, CFile::modeCreate |
	  CFile::modeReadWrite | CFile::shareExclusive, &fe))
	{
		AfxMessageBox("Invald filename",MB_OK,0);
		return FALSE;
	}
	UpdateCurHDIB();

	// replace calls to Serialize with SaveDIB function
	BOOL bSuccess = FALSE;
	TRY
	{
		BeginWaitCursor();
		bSuccess = ::SaveDIB(m_hDIB, file);

		file.Close();
	}
	CATCH (CException, eSave)
	{
		file.Abort(); // will not throw an exception
		EndWaitCursor();
		AfxMessageBox("Invald filename",MB_OK,0);
		return FALSE;
	}
	END_CATCH


	EndWaitCursor();
	return 1;

}


void CDynamicMView::OnTest() 
{
	// TODO: Add your command handler code here
	int i;
	int m_Length,m_Width;
	int StrSize=0;
	float *DNPore;
	DNPore= new float[StrSize];
FILE *fp;
	fp=fopen("E:\\973模拟\\last p\\DynamicM\\set.data","r");
	
	fscanf(fp,"%d %d",&m_Length,&m_Width);
	
	fclose(fp);
	StrSize=m_Length*m_Width;
    fp=fopen("E:\\973模拟\\last p\\DynamicM\\pore.data","w");
	DNPore= new float[StrSize];
	for(i=0;i<StrSize;i++)
	{
     DNPore[i]=0.0;
	 fprintf(fp,"%f\n",DNPore[i]);

	}

    fclose(fp);
}

void CDynamicMView::OnFlowAllpore() 
{
	// TODO: Add your command handler code here
int      StrSize;
//    double   OilDensity,WaterDensity,GrainMean,GrainVar;
 //   double   Density;
	double Ca,Var;
    int      Length,Width;
	float	m_Grain_Size;
	float	m_Interface_Tension;
	float	m_Grain_Var;
	int n;
	float test;
    float Set[7];
	FILE *fp;

	fp=fopen("E:\\973模拟\\last p\\DynamicM\\set.data","r");

	fscanf(fp,"%d %d %f %f %f %f %f %f",&Length,&Width,&Set[2],&Set[3],&Set[4],&Set[5],&Set[6],&Set[7]);
	fclose(fp);

    m_Interface_Tension=Set[5];
	m_Grain_Size       =Set[2];
	m_Grain_Var        =Set[3];

    StrSize=Length*Width;
//	i=m_Grain_Size;
   
    

  //  int     Width,Length;
 
 //CSetView xSet;
  


//*

/*
 Width =GetSet.m_Width;
 
 GrainMean=GetSet.m_GrainMean;
 GrainVar=GetSet.m_GrainVar;
 OilDensity=GetSet.m_OilDensity;
 WaterDensity=GetSet.m_WaterDensity;
 Density=WaterDensity-OilDensity;
 //*/
   

    m_Lengtha=Length;
	m_Widtha =Width;
    StrSize=Length*Width;
    double temp=0.0;
    FILE *fp1,*fp2,*fp3;
    int tmp;
	int i,j,k;     
	int number=5;
	int Count=0;
	int counta=0;
	int m_Filename,m_F,m_Front=0;
    float Max,Min;

	Max=0.0;
	Min=50000.0;

	TCHAR cc[9];TCHAR cc1[9];

   for(i=0;i<10;i++)                    // initial the array 
		cc1[i]=48+i;
	for(i=0;i<10;i++)
		cc[i]=48+i;
	
	double *NPore,*DNPore,*m_Front_P;                 // the value of the pore
	int    *NFront,*NStr,*Size,*Record;    // NFront: front of the cluster ; NStr: cluster structure
// iniatial the array
//
	NPore =  new double[StrSize];
	NFront=  new    int[StrSize];
	NStr  =  new    int[StrSize];
	DNPore=  new double[StrSize];

	

	fp=fopen("E:\\article\\percolation BO discussion\\pore-type\\zhengtai\\pore.data","r");
    for(i=0;i<StrSize;i++)
	{
	  fscanf(fp,"%f",&test);
	  DNPore[i]=NPore[i]=test;

	}
	fclose(fp);

	for(i=0;i<StrSize;i++)
	{
		NFront[i]=1000;                         // iniatial the front value is equal to 1000
		     // inatial the network structure
	    NStr[i]=2000;                           // iniatial the stucture size is 2000  
	}

// start the simulation

	

    for(i=0;i<Width;i++)         // inatial the front of the migration 
	{	
		NStr[StrSize-i]=3000;
	
	}
	   for(i=0;i<Width;i++) 
         NFront[i]=1003;
	   for(i=0;i<Length;i++)
		  ;
// open file to write the cluster stucture
   
	CString Data1;
 /*
	CString Data;
    CFileDialog  dlg(FALSE);
	dlg.BeginModalState();
	if(dlg.DoModal())
	Data=dlg.GetPathName();
	Sleep(1000);
// file is opened
  fp=fopen(Data,"w+b");
/*

  CString F;
  CFileDialog  dlg1(TRUE);        
	dlg1.BeginModalState();
	if(dlg1.DoModal())
	  F=Data1=dlg1.GetPathName();
//*/
  CClientDC  dc(this);
	
		dc.Rectangle(10,10,Length+10,Width+10);
  
fp=fopen("E:\\article\\percolation BO discussion\\pore-type\\zhengtai\\front.data","w");
     while(NStr[number]<2500)      // start oil migration
	 {
	      for(j=0;j<StrSize;j++)
		  {
		        if(NFront[j]==1003)
				{
			         
					
					if((118+0.01*(j/Width))>NPore[j])      //  
					 {
				       number=j;
					   if(!(number%Width))
					   {
		                         NFront[number+Width]=1003;
	                             NFront[number+1]=1003;
                                 NFront[number]=1002;
	                             NPore[number]=3000.0;
	                            
					   }
                       else if(!((number+1)%Width))
					   {
	                          	NFront[number+Width]=1003;
	                           	NFront[number-1]=1003;
	                         	NFront[number]=1002;
	                            NPore[number]=3000.0;
	                          
					   } 
	                   else
					   {
	                          NFront[number+Width]=1003;
	                             NFront[number+1]=1003;
	                             NFront[number-1]=1003;
	                             NFront[number]=1002;
	                             NPore[number]=3000.0;
	                             
					   }
                       dc.SetPixel(10+(number%Width),10+Length-(number/Width),RGB(255,0,0));
	
	                    counta++;
				       
					 }
					 else 
						 NFront[j]=1002;
				}
		  }
	     

	
    fprintf(fp,"%f\n",DNPore[number]);


    
/*
	
m_Filename=counta%30;
m_F=counta/30;
    if(!m_Filename)	
	{
		n = Data1.Insert(46, cc[(m_F/100)%10]);
      ASSERT(n ==Data1.GetLength());
      n = Data1.Insert(47, cc[(m_F/10)%10]);
      ASSERT(n ==Data1.GetLength());
      n = Data1.Insert(48, cc1[m_F%10]);
      ASSERT(n == Data1.GetLength());

	  fp=fopen(Data1,"w+t");  
	  for(i=0;i<StrSize;i++)
	  {  
	       if(NFront[i]==1003)
		   {
   		      fprintf(fp, "%f\n",DNPore[i] );
              m_Front++;
		   }
	  }
	    m_Front=m_Front-1;
        fprintf(fp, "%d\n",m_Front);
	  
      fclose(fp);
        m_Front_P=new double[m_Front];

	  float test1;

      fp=fopen(Data1,"r+t");
	   for(k=0;k<m_Front;k++)
	   {
		  fscanf(fp,"%f",&test1);
	      m_Front_P[k]=test1;
	   }
	  fclose(fp);

      fp=fopen(Data1,"w+t");
	  fprintf(fp, "%d\n",m_Front );
      for(k=0;k<m_Front;k++)
	  {
		  fprintf(fp,"%f\n",m_Front_P[k]);
	      
	  }
	  fclose(fp);
   

	  Data1=F;
	  m_Front=0;

	}
//*/


	 }      //*********************************there is a special thing

	fclose(fp);

/*
CString Data;
    CFileDialog  dlg(FALSE);
	dlg.BeginModalState();
	if(dlg.DoModal())
	Data=dlg.GetPathName();
	fp=fopen(Data,"w");
 fprintf(fp,"%f ",counta/160000.0);

  Size=new int[Count];

  fclose(fp);
//*/
  /*
  fp1=fopen(Data,"r+b");
  for(i=0;i<Count;i++)
  {
    fscanf(fp1,"%d",&Size[i]);
  }
/*
  Record=new int[StrSize];
  for(i=0;i<StrSize;i++)
	  Record[i]=0;

  for(i=0;i<Count;i++)
  {
	  tmp=Size[i];
	  Record[tmp]=1;
  }
  
    CString Data1;
    CFileDialog  dlg1(FALSE);
	dlg1.BeginModalState();
	if(dlg1.DoModal())
	Data1=dlg1.GetPathName();

	fp2=fopen(Data1,"w");
	
	for(i=0;i<StrSize;i++)
	{
		fprintf(fp2,"%d",Record[i]);
		if(!((StrSize+1)%Width))
		fprintf(fp2,"\n");
	}
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
//*/
/*
  delete [] NFront;
  delete [] NPore;
  delete [] NStr;
//*/
/*/
CString Data2;
    CFileDialog  dlg2(FALSE);
	dlg2.BeginModalState();

	if(dlg2.DoModal())
	Data1=dlg2.GetPathName();
	CBmpProc mybmp;
	
	mybmp.Save(Data2,);
//*/
	OnSaveImage();	
}

void CDynamicMView::OnSectionSimulate() 
{

   // 定义一般变量
    int     StrSize;                    // 网格大小定义     

	int counta;                         // 计数器定义
	double temp=0.0;                    //  定义变量
//
	float test,tmp2;
	int i,j,k,m,n,nn,flag;     
	int number=5;
	int Count=0;

	int Length,Width;                  // 网格长宽定义
	float *DNPore_tmp;      
	int   *Str,*Str_new,*DNFront_tmp;  // 定义数组指针
	int judge=0;
	int tmp;

	n=0;
	k=0;
	nn=2;flag=0;
//    COLORREF m_color1;

     CClientDC dc(this);             // 定义描述器
	 CBitmap Bitmap;                 // 定义位图句柄

	 int Step;                       // 定义步长
	 FILE *fp;                       // 定义文件指针
     //int xxx=1;
	 fp=fopen("E:\\973模拟\\last p\\DynamicM\\set2.data","r");   //打开步长文件
     fscanf(fp,"%d",&Step);
	 fclose(fp);

    float   Set[8];


	fp=fopen("E:\\973模拟\\last p\\DynamicM\\set.data","r");

	fscanf(fp,"%d %d %f %f %f %f %f %f",&Length,&Width,&Set[2],&Set[3],&Set[4],&Set[5],&Set[6],&Set[7]);
	fclose(fp);

    counta=0;                                     

    m_Lengtha=Length;                              // 长度
	m_Widtha =Width;                               // 宽度
	StrSize=Length*Width;                          // 网格数

	DNFront =    new  int [StrSize];              //  前缘数组
    DNHeight=    new  float[StrSize+1];           //  构造数组
	DNPore_tmp=  new  float[StrSize];             //  孔隙临时数组
	Str       =  new   int[StrSize];              //  结构控制数组
	Str_new   =  new   int[StrSize];              //  结构存贮数组
	DNFront_tmp= new  int[StrSize];               //  前缘临时数组
	DNPore     = new  double[StrSize];             //  孔隙数组
//	int *NFront;

	 DNStr   =     new  int[StrSize];
	 for(i=0;i<StrSize;i++)
	 {
    	DNStr[i]=2000;
	 }
    for(i=0;i<(Width*8);i++)
	{
    	DNStr[i]=3000;
	    DNStr[StrSize-i]=3000;
	
	}
  for(i=0;i<Length;i++)
  {
 
    DNStr[Width*(i+1)-1]=3000;
    DNStr[Width*(i+1)-2]=3000;
	DNStr[Width*i]=3000;
	DNStr[Width*i+1]=3000;

  }
    
     fp=fopen("E:\\973模拟\\last p\\DynamicM\\pore.data","r");

   for(i=0;i<StrSize;i++)
   { 
       
	   fscanf(fp,"%f",&tmp2);
       DNPore[i]=tmp2;
   }

   fclose(fp);

/*
   for(i=0;i<160000;i++)
   {
	m_color1=dc.GetPixel(10+i%400,410-i/400);
	  if(m_color1=RGB(0,0,0))
	  {
		
		DNFront[i]=1003;
		counta++;
		
	  }
		
   }
   //*/

//  get the height data
  


  // for(i=0;i<counta;i++)
 //  {

for(n=0;n<StrSize;n++)
		{
  	       DNPore_tmp[n]=DNPore[n];
		   DNFront_tmp[n]=DNFront[n];
		   Str[n]=0;
		}
int judge2;
judge2=0;
float height;
height=0.0;
    int m_Resource_number,m_Top_number;
	float m_Cell=0.001;
//	Step=10000;
//	fp=fopen("E:\\973模拟\\last p\\DynamicM\\resource.data","r");
//	fscanf(fp,"%d %d %f",&m_Resource_number,&m_Top_number,&m_Cell);
//	fclose(fp);

    for(i=0;i<NN_Ting;i++)
    {

		for(n=0;n<StrSize;n++)
		{
  	       DNPore_tmp[n]=DNPore[n];
		   DNFront_tmp[n]=DNFront[n];
		   Str_new[n]=0;
		}
        judge=1;
		judge2=0;
		for(m=0;m<StrSize;m++)
		DNFront[m]=1000;
	      
	 	tmp=Ting[i];
	    DNFront_tmp[n]=DNFront[tmp]=1003;
        number=tmp;
       

	  while((DNStr[number]<2500)&&judge&&judge2<Step)      // start oil migration
	  {
        

		  for(j=0;j<StrSize;j++)
			{
		       if(DNFront_tmp[j]==1003)
			   {
				     test=0;
				   
					 
				{
			         if((15000+Set[5]*(j/Width)-DNPore_tmp[j])>temp)      //  
					 {
				       number=j;
				       temp=(15000+Set[5]*(j/Width)-DNPore_tmp[number]);
					 }
				}					 
 				 
			   }
			}
	//	   if(Str[number])
	//		 judge2++;
	      
	      if(temp!=0.0)
		  {
			   if(!(number%Width))
			   {
		            DNFront_tmp[number+Width]=1003;
	                DNFront_tmp[number+1]=1003;
                    DNFront_tmp[number]=1002;
	                DNPore_tmp[number]=30000.0;
	                 temp=0.0;
			   }
               else if(!((number+1)%Width))
			   {
	            	DNFront_tmp[number+Width]=1003;
	              	DNFront_tmp[number-1]=1003;
	              	DNFront_tmp[number]=1002;
	                DNPore_tmp[number]=30000.0;
	                 temp=0.0;
			   }
	           else
			   {
	                DNFront_tmp[number+Width]=1003;
	                DNFront_tmp[number+1]=1003;
	                DNFront_tmp[number-1]=1003;
	                DNFront_tmp[number]=1002;
	                DNPore_tmp[number]=30000.0;
	                    temp=0.0;
			   }

            
		    
			

	        DNFront_tmp[number]=1002;
	        DNPore_tmp[number]=30000.0;
			
	        
		 
          dc.SetPixel(10+(number%Width),Length+10-(number/Width),RGB(250,0,0));  // 绘制初始运移图
		  Str_new[number]=1;
		   temp=0.0;
		   if(!Str[number])
		   judge2++;
		   
		  }
          else 
		  {
			judge=0;
		  }
	
	  }
	}
/*
	       for(n=0;n<StrSize;n++)                                                   // 判断运移次数和步长
		   {
			  if(Str[n]&&Str_new[n])                                           //运移是否重复判断
			  {
				flag=1;
			    Str[n]=1*(nn); //judge2++;
			  }
			  
			  if(Str_new[n]&&(!Str[n]))                                        // 前方有无油源判断
			  {
				  Str[n]=Str_new[n];
                  
				  // judge2++;
			  }
		   }
//*/

	      if(flag)
	      nn=nn+1;
	      flag=0;

    
   /*
	     for(k=0;k<StrSize;k++)
		 {
		  if(Str[k]>0)
		  {
			  if(Str[k]>100)
				  Str[k]=100;
			  int mm=0;
			  mm=Str[k]+180;
			  dc.SetPixel(10+(k%Width),Length+10-(k/Width),RGB(mm,0,0));
		  }
		 }
//*/
	   fp=fopen("E:\\973模拟\\last p\\DynamicM\\Str1.data","w");

       for(i=0;i<StrSize;i++)
	   { 
	     fprintf(fp,"%d\n",Str_new[i]);
	   }
       fclose(fp);
  //*/	
    	OnSaveImage();	
}

void CDynamicMView::OnPlan() 
{
// 定义一般变量
    int     StrSize;                    // 网格大小定义     

	int counta;                         // 计数器定义
	double temp=0.0;                    //  定义变量
//
	double test,tmp2,tmp8;
	int i,j,k,m,n,nn,flag;     
	int number=5;
	int Count=0;

	int Length,Width;                  // 网格长宽定义
	double *DNPore_tmp;      
	int   *Str,*Str_new,*DNFront_tmp;  // 定义数组指针
	int judge=0;
	int tmp;

	n=0;
	k=0;
	nn=2;flag=0;
//    COLORREF m_color1;

     CClientDC dc(this);             // 定义描述器
	 CBitmap Bitmap;                 // 定义位图句柄

	 int Step;                       // 定义步长
	 FILE *fp;                       // 定义文件指针

	 fp=fopen("E:\\973模拟\\last p\\DynamicM\\setstep.data","r");   //打开步长文件
     fscanf(fp,"%d,%d",&Step);
	 fclose(fp);

    float   Set[8];


	fp=fopen("E:\\973模拟\\last p\\DynamicM\\set.data","r");

	fscanf(fp,"%d %d %f %f %f %f %f %f",&Length,&Width,&Set[2],&Set[3],&Set[4],&Set[5],&Set[6],&Set[7]);
	fclose(fp);

    counta=0;                                     

    m_Lengtha=Length;                              // 长度
	m_Widtha =Width;                               // 宽度
	StrSize=Length*Width;                          // 网格数

	DNFront =    new  int [StrSize];              //  前缘数组
    DNHeight=    new  float[StrSize+1];           //  构造数组
	DNPore_tmp=  new  double[StrSize];             //  孔隙临时数组
	Str       =  new   int[StrSize];              //  结构控制数组
	Str_new   =  new   int[StrSize];              //  结构存贮数组
	DNFront_tmp= new  int[StrSize];               //  前缘临时数组
	DNPore     = new  double[StrSize];             //  孔隙数组
//	int *NFront;

	 DNStr   =     new  int[StrSize];
	 for(i=0;i<StrSize;i++)
	 {
    	DNStr[i]=2000;
	 }
    for(i=0;i<(Width*8);i++)
	{
    	DNStr[i]=3000;
	    DNStr[StrSize-i]=3000;
	
	}
  for(i=0;i<Length;i++)
  {
 
    DNStr[Width*(i+1)-1]=3000;
    DNStr[Width*(i+1)-2]=3000;
	DNStr[Width*i]=3000;
	DNStr[Width*i+1]=3000;

  }
    
     fp=fopen("E:\\973模拟\\last p\\DynamicM\\pore.data","r");

   for(i=0;i<StrSize;i++)
   { 
       
	   fscanf(fp,"%f",&tmp2);
       DNPore[i]=tmp2;
   }

   fclose(fp);
  CString Data;
    CFileDialog  dlg(TRUE);
	dlg.BeginModalState();
	if(dlg.DoModal())
	m_Data=Data=dlg.GetPathName();
fp=fopen(Data,"r");

  for(i=0;i<StrSize;i++)
  {
//	if(!(i%400))
//	 fscanf(fp,"\n");
    test=5000;
	fscanf(fp,"%f",&tmp8);
	DNHeight[i]=tmp8;
	if(DNHeight[i]<test)
		test=DNHeight[i];


  }
 
  DNHeight[StrSize+1]=test;
  fclose(fp);
/*
   for(i=0;i<160000;i++)
   {
	m_color1=dc.GetPixel(10+i%400,410-i/400);
	  if(m_color1=RGB(0,0,0))
	  {
		
		DNFront[i]=1003;
		counta++;
		
	  }
		
   }
   //*/

//  get the height data
  


  // for(i=0;i<counta;i++)
 //  {

for(n=0;n<StrSize;n++)
		{
  	       DNPore_tmp[n]=DNPore[n];
		   DNFront_tmp[n]=DNFront[n];
		   Str[n]=0;
		}
int judge2;
judge2=0;
float height;
height=0.0;
    int m_Resource_number,m_Top_number;
	float m_Cell=0.001;
	Step=10000;
//	fp=fopen("E:\\973模拟\\last p\\DynamicM\\resource.data","r");
//	fscanf(fp,"%d %d %f",&m_Resource_number,&m_Top_number,&m_Cell);
//	fclose(fp);

    for(i=0;i<NN_Ting;i++)
    {

		for(n=0;n<StrSize;n++)
		{
  	       DNPore_tmp[n]=DNPore[n];
		   DNFront_tmp[n]=DNFront[n];
		   Str_new[n]=0;
		}
        judge=1;
		judge2=0;
		for(m=0;m<StrSize;m++)
		DNFront[m]=1000;
	      
	 	tmp=Ting[i];
	    DNFront_tmp[n]=DNFront[tmp]=1003;
        number=tmp;
       

	  while((DNStr[number]<2500)&&judge&&judge2<Step)      // start oil migration
	  {
        

		  for(j=0;j<StrSize;j++)
			{
		       if(DNFront_tmp[j]==1003)
			   {
				     test=0;
				      if((( (1000+( (Set[7]-Set[6])*9.8*0.08*(DNHeight[j]) ))-DNPore_tmp[j])>temp))      // &&(( (Set[7]-Set[6])*9.8*(DNHeight[j]) )>DNPore_tmp[j])) 
					 {
				          number=j;
				         temp=(1000+( (Set[7]-Set[6])*9.8*0.08*(DNHeight[j]) ))-DNPore_tmp[number];
					 }
					 

					// if((( (1000+( (Set[7]-Set[6])*9.8*m_Cell* (j/Width)))-DNPore_tmp[j])>temp))      // -height&&(( (Set[7]-Set[6])*9.8*(DNHeight[j]) )>DNPore_tmp[j])) 
					// {
				    //      number=j;
				    //      temp=(1000+( (Set[7]-Set[6])*9.8*m_Cell*(j/Width) ))-DNPore_tmp[number];
					// }
				 
			   }
			}
	//	   if(Str[number])
	//		 judge2++;
	      
	      if(temp!=0.0)
		  {
			   if(!(number%Width))
			   {
		            DNFront_tmp[number+Width]=1003;
	                DNFront_tmp[number+1]=1003;
                    DNFront_tmp[number]=1002;
	                DNPore_tmp[number]=30000.0;
	                 temp=0.0;
			   }
               else if(!((number+1)%Width))
			   {
	            	DNFront_tmp[number+Width]=1003;
	              	DNFront_tmp[number-1]=1003;
	              	DNFront_tmp[number]=1002;
	                DNPore_tmp[number]=30000.0;
	                 temp=0.0;
			   }
	           else
			   {
	                DNFront_tmp[number+Width]=1003;
	                DNFront_tmp[number+1]=1003;
	                DNFront_tmp[number-1]=1003;
	                DNFront_tmp[number]=1002;
	                DNPore_tmp[number]=30000.0;
	                    temp=0.0;
			   }

            
		    
			Str_new[number]=1;

	        DNFront_tmp[number]=1002;
	        DNPore_tmp[number]=30000.0;
			
	        
		 
          dc.SetPixel(10+(number%Width),Length+10-(number/Width),RGB(150,0,0));  // 绘制初始运移图
		  
		   temp=0.0;
		   if(!Str[number])
		   judge2++;
		   
		  }
          else 
		  {
			judge=0;
		  }
	
	  }
	}

	       for(n=0;n<StrSize;n++)                                                   // 判断运移次数和步长
		   {
			  if(Str[n]&&Str_new[n])                                           //运移是否重复判断
			  {
				flag=1;
			    Str[n]=1*(nn); //judge2++;
			  }
			  
			  if(Str_new[n]&&(!Str[n]))                                        // 前方有无油源判断
			  {
				  Str[n]=Str_new[n];
                  
				  // judge2++;
			  }
		   }
	  
	      if(flag)
	      nn=nn+1;
	      flag=0;

    
   //*
	     for(k=0;k<StrSize;k++)
		 {
		  if(Str[k]>0)
		  {
			  if(Str[k]>100)
				  Str[k]=100;
			  int mm=0;
			  mm=Str[k]+180;
			  dc.SetPixel(10+(k%Width),Length+10-(k/Width),RGB(mm,0,0));
		  }
		 }
//*/
	   fp=fopen("E:\\973模拟\\last p\\DynamicM\\Str.data","w");

       for(i=0;i<StrSize;i++)
	   { 
	     fprintf(fp,"%d",Str[i]);
	   }
       fclose(fp);
  //*/	
    	OnSaveImage();	
	
}

void CDynamicMView::OnNewContour() 
{
 double *pore,*height,*N_p,*N_tmp,*N_tmp2;
 float temp2;
 double temp,temp1;
 int    width,hei,i,j,k;
 double count;
 int    M,N;
 float  M1,N1;
 double Capillary_f;

 pore  = new double[160000];
 height= new double[160000];
 N_p   = new double[160000];
 N_tmp = new double[160000];
 N_tmp2 = new double[160000];
 
 FILE *fp,*fp1,*fp2,*fp3;

 count=0.0;

 i=0;

 fp=fopen("E:\\article\\平面模拟\\理论文章\\pore.data","r");

   for(i=0;i<160000;i++)
   { 
       fscanf(fp,"%f",&temp2);
       pore[i]=temp2;
   }
 fclose(fp);

fp=fopen("E:\\article\\平面模拟\\理论文章\\paris.data","r");

   for(i=0;i<160000;i++)
   { 
       fscanf(fp,"%f",&temp2);
       height[i]=temp2+50;
   }
   fclose(fp);

   fp1=fopen("E:\\article\\平面模拟\\理论文章\\newcon.data","w");
   fp2=fopen("E:\\article\\平面模拟\\理论文章\\new.data","w");
   fp3=fopen("E:\\article\\平面模拟\\理论文章\\test.data","w");

   for(i=0;i<160000;i++)
   {
	  hei  = i/400;
	  width= i%400;
//  the first part
    
	
		  if( ((hei-250)>0)&&((width-204)>0) )                     // first region
		  {
			  N=hei-250;  M=width-204;
			  if(N>M)
			  {
			      for(j=1;j<N;j++)
				  {
				     count=count+pore[(250+j)*400+204+int((M*j)/N)];
				  }

			      N_tmp[i]=count;
			      count=0.0;
			  }
			  if(N<=M)
			  {
				  for(j=1;j<M;j++)
				  {
				     count=count+pore[(250+int((N*j)/M))*400+204+j];
				  }

			      N_tmp[i]=count;
				  N_tmp2[i]=count/M;
			      count=0.0;
			  }
		  }

		  if( ((hei-250)>0)&&((width-204)<0) )                    // second region
		  {
			  N=hei-250;  M=204-width;
			  if(N>M)
			  {
			      for(j=1;j<N;j++)
				  {
				     count=count+pore[(250+j)*400+204-int((M*j)/N)];
				  }

			      N_tmp[i]=count;
				  N_tmp2[i]=count/N;
			      count=0.0;
			  }
			  if(N<=M)
			  {
				  for(j=1;j<M;j++)
				  {
				     count=count+pore[(250+int((N*j)/M))*400+(204-j)];
				  }

			      N_tmp[i]=count;
				  N_tmp2[i]=count/M;
			      count=0.0;
			  }
		  }

		  if( ((hei-250)<0)&&((width-204)>0) )                   // third region
		  {
			  N=250-hei;  M=width-204;
			  if(N>M)
			  {
			      for(j=1;j<N;j++)
				  {
				     count=count+pore[(250-j)*400+204+int((M*j)/N)];
				  }

			      N_tmp[i]=count;
				  N_tmp2[i]=count/N;
			      count=0.0;
			  }
			  if(N<=M)
			  {
				  for(j=1;j<M;j++)
				  {
				     count=count+pore[( 250-(int((N*j)/M)) )*400+204+j];
				  }

			      N_tmp[i]=count;
				  N_tmp2[i]=count/M;
			      count=0.0;
			  }
		  }

		  if( ((hei-250)<0)&&((width-204)<0) )                   // fourth region
		  {
			  N=250-hei;  M=204-width;
			  if(N>M)
			  {
			      for(j=1;j<N;j++)
				  {

				     count=count+pore[(250-j)*400+204-int((M*j)/N)];
					 //pore[(250-j)*400+204-int((M*j)/N)]

				  }

			      N_tmp[i]=count;
				  N_tmp2[i]=count/N;
			      count=0.0;
			  }
			  if(N<=M)
			  {
				  for(j=1;j<M;j++)
				  {
				     count=count+pore[( 250-(int((N*j)/M)) )*400+204-j];
				  }

			      N_tmp[i]=count;
				  N_tmp2[i]=count/M;
			      count=0.0;
			  }
		  }
	


		  

			  




      fprintf(fp3,"%f  ",N_tmp[i]/1000000000);
	  
      temp=(width-204.0)*(width-204.0)*1000000+(hei-250.0)*(hei-250.0)*1000000+height[i]*height[i];
	  temp1=pow(temp,0.5);
	  temp1=temp1/height[i];

	  N_p[i]=N_tmp[i]*pow(N_tmp2[i],1.14)*pow(temp1,-0.57);
 
	  
	  fprintf(fp1,"%f  ",N_p[i]/1000000000);

	  if(!(i%8))
	  {fprintf(fp2,"%d   %d    %f\n",width,hei,N_p[i]/1000000000);}

	  k=0;
	 


   }

   fclose(fp1);fclose(fp2);fclose(fp3);
	// TODO: Add your command handler code here
	
}

void CDynamicMView::OnTest1() 
{
	// TODO: Add your command handler code here
    int i,hei,width;
	float temp;
	FILE *fp;
	double *pore;

	pore= new double[160000];
    CClientDC dc(this);

	fp=fopen("E:\\article\\平面模拟\\理论文章\\test.data","r");
	for(i=0;i<160000;i++)
	{
		hei=i/400; width=i%400;
		fscanf(fp,"%f",&temp);
        pore[i]=temp;
		if(pore[i]<40001.0)
		dc.SetPixel(10+width,410-hei,RGB(150,0,0));			  

	}

}

void CDynamicMView::Ondrawpou() 
{
   // 定义一般变量
    int     StrSize;                    // 网格大小定义     

	int counta;                         // 计数器定义
	double temp=0.0;                    //  定义变量
//
	float test,tmp2;
	int i,j,k,m,n,nn,flag;     
	int number=5;
	int Count=0;

	int Length,Width;                  // 网格长宽定义
	      
	int   *Str;  // 

	 
	float Set[8];
    FILE *fp;

fp=fopen("E:\\973模拟\\last p\\DynamicM\\set.data","r");

	fscanf(fp,"%d %d %f %f %f %f %f %f",&Length,&Width,&Set[2],&Set[3],&Set[4],&Set[5],&Set[6],&Set[7]);
	fclose(fp);

    counta=0;                                     
    m_Lengtha=Length;                              // 长度
	m_Widtha =Width;                               // 宽度
	StrSize=Length*Width; 
Str       =  new   int[StrSize];

fp=fopen("E:\\973模拟\\last p\\DynamicM\\Str1.data","r");
for(i=0;i<StrSize;i++)
   { 
       
	   fscanf(fp,"%d",&Count);
       Str[i]=Count;
   }
CClientDC dc(this);

 for(k=0;k<StrSize;k++)
		 {
		  if(Str[k])
		  {
			  
			  dc.SetPixel(10+(k%Width),Length+10-(k/Width),RGB(255,0,0));
		  }
		 }
	
}

void CDynamicMView::OnDataCompose() 
{
	FILE *fp;

	CString Data;
	float *data1,*data2,*data3;
	float  tmp8;
	int Length,Width,StrSize,i,j;
  
	float   Set[8];


	fp=fopen("E:\\973模拟\\last p\\DynamicM\\set.data","r");

	fscanf(fp,"%d %d %f %f %f %f %f %f",&Length,&Width,&Set[2],&Set[3],&Set[4],&Set[5],&Set[6],&Set[7]);
	fclose(fp);
	StrSize=Length*Width;

	data1= new float[StrSize];
	data2= new float[StrSize];
	data3= new float[StrSize];

//	StrSize=256500;
// 打开第一个构造数据体
    CFileDialog  dlg(TRUE);
	dlg.BeginModalState();
	if(dlg.DoModal())
	m_Data=Data=dlg.GetPathName();

    fp=fopen(Data,"r");
   for(i=67100;i<StrSize;i++)
   {
	 fscanf(fp,"%f",&tmp8);
     data1[i]=tmp8;
   }fclose(fp);


// 打开第二个构造数据体
    CFileDialog  dlg1(TRUE);
	dlg1.BeginModalState();
	if(dlg1.DoModal())
	m_Data=Data=dlg1.GetPathName();


    fp=fopen(Data,"r");
   for(i=0;i<StrSize;i++)
   {
	 fscanf(fp,"%f",&tmp8);
     data2[i]=tmp8;
   }fclose(fp);

//将两个数据体进行组合

   for(i=0;i<StrSize;i++)
   {
	   if(data1[i]>80000)
		   data1[i]=0.0;
       if(data2[i]>80000)
		   data2[i]=0.0;
	   data3[i]=data1[i]+data2[i];
   }
   
//将组合的构造数据体组合结果输出
	
   CFileDialog  dlg2(FALSE);
	dlg1.BeginModalState();
	if(dlg2.DoModal())
	m_Data=Data=dlg2.GetPathName();


    fp=fopen(Data,"w");
   for(i=0;i<StrSize;i++)
   {
	 fprintf(fp,"%f\n",data3[i]);
     
   }fclose(fp);
}

void CDynamicMView::OnNewPential() 
{
	// TODO: Add your command handler code here
		FILE *fp;

	CString Data;
	float *data1,*data2,*data3;
	float  tmp8;
	int StrSize,i,j;
    StrSize=160000;
	data1= new float[StrSize];
	data2= new float[StrSize];
	data3= new float[StrSize];

	
// 打开第一个构造数据体
    CFileDialog  dlg(TRUE);
	dlg.BeginModalState();
	if(dlg.DoModal())
	m_Data=Data=dlg.GetPathName();

    fp=fopen(Data,"r");
   for(i=0;i<StrSize;i++)
   {
	 fscanf(fp,"%f",&tmp8);
     data1[i]=tmp8;
   }fclose(fp);


// 打开岩性数据体
    CFileDialog  dlg1(TRUE);
	dlg1.BeginModalState();
	if(dlg1.DoModal())
	m_Data=Data=dlg1.GetPathName();


    fp=fopen(Data,"r");
   for(i=0;i<StrSize;i++)
   {
	 fscanf(fp,"%f",&tmp8);
     data2[i]=tmp8;
   }fclose(fp);

//将两个数据体进行组合

   for(i=0;i<StrSize;i++)
   {
	   
	   data3[i]=data1[i]+data2[i];
   }
   
//将组合的构造数据体组合结果输出
	
   CFileDialog  dlg2(FALSE);
	dlg2.BeginModalState();
	if(dlg2.DoModal())
	m_Data=Data=dlg2.GetPathName();


    fp=fopen(Data,"w");
   for(i=0;i<StrSize;i++)
   {
	if(!(i%40))
	 fprintf(fp,"%d  %d  %f\n",i%400,i/400,data3[i]);
     
   }fclose(fp);

}
