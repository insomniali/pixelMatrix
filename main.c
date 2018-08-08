#include"image.h"

int main(void) {
	FILE *file = NULL;
	char filename[256];
	BITMAPFILEHEADER bmpfileheader;
	BITMAPINFOHEADER bmpinfoheader;
	int **pixelmatrix;
	int *column;


	printf("请输入文件名（bmp）:\n");
	gets(filename);
	file = fopen(filename, "rb+");
	if (file == NULL)
	{
		printf("\nerror opening %s for reading! ", filename);
	}

	fseek(file, 0L, 0);

	//位图文件头内容
	fread(&bmpfileheader, sizeof(BITMAPFILEHEADER), 1, file);
	printf("bmpfileheader.bfType:%d\n", bmpfileheader.bfType);
	printf("bmpfileheader.bfSize:%d\n",bmpfileheader.bfSize);
	printf("bmpfileheader.bfReserved1:%d\n", bmpfileheader.bfReserved1);
	printf("bmpfileheader.bfReserved2:%d\n", bmpfileheader.bfReserved2);
	printf("bmpfileheader.bfOffBits:%d\n", bmpfileheader.bfOffBits);


	
	//位图信息头内容
	fread(&bmpinfoheader, sizeof(BITMAPINFOHEADER), 1, file);
	printf("bmpinfoheader.bisize: %d\n", bmpinfoheader.biSize);
	printf("bmpinfoheader.biWidth: %ld\n", bmpinfoheader.biWidth);
	printf("bmpinfoheader.biHeight: %ld\n", bmpinfoheader.biHeight);
	printf("bmpinfoheader.biplans: %d\n", bmpinfoheader.biPlanes);
	printf("bmpinfoheader.biBitCount: %d\n", bmpinfoheader.biBitCount);
	printf("bmpinfoheader.biCompression: %d\n", bmpinfoheader.biCompression);
	printf("bmpinfoheader.biSizeImage: %d\n", bmpinfoheader.biSizeImage);
	printf("bmpinfoheader.biXPelsPerMeter: %d\n", bmpinfoheader.biXPelsPerMeter);
	printf("bmpinfoheader.biYPelsPerMeter: %d\n", bmpinfoheader.biYPelsPerMeter);
	printf("bmpinfoheader.biClrUsed: %d\n", bmpinfoheader.biClrUsed);
	printf("bmpinfoheader.biClrImportant: %d\n", bmpinfoheader.biClrImportant);

	
	column = (int *)malloc(sizeof(int)*bmpinfoheader.biHeight);
	pixelmatrix = (int **)malloc(sizeof(column)*bmpinfoheader.biWidth);

	pixelmatrix = pixel_Traversal(file, bmpfileheader, bmpinfoheader); 

	getchar();
	fclose(file);
	return 0;
}