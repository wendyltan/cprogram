#include"stdafx.h"
#include <complex>
#include<math.h>

using namespace std;

#define PI 3.1415926535

BITMAPINFO *lpBitsInfo = NULL;

DWORD H[256];

static LONG size=0;

BITMAPINFO* lpDIB_FFT = NULL;  //Ƶ��ͼ��
BITMAPINFO* lpDIB_IFFT = NULL;
complex<double>* gFD; 

//----------------------------------------����λͼ���ݺ���ʾRGBֵ----------------------------------------------/
BOOL LoadBmpFile(char* BmpFileName)
{
	FILE* fp;
	if(NULL == (fp = fopen(BmpFileName,"rb")))
		return FALSE;


	BITMAPFILEHEADER bf;
	BITMAPINFOHEADER bi;
	

	fread(&bf,sizeof(BITMAPFILEHEADER),1,fp);
	fread(&bi,sizeof(BITMAPINFOHEADER),1,fp);

	DWORD NumColors;
	if(bi.biClrUsed!=0)
	{
		NumColors = bi.biClrUsed;
	}
	else
	{
		switch(bi.biBitCount){
			case 1:
				NumColors = 2;
				break;
			case 4:
				NumColors = 16;
				break;
			case 8:
				NumColors = 256;
				break;
			case 24:
				NumColors = 0;
				break;	
		
		}
	}
	


	DWORD LineBytes = (bi.biWidth*bi.biBitCount+31)/32*4;
	size = 40 + 4 * NumColors + LineBytes * bi.biHeight;

	if(NULL==(lpBitsInfo = (BITMAPINFO *)malloc(size)))
		return FALSE;

	fseek(fp , 14, SEEK_SET);
	fread((char*)lpBitsInfo,size,1,fp);
	
	

	lpBitsInfo->bmiHeader.biClrUsed = NumColors;
	

	fclose(fp);



	return TRUE;
}


void pixel(int i,int j)
{

	
	int w = lpBitsInfo->bmiHeader.biWidth;
	int h = lpBitsInfo->bmiHeader.biHeight;
	if(i>h||j>w)
		return;
	int LineBytes = (w * lpBitsInfo->bmiHeader.biBitCount + 31)/32 * 4;

	BYTE* lpBits = (BYTE*)&lpBitsInfo->bmiColors[lpBitsInfo->bmiHeader.biClrUsed];

	BYTE *pixel;
	char str[256];
	int r,g,b;
	switch(lpBitsInfo->bmiHeader.biBitCount)
	{
		case 8:
			{
				pixel = lpBits + LineBytes * (h - 1 - i) + j;
				r = lpBitsInfo->bmiColors[*pixel].rgbRed;
				g = lpBitsInfo->bmiColors[*pixel].rgbGreen;
				b = lpBitsInfo->bmiColors[*pixel].rgbBlue;

				sprintf(str,"RGB(%d,%d,%d)",r,g,b);

				break;
			}
		
		case 24:
			{
				pixel = lpBits + LineBytes * (h - 1 - i) + j*3;
				b = *pixel;
				g = *(pixel+1);
				r = *(pixel+2);

				sprintf(str,"RGB(%d,%d,%d)",r,g,b);
				break;
			}
		
		case 1:
			{
			
				pixel = lpBits + LineBytes * (h - 1 - i) + j/8;
				BYTE bv = (1<<(7-j%8))&(*pixel);

				if(0==bv)
					strcpy(str,"����ɫ");
				else
					strcpy(str,"ǰ��ɫ");
				break;
			}
		
		case 4:
			{
				pixel = lpBits + LineBytes * (h - 1 - i) + j/2;

				if(0 == j%2)
					*pixel = *pixel >>4;
				else
					*pixel = *pixel&15;

				r = lpBitsInfo->bmiColors[*pixel].rgbRed;
				g = lpBitsInfo->bmiColors[*pixel].rgbGreen;
				b = lpBitsInfo->bmiColors[*pixel].rgbBlue;

				sprintf(str,"RGB(%d,%d,%d)",r,g,b);
				break;

			
			}
				

	}
	AfxMessageBox(str);

}
//----------------------------------------�Ҷȱ任�ͻҶ�ֱ��ͼ----------------------------------------------/
void Gray()
{

	int w=lpBitsInfo->bmiHeader.biWidth;
	int h=lpBitsInfo->bmiHeader.biHeight;
	int LineBytes=
		(w*lpBitsInfo->bmiHeader.biBitCount+31)/32*4;
	BYTE* lpBits=
		(BYTE*)&lpBitsInfo->bmiColors[lpBitsInfo->bmiHeader.biClrUsed];

	int new_LineBytes=(w*8+31)/32*4;
	LONG size=40+1024+new_LineBytes*h;

	LPBITMAPINFO new_lpBitsInfo =(LPBITMAPINFO)malloc(size);

	memcpy(new_lpBitsInfo,lpBitsInfo,40);
	new_lpBitsInfo->bmiHeader.biBitCount=8;
    new_lpBitsInfo->bmiHeader.biClrUsed=256;

	int i,j;
	for(i=0;i<256;i++)
	{
     new_lpBitsInfo->bmiColors[i].rgbRed=i;
	 new_lpBitsInfo->bmiColors[i].rgbGreen=i;
	 new_lpBitsInfo->bmiColors[i].rgbBlue=i;
	 new_lpBitsInfo->bmiColors[i].rgbReserved=i;
	}
	

	BYTE* new_lpBits=(BYTE*)&new_lpBitsInfo->bmiColors[new_lpBitsInfo->bmiHeader.biClrUsed];

	BYTE *R,*G,*B,avg;

	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			//ָ�������㣨i��j��ָ��
          B=lpBits+LineBytes*(h-1-i)+j*3;
		  G=B+1;
		  R=B+2;
		  avg=(*R+*G+*B)/3;
          *R=*G=*B=avg;
		}
	}

}

