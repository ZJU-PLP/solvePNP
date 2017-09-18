#include <iostream>  
#include "opencv2/highgui/highgui.hpp"  
#include "opencv2/imgproc/imgproc.hpp"  
#include <vector>
#include "opencv2/opencv.hpp"
//#include <contours2.cpp>
using namespace cv;  
using namespace std;  
void bwLabel(const Mat& imgBw, Mat & imgLabeled);
 void brightnessException (Mat InputImg,float& cast,float& da);
Point  centerOfGravity(Mat& input,int &x,int &y);
int  coordinate(Point First,Point Second,Point centre,Point2d Sensor_Size,int H);
int height=0,width=0;
float cast=0,da=0;
//#define DEBUG
#ifdef DEBUG
#define dbg(de)        printf(de)
#else
#define dbg()    
#endif

#define focalLength 4.75  //������������ߴ磬��λmm
Point2d centrePoint;  
Point2d SensorSize;
int realH=420;

 int main( int argc, char** argv )  
 {  
	 centrePoint.x=316.835;
	 centrePoint.y=247.917;
	 
	 SensorSize.x=3.2;
	 SensorSize.y=2.4;
	int x=0,y=0;
    VideoCapture cap(1); //capture the video from web cam  
	width=cap.get(CV_CAP_PROP_FRAME_HEIGHT );
	height=cap.get(CV_CAP_PROP_FRAME_HEIGHT );

    if ( !cap.isOpened() )  // if not success, exit program  
    {  
         cout << "Cannot open the web cam" << endl;  
         return -1;  
    }  
  
  namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"  
  
  Mat cameraMatrix = Mat::eye(3, 3, CV_64F);
    cameraMatrix.at<double>(0, 0) = 4.377083949726417e+02;
    cameraMatrix.at<double>(0, 1) = 0.021564701076255;
    cameraMatrix.at<double>(0, 2) = 3.260491311579127e+02;
    cameraMatrix.at<double>(1, 1) = 4.375146185726212e+02;
    cameraMatrix.at<double>(1, 2) = 2.436940467669944e+02;

    Mat distCoeffs = Mat::zeros(5, 1, CV_64F);
    distCoeffs.at<double>(0, 0) = -0.385541673306882;
    distCoeffs.at<double>(1, 0) = 0.145556723650446;
    distCoeffs.at<double>(2, 0) = 6.057456843815020e-04;
    distCoeffs.at<double>(3, 0) = -0.001158039562780;
    distCoeffs.at<double>(4, 0) = 0;

    Mat view, rview, map1, map2;
    Size imageSize;
	Mat imgOriginal;  
    cap.read(imgOriginal); // read a new frame from video  

    imageSize = imgOriginal.size();
    initUndistortRectifyMap(cameraMatrix, distCoeffs, Mat(),
        getOptimalNewCameraMatrix(cameraMatrix, distCoeffs, imageSize, 1, imageSize, 0),
        imageSize, CV_16SC2, map1, map2);


  int exposure=6;
	//exposure = cap.get(CV_CAP_PROP_EXPOSURE);
	//cout<<exposure<<endl;
	exposure*=(-1);
  int GLowH = 60;  
  int GHighH = 71;  
  
  int RLowH = 0;  
  int RHighH = 15; 

  int iLowS = 147;   
  int iHighS = 255;  
  
  int iLowV = 200;  
  int iHighV = 255;  
  //  int iLowH = 75;  
  //int iHighH = 130;  
  //
  //int iLowS = 0;   
  //int iHighS = 255;  
  //
  //int iLowV = 0;  
  //int iHighV = 142; 

  ////Create trackbars in "Control" window  
  cvCreateTrackbar("�ع�ֵ��", "Control", &exposure, 20); //Hue (0 - 179)  

  cvCreateTrackbar("LowH", "Control", &GLowH, 179); //Hue (0 - 179)  
  cvCreateTrackbar("HighH", "Control",&GHighH, 179);  
  
  cvCreateTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)  
  cvCreateTrackbar("HighS", "Control", &iHighS, 255);  
  
  cvCreateTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)  
  cvCreateTrackbar("HighV", "Control", &iHighV, 255);  

  /*try
	{   */                                     
    while (true)  //haimeidakai
    {  
		
		dbg("1");
		cap.set(CV_CAP_PROP_EXPOSURE,exposure);

        bool bSuccess = cap.read(imgOriginal); // read a new frame from video  
		remap(imgOriginal, imgOriginal, map1, map2, INTER_LINEAR);
		flip(imgOriginal, imgOriginal, 1); // flip by x axis  
		brightnessException (imgOriginal,cast, da);
		/*if(da>=64)
		{
			exposure++;
		}else if(da<=1)
		{
			exposure--;
		}*/
         if (!bSuccess) //if not success, break loop  
        {  
             cout << "Cannot read a frame from video stream" << endl;  
             break;  
        }  
   	 dbg("2");
   Mat imgHSV;  
   vector<Mat> hsvSplit;  
   cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV  
   //hsvSplit.resize(3);
   //��Ϊ���Ƕ�ȡ���ǲ�ɫͼ��ֱ��ͼ���⻯��Ҫ��HSV�ռ���  
   split(imgHSV, hsvSplit);  
 /*  imshow("hsvSplit[2]ǰ", hsvSplit[2]);*/
   equalizeHist(hsvSplit[2],hsvSplit[2]);  //ֱ��ͼ���⻯���ú����ܹ�һ��ͼ�����Ⱥ���ǿ�Աȶ�
    //imshow("hsvSplit[2]��", hsvSplit[2]);
   merge(hsvSplit,imgHSV);  
   	dbg("3");
   Mat imgThresholded;  
   //��ȡ��Ƶ���Ϣ
   inRange(imgHSV, Scalar(RLowH, iLowS, iLowV), Scalar(RHighH, iHighS, iHighV), imgThresholded); //Threshold the image  
   //������ (ȥ��һЩ���)  
   Mat element = getStructuringElement(MORPH_RECT, Size(2, 2));  
   morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);  
   //�ղ��� (����һЩ��ͨ��)  
   Mat elementB = getStructuringElement(MORPH_RECT, Size(5, 5));  
   morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, elementB);  
   Mat imgBinary;
   Point redPoint;//���
   dbg("4");
   threshold(imgThresholded, imgBinary, 128, 1, THRESH_BINARY);//  ��ֵ��
   dbg("5");
    bwLabel(imgBinary,imgBinary);
	dbg("6");
	redPoint=centerOfGravity(imgBinary,redPoint.x,redPoint.y);
	dbg("7");
	 imshow("RImage", imgThresholded); //show the thresholded image  
	
	//��ȡ�̵Ƶ���Ϣ
   inRange(imgHSV, Scalar(GLowH, iLowS, iLowV), Scalar(GHighH, iHighS, iHighV), imgThresholded); //Threshold the image  
   //������ (ȥ��һЩ���)  
   morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);  
   //�ղ��� (����һЩ��ͨ��)  
   morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, elementB);  
   Point greenPoint;//�̵�
   dbg("8");
   threshold(imgThresholded, imgBinary, 128, 1, THRESH_BINARY);//  ��ֵ��
    bwLabel(imgBinary,imgBinary);
	greenPoint=centerOfGravity(imgBinary,greenPoint.x,greenPoint.y);
	
	cout<<coordinate(redPoint,greenPoint,centrePoint,SensorSize,realH)<<endl;
	
	imshow("GImage", imgThresholded); //show the thresholded image  
	
	//printf("%d,%d      %d,%d\r\n",redPoint.x,redPoint.y,greenPoint.x,greenPoint.y);
    
   imshow("Original", imgOriginal); //show the original image  

  waitKey(1);

    }  
	/*}catch(...){}*/
   return 0;  
  
}  
/////////////////////////////////////////////////////////////////
//��������߶εľ���,ע�����ƽ��������߶�ƽ��ƽ��
//���õ�����Ҫ��ʽf/d=h/H
/////////////////////////////////////////////////////////////////
int  coordinate(Point First,Point Second,Point centre,Point2d Sensor_Size,int H)
{
	//����������ᵽ�������ߵĴ���ľ��루ʵ�ʳߴ磩
	double h=0;//hΪ����ľ���
		//���������
	int  Distance_To_Centre = 0;//����ֵ
	Point retVal;  
    double dx = abs(First.x - Second.x);  
    double dy = abs(First.y - Second.y);  

		 double u = (centre.x - First.x)*(First.x - Second.x) +  
        (centre.y - First.y)*(First.y - Second.y);  
    u = u/((dx*dx)+(dy*dy));  
  
    retVal.x = abs(First.x + u*dx);  
    retVal.y = abs(First.y + u*dy);  
  
	double centreToretVal=0;//���ᵽ������ͼ���ϵľ���
	centreToretVal=sqrt((centre.x-retVal.x)*Sensor_Size.x/width*(centre.x-retVal.x)*Sensor_Size.x/width+\
		(centre.y-retVal.y)*Sensor_Size.y/height*(centre.y-retVal.y)*Sensor_Size.y/height);

	int d=0;//���߶�����ƽ��ľ���
	h=sqrt((First.x-Second.x)*Sensor_Size.x/width*(First.x-Second.x)*Sensor_Size.x/width+\
		(First.y-Second.y)*Sensor_Size.y/height*(First.y-Second.y)*Sensor_Size.y/height);
	d=focalLength*H/h;

	double arctan=0;//���������������б�Ƕ�
	arctan=atan((centreToretVal/focalLength));
	
	
	if(acos(arctan)!=0)
	Distance_To_Centre=d/cos(arctan);//������б�Ƕ����ʵ�ʾ���


	return Distance_To_Centre;
}

