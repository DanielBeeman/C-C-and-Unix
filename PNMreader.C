#include <PNMreader.h>
#include <source.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <image.h>

//passing in the file in the constructor since execute does not take in any arguments.
PNMreader::PNMreader(char* f)
{
	filename = new char[strlen(f)+1];
	strcpy(filename, f);
}

//destructor
PNMreader::~PNMreader()
{
	delete []filename;
}

//to actually read the file, very similar to 3B.
void PNMreader::Execute()
{

	FILE *f_in;
	char magicNum[128];
	int width, height, maxval;
	f_in = fopen(filename, "r");
	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
 
	output.ResetSize(width, height);  
	int outW = output.GetWidth();
	int outH = output.GetHeight();
	int outM = output.GetMaxval();
	Pixel * outD = new Pixel[width * height];
	fread(outD, sizeof(Pixel), outW*outH, f_in);
	output.ResetPixel(outD);
	fclose(f_in);
	delete [] outD;

};

void PNMreader::Update()
{
	Execute();
}	
	