void Histogram()
{
	int w=lpBitsInfo->bmiHeader.biWidth;
	int h=lpBitsInfo->bmiHeader.biHeight;
	int LineBytes=(w*lpBitsInfo->bmiHeader.biBitCount+31)/32*4;
	BYTE* lpBits=(BYTE*)&lpBitsInfo->bmiColors[lpBitsInfo->bmiHeader.biClrUsed];

	int i,j;
	BYTE *pixel;

	for(i=0;i<256;i++)
	{
		H[i] = 0;
	}

	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			pixel = lpBits + LineBytes *(h-1-i) +j;
			H[*pixel] ++;

		}
	}

}

//----------------------------------------���Ե�����----------------------------------------------/
void LinerTrans(float a,float b)
{
	int w=lpBitsInfo->bmiHeader.biWidth;
	int h=lpBitsInfo->bmiHeader.biHeight;
	int LineBytes=(w*lpBitsInfo->bmiHeader.biBitCount+31)/32*4;
	BYTE* lpBits=(BYTE*)&lpBitsInfo->bmiColors[lpBitsInfo->bmiHeader.biClrUsed];

	int i,j;
	BYTE *pixel;
	float temp;

	for(i = 0; i<h; i++)
	{

		for(j = 0;j <w;j++)
		{
			pixel = lpBits + LineBytes *(h-1-i) +j;
			temp = a * (*pixel)+b;

			if(temp>255)
			{
				*pixel = 255;
			}
			else if(temp <0)
			{
				*pixel = 0;
			}
			else
			{
				*pixel = (BYTE)	(temp + 0.5);	
			}
			
		}
	}
}

//----------------------------------------���⻯----------------------------------------------/
void Equalize()
{
	int i,j,temp;
	int w=lpBitsInfo->bmiHeader.biWidth;
	int h=lpBitsInfo->bmiHeader.biHeight;
	int LineBytes=(w*lpBitsInfo->bmiHeader.biBitCount+31)/32*4;
	BYTE* lpBits=(BYTE*)&lpBitsInfo->bmiColors[lpBitsInfo->bmiHeader.biClrUsed];


	BYTE Map[256];
	BYTE *pixel;

	Histogram();

	for(i=0;i<256;i++)
	{
		temp = 0;
		for(j=0;j<=i;j++)
		{
			temp += H[j];
		}

		Map[i] = (BYTE)(temp*255/w/h);

	}

	for(i = 0;i < h;i++)
	{
		for(j = 0;j<w;j++)
		{
			pixel = lpBits + LineBytes *(h-1-i) +j;

			*pixel = Map[*pixel];
		}
	}
}


