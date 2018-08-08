#pragma once
#include<stdio.h>
#include<stdlib.h>
#pragma pack(2)

typedef unsigned long DWORD;       //4字节
typedef unsigned short WORD;       //2字节
typedef unsigned char BYTE;        //1字节

typedef struct tagBITMAPFILEHEADER
{
	WORD bfType;              //位图文件类型，BMP
	DWORD bfSize;             //位图文件大小
	WORD bfReserved1;         //位图文件保留字，为0
	WORD bfReserved2;         //位图文件保留字，为0
	DWORD bfOffBits;          //位图数据起始位置，相对于文件头的偏移量，以字节为单位

}BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {

	DWORD biSize;             //本结构所占用字节数
	long   biWidth;           //位图宽度
	long   biHeight;          //位图高度
	WORD   biPlanes;          //目标设备的级别
	WORD   biBitCount;        //每个像素点的位数
	DWORD  biCompression;     //位图压缩类型
	DWORD  biSizeImage;       //位图的大小
	long   biXPelsPerMeter;   //位图水平分辨率
	long   biYPelsPerMeter;   //位图垂直分辨率
	DWORD biClrUsed;          //位图实际使用的颜色表中的颜色数
	DWORD biClrImportant;     //位图显示过程中重要的颜色数

} BITMAPINFOHEADER;

int ** pixel_Traversal(FILE*file, BITMAPFILEHEADER bmpfileheader, BITMAPINFOHEADER bmpinfoheader);     //返回像素矩阵