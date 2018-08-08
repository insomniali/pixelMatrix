#include"image.h"

int ** pixel_Traversal(FILE*file, BITMAPFILEHEADER bmpfileheader, BITMAPINFOHEADER bmpinfoheader) {

	int **temp;
	int *column;
	int *ptrtemp;
	long pixeladd = bmpinfoheader.biBitCount / 8;                //一个像素所占字节
	BYTE * buffer=NULL;
	BYTE *ptr = NULL;
	BYTE *r = NULL ;
	BYTE *g = NULL;
	BYTE *b =NULL;
	long widthbyte;                                             //一行像素所占字节

	column = (int *)malloc(sizeof(int)*bmpinfoheader.biHeight); 
	ptrtemp = (int *)malloc(sizeof(int)*bmpinfoheader.biHeight);
	temp = (int **)malloc(sizeof(column)*bmpinfoheader.biWidth);
	widthbyte = pixeladd*bmpinfoheader.biWidth;
	r = (BYTE*)malloc(sizeof(BYTE));
	g = (BYTE*)malloc(sizeof(BYTE));
	b = (BYTE*)malloc(sizeof(BYTE));

	if ((widthbyte % 4) != 0)widthbyte += 4 - (widthbyte % 4);
	buffer = (BYTE*)malloc(sizeof(BYTE)* widthbyte * bmpinfoheader.biHeight);
	
	fseek(file, bmpfileheader.bfOffBits, 0);
	fread(buffer, widthbyte * bmpinfoheader.biHeight, 1, file);
	
	for (int i=0; i < bmpinfoheader.biWidth; ++i) {
		temp[i] = column;
		for (int j=0; j < bmpinfoheader.biHeight; ++j)
		{
			ptr=buffer + i * pixeladd + (bmpinfoheader.biHeight-1-j)* widthbyte;
			*b = *ptr;
			*g = *(ptr + 1);
			*r = *(ptr + 2);
			temp[i][j] = ((int)*b)*1000000+ ((int)*g)*1000+ ((int)*r);
		}
		ptrtemp = column;
		column = NULL;
		temp[i] = ptrtemp;
		free(column);
		column = (int *)malloc(sizeof(int)*bmpinfoheader.biHeight);  
	}

	return temp;
}