//----------------------------------------����Ҷ�任----------------------------------------------/
void FT(complex<double> * TD, complex<double> * FD, int m)
{
	int u, x;
	double angle;
	for (u = 0; u < m; u ++)
	{
		FD[u] = 0;
		for (x = 0; x < m; x ++)
		{
			angle = -2 * PI * u * x / m;
			FD[u] += TD[x] * complex<double> (cos(angle), sin(angle)); 
		}
		FD[u] /= m;
	}
}
//����Ҷ���任����
void IFT(complex<double> * FD, complex<double> * TD, int m)
{
	int u, x;
	double angle;
	for (x = 0; x < m; x ++)
	{
		TD[x] = 0;
		for (u = 0; u < m; u ++)
		{
			angle = 2 * PI * u * x / m;
			TD[x] += FD[u] * complex<double> (cos(angle), sin(angle)); 
		}

	}
}
//ͼ����и���Ҷ�任
void Fourier()
{
	int w = lpBitsInfo->bmiHeader.biWidth;
	int h = lpBitsInfo->bmiHeader.biHeight;
	int LineBytes = (w * lpBitsInfo->bmiHeader.biBitCount + 31)/32 * 4;
	BYTE* lpBits = (BYTE*)&lpBitsInfo->bmiColors[lpBitsInfo->bmiHeader.biClrUsed];
	// �����ڴ�
	complex<double>* TD = new complex<double>[w * h];
	complex<double>* FD = new complex<double>[w * h];
	
	// ��ʱ��ֵ
	int i, j;
	BYTE* pixel;

	for (i = 0; i < h; i ++)
	{
		for(j = 0; j < w; j ++)
		{
			pixel = lpBits + LineBytes * (h - 1 - i) + j;
			TD[j + w * i] = complex<double>(*pixel * pow(-1, i + j), 0);
		}
	}
	
	//��ͼ����ÿ��������һ��w��ͼ���ȣ����1D_FFT�任
	for (i = 0; i < h; i ++)
	{
		FT(&TD[w * i], &FD[w * i], w);
	}
	
	//����TD�����м�任�������FDת�ú󸳸�TD
	for (i = 0; i < h; i ++)
	{
		for (j = 0; j < w; j ++)
		{
			TD[i + h * j] = FD[j + w * i];
		}
	}
	
	//��Ϊǰ��TD���м���FD��ת�ã����Դ˴��൱�ڶ�ͼ����ÿ��������һ��h��ͼ��߶ȣ����1DFT�任
	for (i = 0; i < w; i ++)
	{
		FT(&TD[i * h], &FD[i * h], h);
	}//ע�⣬��ʱFDΪͼ���ת��

	//����Ƶ��ͼ��
	//ΪƵ��ͼ������ڴ�
	BITMAPINFO* lpDIB_FT = (LPBITMAPINFO) malloc(size);
	if (NULL == lpDIB_FT)
		return;
	memcpy(lpDIB_FT, lpBitsInfo, size);

	//ָ��Ƶ��ͼ������ָ��
	lpBits = (BYTE*)&lpDIB_FT->bmiColors[lpDIB_FT->bmiHeader.biClrUsed];

	double temp;
	for (i = 0; i < h; i ++)
	{
		for (j = 0; j < w; j ++)
		{
			pixel = lpBits + LineBytes * (h - 1 - i) + j;

			//����Ƶ�׷���.ע���±��д����ת�û���
			temp = sqrt(FD[j * h + i].real() * FD[j * h + i].real() + 
				        FD[j * h + i].imag() * FD[j * h + i].imag()) * 2000;
			
			if (temp > 255)
				temp = 255;
			*pixel = (BYTE)(temp);
		}
	}
	
	// ɾ����ʱ����
	delete TD;
	gFD = FD;

	//�ͷ�ԭͼ��
	free(lpBitsInfo);
	
	//����Ϊ��ͼ��
	lpBitsInfo = lpDIB_FT;
}
//---------------------------------------����Ҷ���任--------------------------------------/
void IFourier()
{
	int w = lpBitsInfo->bmiHeader.biWidth;
	int h = lpBitsInfo->bmiHeader.biHeight;
	
	int LineBytes = (w * lpBitsInfo->bmiHeader.biBitCount + 31)/32 * 4;
	BYTE* lpBits = (BYTE*)&lpBitsInfo->bmiColors[lpBitsInfo->bmiHeader.biClrUsed];
	
	//�����ڴ�
	complex<double>* TD = new complex<double>[w * h];
	complex<double>* FD = new complex<double>[w * h];

	int i, j;

	//��gFD��ת�ø���FD��ע��gFDΪͼ���ת�ã�ת�ú�FD�ָ�����
	for (i = 0; i < h; i ++)
	{
		for (j = 0; j < w; j ++)
		{
			FD[w * i + j] = gFD[i + h * j];
		}
	}

	//��FD��ÿ��������һ��w��ͼ���ȣ����1DIFT�任��
	for (i = 0; i < h; i ++)
	{
		IFT(&FD[w * i], &TD[w * i], w);
	}
	
	//����FD�����м�任�������TDת�ú󸳸�FD��
	for (i = 0; i < h; i ++)
	{
		for (j = 0; j < w; j ++)
		{
			FD[i + h * j] = TD[j + w * i];
		}
	}

	//��Ϊǰ��FD���м���TD��ת�ã����Դ˴��൱��FD��ÿ��������һ��h��ͼ��߶ȣ����1DIFT�任
	for (i = 0; i < w; i ++)
	{
		IFT(&FD[i * h], &TD[i * h], h);
	}
	
	//Ϊͼ������ڴ�
	BITMAPINFO* lpDIB_FT = (LPBITMAPINFO) malloc(size);
	if (NULL == lpDIB_FT)
		return;
	memcpy(lpDIB_FT, lpBitsInfo, size);
	
	//ָ��Ƶ��ͼ������ָ��
	lpBits = (BYTE*)&lpDIB_FT->bmiColors[lpDIB_FT->bmiHeader.biClrUsed];

	BYTE* pixel;
	for (i = 0; i < h; i ++)
	{
		for (j = 0; j < w; j ++)
		{
			pixel = lpBits + LineBytes * (h - 1 - i) + j;
			*pixel = (BYTE)(TD[j * h + i].real() / pow(-1, i + j));
		}
	}
	
	// ɾ����ʱ����
	delete FD;
	delete gFD;
	delete TD;
	
	//�ͷ�ԭͼ��
	free(lpBitsInfo);
	
	//����Ϊ��ͼ��
	lpBitsInfo = lpDIB_FT;
}
//------------------------------------------���ٸ���Ҷ�任----------------------------------------/
//һά����Ҷ�任����
void FFT(complex<double> * TD, complex<double> * FD, int r)
{
	// ���㸶��Ҷ�任����
	LONG count = 1 << r;
	// �����Ȩϵ��
	int i;
	double angle;
	complex<double>* W = new complex<double>[count / 2];
	for(i = 0; i < count / 2; i++)
	{
		angle = -i * PI * 2 / count;
		W[i] = complex<double> (cos(angle), sin(angle));
	}
	// ��ʱ���д��X1
	complex<double>* X1 = new complex<double>[count];
	memcpy(X1, TD, sizeof(complex<double>) * count);
	
	// ���õ����㷨���п��ٸ���Ҷ�任�����ΪƵ��ֵX2
	complex<double>* X2 = new complex<double>[count]; 

	int k,j,p,size;
	complex<double>* temp;
	for (k = 0; k < r; k++)
	{
		for (j = 0; j < 1 << k; j++)
		{
			size = 1 << (r-k);
			for (i = 0; i < size/2; i++)
			{
				p = j * size;
				X2[i + p] = X1[i + p] + X1[i + p + size/2];
				X2[i + p + size/2] = (X1[i + p] - X1[i + p + size/2]) * W[i * (1<<k)];
			}
		}
		temp  = X1;
		X1 = X2;
		X2 = temp;
	}
	
	// ����������λ�������У�
	for (j = 0; j < count; j++)
	{
		p = 0;
		for (i = 0; i < r; i++)
		{
			if (j & (1<<i))
			{
				p += 1<<(r-i-1);
			}
		}
		FD[j]=X1[p];
		FD[j] /= count;
	}
	
	// �ͷ��ڴ�
	delete W;
	delete X1;
	delete X2;
}




