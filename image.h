#pragma once
#include<stdio.h>
#include<stdlib.h>
#pragma pack(2)

typedef unsigned long DWORD;       //4�ֽ�
typedef unsigned short WORD;       //2�ֽ�
typedef unsigned char BYTE;        //1�ֽ�

typedef struct tagBITMAPFILEHEADER
{
	WORD bfType;              //λͼ�ļ����ͣ�BMP
	DWORD bfSize;             //λͼ�ļ���С
	WORD bfReserved1;         //λͼ�ļ������֣�Ϊ0
	WORD bfReserved2;         //λͼ�ļ������֣�Ϊ0
	DWORD bfOffBits;          //λͼ������ʼλ�ã�������ļ�ͷ��ƫ���������ֽ�Ϊ��λ

}BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {

	DWORD biSize;             //���ṹ��ռ���ֽ���
	long   biWidth;           //λͼ���
	long   biHeight;          //λͼ�߶�
	WORD   biPlanes;          //Ŀ���豸�ļ���
	WORD   biBitCount;        //ÿ�����ص��λ��
	DWORD  biCompression;     //λͼѹ������
	DWORD  biSizeImage;       //λͼ�Ĵ�С
	long   biXPelsPerMeter;   //λͼˮƽ�ֱ���
	long   biYPelsPerMeter;   //λͼ��ֱ�ֱ���
	DWORD biClrUsed;          //λͼʵ��ʹ�õ���ɫ���е���ɫ��
	DWORD biClrImportant;     //λͼ��ʾ��������Ҫ����ɫ��

} BITMAPINFOHEADER;

int ** pixel_Traversal(FILE*file, BITMAPFILEHEADER bmpfileheader, BITMAPINFOHEADER bmpinfoheader);     //�������ؾ���