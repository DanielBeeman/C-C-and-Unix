#include <sink.h>
#include <PNMwriter.h>
#include <stdio.h>

void PNMwriter::Write(char *filename)
{
	FILE *f_out;
	f_out = fopen(filename, "w");
	fprintf(f_out, "%s\n%d %d\n%d\n","P6", img1->width, img1->height, img1->maxval);
	Pixel * pixel = img1->GetPix();
	fwrite(img1->pixel, sizeof(Pixel), img1->width*img1->height, f_out);
	fclose(f_out);
} 