int FFT_w;
int FFT_h;
int wp;
int hp;
//------------------------------------------���ٸ���Ҷ�任----------------------------------------/
void FastFourier()
{
	int width = lpBitsInfo->bmiHeader.biWidth;
	int height = lpBitsInfo->bmiHeader.biHeight;
	int LineBytes = (width * lpBitsInfo->bmiHeader.biBitCount + 31)/32 * 4;
	//ָ��ͼ������ָ��
	BYTE* lpBits = (BYTE*)&lpBitsInfo->bmiColors[lpBitsInfo->bmiHeader.biClrUsed];

	// FFT��ȣ�����Ϊ2�������η���
	int FFT_w = 1;
	// FFT��ȵ�����������������
	int wp = 0;
	while(FFT_w * 2 <= width)
	{
		FFT_w *= 2;
		wp ++;
	}

	// FFT�߶ȣ�����Ϊ2�������η���
	int FFT_h = 1;
	// FFT�߶ȵ�����������������
	int hp = 0;
	while(FFT_h * 2 <= height)
	{
		FFT_h *= 2;
		hp ++;
	}

	// �����ڴ�
	complex<double>* TD = new complex<double>[FFT_w * FFT_h];
	complex<double>* FD = new complex<double>[FFT_w * FFT_h];
	
	int i, j;
	BYTE* pixel;
	
	for(i = 0; i < FFT_h; i++)  // ��
	{
		for(j = 0; j < FFT_w; j++)  // ��
		{
			// ָ��DIB��i�У���j�����ص�ָ��
			pixel = lpBits + LineBytes * (height - 1 - i) + j;

			// ��ʱ��ֵ
			TD[j + FFT_w * i] = complex<double>(*pixel* pow(-1,i+j), 0);
		}
	}
	
	for(i = 0; i < FFT_h; i++)
	{
		// ��y������п��ٸ���Ҷ�任
		FFT(&TD[FFT_w * i], &FD[FFT_w * i], wp);
	}
	
	// �����м�任���
	for(i = 0; i < FFT_h; i++)
	{
		for(j = 0; j < FFT_w; j++)
		{
			TD[i + FFT_h * j] = FD[j + FFT_w * i];
		}
	}
	
	for(i = 0; i < FFT_w; i++)
	{
		// ��x������п��ٸ���Ҷ�任
		FFT(&TD[i * FFT_h], &FD[i * FFT_h], hp);
	}

	// ɾ����ʱ����
	delete TD;

	//����Ƶ��ͼ��
	//ΪƵ��ͼ������ڴ�
	LONG size = 40 + 1024 + LineBytes * height;
	lpDIB_FFT = (LPBITMAPINFO) malloc(size);
	if (NULL == lpDIB_FFT)
		return;
	memcpy(lpDIB_FFT, lpBitsInfo, size);

	//ָ��Ƶ��ͼ������ָ��
	lpBits = (BYTE*)&lpDIB_FFT->bmiColors[lpDIB_FFT->bmiHeader.biClrUsed];

	double temp;
	for(i = 0; i < FFT_h; i++) // ��
	{
		for(j = 0; j < FFT_w; j++) // ��
		{
			// ����Ƶ�׷���
			temp = sqrt(FD[j * FFT_h + i].real() * FD[j * FFT_h + i].real() + 
				        FD[j * FFT_h + i].imag() * FD[j * FFT_h + i].imag()) *2000;
			
			// �ж��Ƿ񳬹�255
			if (temp > 255)
			{
				// ���ڳ����ģ�ֱ������Ϊ255
				temp = 255;
			}
			
			pixel = lpBits + LineBytes * (height - 1 - i) + j;

			// ����Դͼ��
			*pixel = (BYTE)(temp);
		}
	}

	gFD=FD;

}