//////////////////////////////////////////
//�궨ͼ�������
///////////////////////////////////////////
void bwLabel(const Mat& imgBw, Mat & imgOut)
{
    // ��ͼ����Χ����һ��
     Mat imgClone = Mat(imgBw.rows + 1, imgBw.cols + 1, imgBw.type(), Scalar(0));
     imgBw.copyTo(imgClone(Rect(1, 1, imgBw.cols, imgBw.rows)));
	 Mat imgLabeled;
     imgLabeled.create(imgClone.size(), imgClone.type());
     imgLabeled.setTo(Scalar::all(0));
      vector<vector<Point>> contours;
     vector<Vec4i> hierarchy;
     findContours(imgClone, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_NONE);
 
     vector<int> contoursLabel(contours.size(), 0);
     int numlab = 1;
     // �����Χ����
     for (vector<vector<Point>>::size_type i = 0; i < contours.size(); i++)
     {
         if (hierarchy[i][3] >= 0) // �и�����
         {
             continue;
         }
         for (vector<Point>::size_type k = 0; k != contours[i].size(); k++)
        {
             imgLabeled.at<uchar>(contours[i][k].y, contours[i][k].x) = numlab;
         }
        contoursLabel[i] = numlab++;
     }
     // ���������
     for (vector<vector<Point>>::size_type i = 0; i < contours.size(); i++)    
	 {
         if (hierarchy[i][3] < 0)
         {
             continue;
         }
         for (vector<Point>::size_type k = 0; k != contours[i].size(); k++)
         {
             imgLabeled.at<uchar>(contours[i][k].y, contours[i][k].x) = contoursLabel[hierarchy[i][3]];
         }
     }
	
		 // ���������صı��
		for (int i = 0; i < imgLabeled.rows; i++)
		 {
			 for (int j = 0; j < imgLabeled.cols; j++)
			 {
				 if (imgClone.at<uchar>(i, j) != 0 && imgLabeled.at<uchar>(i, j) == 0)
				 {
					 imgLabeled.at<uchar>(i, j) = imgLabeled.at<uchar>(i, j - 1);
				}
			}
		 }
		 imgOut = imgLabeled(Rect(1, 1, imgBw.cols, imgBw.rows)).clone(); // ���߽�ü���1����
		 contours.clear();

 }