//------------------------------------------���ٸ���Ҷ���任-----------------------------------/
void IFFT(complex<double> * FD, complex<double> * TD, int r)
{
	// ����Ҷ�任����
	LONG	count;
	// ���㸶��Ҷ�任����
	count = 1 << r;

	// ������������洢��
	complex<double> * X = new complex<double>[count];
	// ��Ƶ���д��X
	memcpy(X, FD, sizeof(complex<double>) * count);
	
	// ����
	for(int i = 0; i < count; i++)
		X[i] = complex<double> (X[i].real(), -X[i].imag());
	
	// ���ÿ��ٸ���Ҷ�任
	FFT(X, TD, r);
	
	// ��ʱ���Ĺ���
	for(i = 0; i < count; i++)
		TD[i] = complex<double> (TD[i].real() * count, -TD[i].imag() * count);
	
	// �ͷ��ڴ�
	delete X;
}

void IfastFourier()
{
	//ͼ��Ŀ�Ⱥ͸߶�
	int width = lpBitsInfo->bmiHeader.biWidth;
	int height = lpBitsInfo->bmiHeader.biHeight;
	int LineBytes = (width * lpBitsInfo->bmiHeader.biBitCount + 31)/32 * 4;

	// FFT��ȣ�����Ϊ2�������η���
	int FFT_w = 1;
	// FFT��ȵ�����������������
	int wp = 0;
	while(FFT_w * 2 <= width)
	{
		FFT_w *= 2;
		wp ++;
	}

	// FFT�߶ȣ�����Ϊ2�������η���
	int FFT_h = 1;
	// FFT�߶ȵ�����������������
	int hp = 0;
	while(FFT_h * 2 <= height)
	{
		FFT_h *= 2;
		hp ++;
	}

	// �����ڴ�
	complex<double>* TD = new complex<double>[FFT_w * FFT_h];
	complex<double>* FD = new complex<double>[FFT_w * FFT_h];
	
	int i, j;
	for(i = 0; i < FFT_h; i++)  // ��
		for(j = 0; j < FFT_w; j++)  // ��
			FD[j + FFT_w * i] = gFD[i + FFT_h*j];
	
	// ��ˮƽ������п��ٸ���Ҷ�任
	for(i = 0; i < FFT_h; i++)
		IFFT(&FD[FFT_w * i], &TD[FFT_w * i], wp);
	
	// �����м�任���
	for(i = 0; i < FFT_h; i++)
		for(j = 0; j < FFT_w; j++)
			FD[i + FFT_h * j] = TD[j + FFT_w * i];
	
	// �ش�ֱ������п��ٸ���Ҷ�任
	for(i = 0; i < FFT_w; i++)
		IFFT(&FD[i * FFT_h], &TD[i * FFT_h], hp);

	//Ϊ���任ͼ������ڴ�
	LONG size = 40 + 1024 + LineBytes * height;

	lpDIB_IFFT = (LPBITMAPINFO) malloc(size);
	if (NULL == lpDIB_IFFT)
		return;
	memcpy(lpDIB_IFFT, lpBitsInfo, size);

	//ָ�򷴱任ͼ������ָ��
	BYTE* lpBits = (BYTE*)&lpDIB_IFFT->bmiColors[lpDIB_IFFT->bmiHeader.biClrUsed];
	BYTE* pixel;
	double temp;
	for(i = 0; i < FFT_h; i++) // ��
	{
		for(j = 0; j < FFT_w; j++) // ��
		{
			pixel = lpBits + LineBytes * (height - 1 - i) + j;
			temp= (TD[j*FFT_h + i].real() / pow(-1, i+j));
			if (temp < 0)
				temp = 0;
			else if (temp >255)
				temp = 255;
			*pixel = (BYTE)temp;
		}
	}

	// ɾ����ʱ����
	delete FD;
	delete TD;
	//delete gFD;


}

//------------------------------------------�����˲�-----------------------------------/

void Template(int* Array, float coef)
{
	// ͼ��Ŀ�Ⱥ͸߶�
	int w = lpBitsInfo->bmiHeader.biWidth;
	int h = lpBitsInfo->bmiHeader.biHeight;

	// ÿ�е��ֽ�����������4�ı�����
	int LineBytes = (w * lpBitsInfo->bmiHeader.biBitCount + 31)/32 * 4;

	// ָ��ԭͼ�����ݵ�ָ��
	BYTE *lpBits = (BYTE*)&lpBitsInfo->bmiColors[lpBitsInfo->bmiHeader.biClrUsed];

	// Ϊ��ͼ������ڴ�
	BITMAPINFO* new_lpBitsInfo;
	LONG size = sizeof(BITMAPINFOHEADER) + 256 * sizeof(RGBQUAD) + h * LineBytes;
	if (NULL == (new_lpBitsInfo = (LPBITMAPINFO) malloc(size)))
		return;

	// ����BMP
	memcpy(new_lpBitsInfo, lpBitsInfo, size);
	// �ҵ���ͼ��������ʼλ��
	BYTE* lpNewBits = (BYTE*)&new_lpBitsInfo->bmiColors[new_lpBitsInfo->bmiHeader.biClrUsed];

	int i, j, k, l;
	BYTE *pixel, *new_pixel;
	float result;

	// ��(��ȥ��Ե����)
	for(i = 1; i < h - 1; i++)
	{
		// ��(��ȥ��Ե����)
		for(j = 1; j < w - 1; j++)
		{
			// ָ����ͼ��i�У���j�����ص�ָ��
			new_pixel = lpNewBits + LineBytes * (h - 1 - i) + j;
			result = 0;

			// ����3x3ģ�������ػҶ�ֵ�ĺ�
			for (k = 0; k < 3; k++)
			{
				for (l = 0; l < 3; l++)
				{
					// ָ��ԭͼ��ģ����ÿ�����ص�ĻҶ�ֵ����i - 1 + k�У���j - 1 + l�����ص�ָ��
					pixel = lpBits + LineBytes * (h - i - k) + j - 1 + l;
					
					// �Ҷ�ֵ����ģ��ϵ�����ۼ�
					result += (*pixel) * Array[k * 3 + l];
				}
			}

			// ����ϵ��
			result *= coef;
	//		result = (float)fabs(result);

			if (result < 0)
				*new_pixel = 0;
			else if(result > 255)
				*new_pixel = 255;
			else
				*new_pixel = (BYTE) (result + 0.5);
		}
	}

	free(lpBitsInfo);
	lpBitsInfo = new_lpBitsInfo;
}

void AverageFilter() 
{
	int Array[9]; //3x3ģ��

	//��׼��ֵ�˲�
	Array[0] = 1;
	Array[1] = 1;
	Array[2] = 1;
	Array[3] = 1;
	Array[4] = 1;
	Array[5] = 1;
	Array[6] = 1;
	Array[7] = 1;
	Array[8] = 1;

	Template(Array, (float)1/9);


}

BYTE WINAPI GetMedianNum(BYTE* Array)
{
	int i,j;
	
	BYTE temp;
	
	// ��ð�ݷ��������������
	for (j = 0; j < 9 - 1; j ++)
	{
		for (i = 0; i < 9 - j - 1; i ++)
		{
			if (Array[i] > Array[i + 1])
			{
				// ����
				temp = Array[i];
				Array[i] = Array[i + 1];
				Array[i + 1] = temp;
			}
		}
	}
	
	// ������ֵ
	return Array[4];
}