////////////////////////////////
//��������������
////////////////////////////////
Point centerOfGravity(Mat& input,int &x,int &y)
{

      int height = input.rows; //����
      int width = input.cols ; //����
	  int k=0;  //ģ������
	  int maxNumOfmodual=0;  //�������ģ����
	  int num[5000][2];  //��0λ��¼�������������ڶ�λ��¼���Ǳ��
	  Point COG;//����
	  for(int i=0;i<50;i++)
	  {
		num[i][0]=0;
		num[i][1]=i;
	  }  
	  
      if (input.isContinuous())  
      {
		 uchar* dta=(uchar*)input.data;
          //��ģ������������� num������
		  for (int i = 0;i < height;i++)  
			{ 
				  for (int j = 0;j < width;j++)  
				 {
					 num[dta[i * width + j]][0]++;
				 } //���д������                    
			}
		num[0][0]=1;
		   //�ҵ�num�������������ı��num[0](���������ģ��)
		    while(num[k][0]!=0)
		  { k++; }
			k-=1;
		  for(int i=k;i!=0;i--)
		  {
			 if(num[i][0]>num[i-1][0])
			 {
				 num[i-1][0]=num[i][0];
				 num[i-1][1]=num[i][1];
				 maxNumOfmodual=num[i-1][1];
			 }
              
		  }
		    //������ģ�������
		  int x=0,y=0,n=0;
		  
		   for (int i = 2;i < height - 2;i++)  
			{ 
				  for (int j = 2;j < width - 2;j++)  
				 {
					 if(dta[i * width + j]==maxNumOfmodual)
					 {
						 dta[i * width + j]=50;
						x+=j;
						y+=i;
						n++;
					 }
				 }                    
			}
		   if(n!=0)
		   {
			 x/=n;
			 y/=n;
		   }
		   //printf("%d   %d\r\n",x,y);
		   //cout<<x<<","<<y<<endl;
		   
		   COG.x=x;
		   COG.y=y;
	
       }  

	  return COG;

}

 void brightnessException (Mat InputImg,float& cast,float& da) 
{ 
    Mat GRAYimg; 
    cvtColor(InputImg,GRAYimg,CV_BGR2GRAY); 
    float a=0; 
    int Hist[256]; 
    for(int i=0;i<256;i++) 
    Hist[i]=0; 
	try
	{
		  if (GRAYimg.isContinuous())  
		  {
			  uchar* dta=(uchar*)GRAYimg.data;
			   for (int i = 2;i < height - 2;i++)  
				{ 
					  for (int j = 2;j < width - 2;j++)  
						 {
				            a+=(dta[i*width+j]);
							int x=dta[i*width+j]; 
							Hist[x]++; 
						 } //���д������                    
				}
		   }   
	}
	catch(...){
		printf("�쳣");
				}
    
    da=a/float(GRAYimg.rows*GRAYimg.cols); //��+-�ŵ�ƽ��ֵ
    //float D =abs(da);   //��+-�ŵ�ƽ��ֵ
    //float Ma=0; 
    //for(int i=0;i<256;i++) 
    //{ 
    //    Ma+=abs(i-128-da)*Hist[i]; 
    //} 
    //Ma/=float((GRAYimg.rows*GRAYimg.cols)); 
    //float M=abs(Ma); 
    //float K=D/M; 
    //cast = K;
  //printf("����ָ���� %f\n",da);
    /*if(cast>1)
    {
	   printf("���ȣ�");
	   if(da>0)
	   printf("����\n");
	   else
	   printf("����\n");
	 }
	else
	 printf("���ȣ�����\n");*/
    return; 
}

//Point  centerOfMass(Mat& inputImage) 
//{
//	int weight=inputImage.cols;
//	int height=inputImage.rows;
//	
//}