void MedianFilter() 
{
	// ͼ��Ŀ�Ⱥ͸߶�
	int w = lpBitsInfo->bmiHeader.biWidth;
	int h = lpBitsInfo->bmiHeader.biHeight;

	// ÿ�е��ֽ�����������4�ı�����
	int LineBytes = (w * lpBitsInfo->bmiHeader.biBitCount + 31)/32 * 4;

	// ָ��ԭͼ�����ݵ�ָ��
	BYTE *lpBits = (BYTE*)&lpBitsInfo->bmiColors[lpBitsInfo->bmiHeader.biClrUsed];

	// Ϊ��ͼ������ڴ�
	BITMAPINFO* new_lpBitsInfo;
	LONG size = sizeof(BITMAPINFOHEADER) + 256 * sizeof(RGBQUAD) + h * LineBytes;
	if (NULL == (new_lpBitsInfo = (LPBITMAPINFO) malloc(size)))
		return;

	// ����BMP
	memcpy(new_lpBitsInfo, lpBitsInfo, size);
	// �ҵ���ͼ��������ʼλ��
	BYTE* lpNewBits = (BYTE*)&new_lpBitsInfo->bmiColors[new_lpBitsInfo->bmiHeader.biClrUsed];

	int i, j, k, l;
	BYTE *pixel, *new_pixel;
	
	BYTE Value[9]; //3x3ģ��

	// ��(��ȥ��Ե����)
	for(i = 1; i < h - 1; i++)
	{
		// ��(��ȥ��Ե����)
		for(j = 1; j < w - 1; j++)
		{
			// ָ����ͼ��i�У���j�����ص�ָ��
			new_pixel = lpNewBits + LineBytes * (h - 1 - i) + j;

			// ���� 3x3ģ�������صĻҶ�ֵ
			for (k = 0; k < 3; k++)
			{
				for (l = 0; l < 3; l++)
				{
					// ָ��ԭͼ��i - 1 + k�У���j - 1 + l�����ص�ָ��
					pixel = lpBits + LineBytes * (h - i - k) + j - 1 + l;
					
					// ��������ֵ
					Value[k * 3 + l] = *pixel;
				}
			}

			// ��ȡ��ֵ
			*new_pixel = GetMedianNum(Value);
		}
	}

	free(lpBitsInfo);
	lpBitsInfo = new_lpBitsInfo;

}

//�ݶ���
void GradSharp() 
{
	// ͼ��Ŀ�Ⱥ͸߶�
	int w = lpBitsInfo->bmiHeader.biWidth;
	int h = lpBitsInfo->bmiHeader.biHeight;

	// ÿ�е��ֽ�����������4�ı�����
	int LineBytes = (w * lpBitsInfo->bmiHeader.biBitCount + 31)/32 * 4;

	// ָ��ԭͼ�����ݵ�ָ��
	BYTE *lpBits = (BYTE*)&lpBitsInfo->bmiColors[lpBitsInfo->bmiHeader.biClrUsed];

	// ָ��Դͼ���ָ��
	BYTE *lpSrc, *lpSrc1, *lpSrc2;
	
	int i, j;
	BYTE temp;
	
	// ÿ��
	for(i = 0; i < h-1; i++)
	{
		// ÿ��
		for(j = 0; j < w-1; j++)
		{
			// ָ��ͼ���i�У���j�����ص�ָ��
			lpSrc  = lpBits + LineBytes * (h - 1 - i) + j;
			
			// ָ��ͼ���i+1�У���j�����ص�ָ��
			lpSrc1 = lpBits + LineBytes * (h - 2 - i) + j;
			
			// ָ��ͼ���i�У���j+1�����ص�ָ��
			lpSrc2 = lpBits + LineBytes * (h - 1 - i) + j + 1;
			
			//�ݶ�����
			temp = abs((*lpSrc)-(*lpSrc1)) + abs((*lpSrc)-(*lpSrc2));
			
			if (temp > 255)
				*lpSrc = 255;
			else
				*lpSrc = temp;
		}
	}
}

//������˹��
void RaplasSharp() 
{
	int Array[9]; //3x3ģ��

	//������˹��
	Array[0] = -1;
	Array[1] = -1;
	Array[2] = -1;
	Array[3] = -1;
	Array[4] = 9;
	Array[5] = -1;
	Array[6] = -1;
	Array[7] = -1;
	Array[8] = -1;

	Template(Array, (float)1);
}

//-----------------------------------------------Ƶ���˲�------------------------------/
//����Ƶ���˲�����
void Ideal_Filter_FFT(int D)
{
	//ͼ��Ŀ�Ⱥ͸߶�
	int width = lpBitsInfo->bmiHeader.biWidth;
	int height = lpBitsInfo->bmiHeader.biHeight;
	int FFT_w = 1;
	while(FFT_w * 2 <= width)
		FFT_w *= 2;
	int FFT_h = 1;
	while(FFT_h * 2 <= height)
		FFT_h *= 2;

	//����ԭʼƵ������
	complex<double>* origin_FD = new complex<double>[FFT_w * FFT_h];
	for(int n = 0; n < FFT_w * FFT_h; n++)
		origin_FD[n] = gFD[n];

	//Ƶ���˲��������/��ͨ�˲���
	int i, j;
	double dis;
	for(i = 0; i < FFT_h; i++)
	{
		for(j = 0; j < FFT_w; j++)
		{
			dis = sqrt((i - FFT_h/2) * (i - FFT_h/2) + (j - FFT_w/2)  * (j - FFT_w/2) + 1);
			if (D > 0) //��ͨ
			{
				if (dis > D) 
					gFD[i * FFT_h + j] = 0; //�����ͨ���ضϸ�Ƶ
			}
			else { //��ͨ
				if (dis <= -D) 
					gFD[i * FFT_h + j] = 0; //�����ͨ���ضϵ�Ƶ
			}
		}
	}

	//�����µ�Ƶ��ͼ��
	int LineBytes = (width * lpBitsInfo->bmiHeader.biBitCount + 31)/32 * 4;
	LONG size = 40 + 1024 + LineBytes * height;
	BITMAPINFO* new_lpDIB_FFT = (LPBITMAPINFO) malloc(size);
	memcpy(new_lpDIB_FFT, lpDIB_FFT, size);
	BYTE* lpBits = (BYTE*)&new_lpDIB_FFT->bmiColors[new_lpDIB_FFT->bmiHeader.biClrUsed];
	double temp;
	BYTE* pixel;
	for(i = 0; i < FFT_h; i++)
	{
		for(j = 0; j < FFT_w; j++)
		{
			temp = sqrt(gFD[j * FFT_h + i].real() * gFD[j * FFT_h + i].real() + 
				        gFD[j * FFT_h + i].imag() * gFD[j * FFT_h + i].imag())*2000 ;
			if (temp > 255)
				temp = 255;
			pixel = lpBits + LineBytes * (height - 1 - i) + j;
			*pixel = (BYTE)(temp);
		}
	}
	//�ͷ�ԭƵ��ͼ��
	if (lpDIB_FFT)
		free(lpDIB_FFT);
	//�����µ�Ƶ��ͼ��
	lpDIB_FFT = new_lpDIB_FFT;

	//���ٸ���Ҷ���任
	IfastFourier();

	//�ָ���ԭʼƵ������
	delete gFD;
	gFD = origin_FD;
}
//������˹�˲�����
void Butterworth_Filter_FFT(int D)
{

	//ͼ��Ŀ�Ⱥ͸߶�
	int width = lpBitsInfo->bmiHeader.biWidth;
	int height = lpBitsInfo->bmiHeader.biHeight;
	int FFT_w = 1;
	while(FFT_w * 2 <= width)
		FFT_w *= 2;
	int FFT_h = 1;
	while(FFT_h * 2 <= height)
		FFT_h *= 2;

	//����ԭʼƵ������
	complex<double>* origin_FD = new complex<double>[FFT_w * FFT_h];
	for(int n = 0; n < FFT_w * FFT_h; n++)
		origin_FD[n] = gFD[n];

	//Ƶ���˲���������˹��/��ͨ�˲���
	int i, j;
	double dis;

	for(i = 0; i < FFT_h; i++)
	{
		for(j = 0; j < FFT_w; j++)
		{
			dis = sqrt((i - FFT_h/2) * (i - FFT_h/2) + (j - FFT_w/2)  * (j - FFT_w/2) + 1);
			
			if (D > 0) //������˹��ͨ�˲�
				gFD[i * FFT_h + j] *= 1/(1 + pow(dis/D, 2));
			else	   //������˹��ͨ�˲�
				gFD[i * FFT_h + j] *= 1/(1 + pow(D/dis, 2));
		}
	}

	//�����µ�Ƶ��ͼ��
	int LineBytes = (width * lpBitsInfo->bmiHeader.biBitCount + 31)/32 * 4;
	LONG size = 40 + 1024 + LineBytes * height;
	BITMAPINFO* new_lpDIB_FFT = (LPBITMAPINFO) malloc(size);
	memcpy(new_lpDIB_FFT, lpDIB_FFT, size);
	BYTE* lpBits = (BYTE*)&new_lpDIB_FFT->bmiColors[new_lpDIB_FFT->bmiHeader.biClrUsed];
	double temp;
	BYTE* pixel;
	for(i = 0; i < FFT_h; i++)
	{
		for(j = 0; j < FFT_w; j++)
		{
			temp = sqrt(gFD[j * FFT_h + i].real() * gFD[j * FFT_h + i].real() + 
				        gFD[j * FFT_h + i].imag() * gFD[j * FFT_h + i].imag())*2000 ;
			if (temp > 255)
				temp = 255;
			pixel = lpBits + LineBytes * (height - 1 - i) + j;
			*pixel = (BYTE)(temp);
		}
	}
	//�ͷ�ԭƵ��ͼ��
	if (lpDIB_FFT)
		free(lpDIB_FFT);
	//�����µ�Ƶ��ͼ��
	lpDIB_FFT = new_lpDIB_FFT;

	//���ٸ���Ҷ���任
	IfastFourier();

	//�ָ���ԭʼƵ������
	delete gFD;
	gFD = origin_FD;
}
