#include <filter.h>
#include <stdio.h>

//this sets the output from the 'previous' filter as the input for the 'next' input filter, for each respective filter.
Shrinker::Shrinker(){
	GetOutput()->SetSource(this);
}

//the new Update() function
void Filter::Update(){
	if (img1 !=NULL){
		img1->Update();

	}
	if (img2 !=NULL){
		img2->Update();

	}

	Execute();
}
//the filters we apply to the input image that we read, and write to the output image.

void Shrinker::Execute()
{
	Image *output =  GetOutput();
	output->ResetSize((this->img1->GetWidth()/2), (this->img1->GetHeight()/2));
	Pixel * inD = this->img1->GetPix();
	int outH = output->GetHeight();
	int outW = output->GetWidth();
	int inW = this->img1->GetWidth();
	Pixel *pixel = new Pixel[outW * outH];


	for (int i = 0; i < outH; i++) {
		for (int j = 0; j < outW; j++) {
			pixel[i * outW + j].r= inD[(i * 2) * inW+ (j * 2)].r;
			pixel[i * outW+ j].g= inD[(i * 2) * inW + (j * 2)].g;
			pixel[i * outW + j].b= inD[(i * 2) * inW + (j * 2)].b;

		}
	}
	output->ResetPixel(pixel);
	delete [] pixel;
}

LRCombine::LRCombine(){
	GetOutput()->SetSource(this);
}

void LRCombine::Execute()
{
	Image *output = GetOutput();
	output->ResetSize(this->img1->GetWidth() + this->img2->GetWidth(), img1->GetHeight());
	int outH = output->GetHeight();
	int outW = output->GetWidth();
	int inLW = this->img1->GetWidth();
	int inRW = this->img2->GetWidth();
	Pixel * inLD = this->img1->GetPix();
	Pixel * inRD = this->img2->GetPix();
	Pixel *pixel = new Pixel[outW * outH];

	for (int i = 0; i < outH; i++) {
		for (int j = 0; j < inLW; j++) {
			pixel[i * outW + j].r= inLD[i * inLW + j].r;
			pixel[i * outW + j].g= inLD[i * inLW + j].g;
			pixel[i * outW + j].b= inLD[i * inLW + j].b; 
		}
		for (int k = 0; k < inRW; k++) {
			pixel[i * outW + inLW + k].r= inRD[i * inRW + k].r;
			pixel[i * outW + inLW + k].g= inRD[i * inRW + k].g;
			pixel[i * outW + inLW + k].b= inRD[i * inRW + k].b; 
		}	
	}
	output->ResetPixel(pixel);
	delete [] pixel;
}

TBCombine::TBCombine(){
	GetOutput()->SetSource(this);
}


void TBCombine::Execute()
{
	Image *output = GetOutput();
	output->ResetSize(this->img1->GetWidth(), this->img1->GetHeight() + this->img2->GetHeight());
	int outH = output->GetHeight();	
	
	int outW = output->GetWidth();
	int inTW = img1->GetWidth();
	int inTH = img1->GetHeight();
	
	Pixel * inTD = img1->GetPix();
	Pixel * inBD = img2->GetPix();
	int dimens = inTW * inTH;
	Pixel *pixel = new Pixel[outW*outH];

	for (int i = 0; i < dimens; i++){
		pixel[i].r= inTD[i].r;
		pixel[i].g= inTD[i].g;
		pixel[i].b= inTD[i].b;
		}
	for (int j = 0; j < dimens; j++) {
		pixel[j + dimens].r = inBD[j].r;
		pixel[j + dimens].g = inBD[j].g;
		pixel[j + dimens].b = inBD[j].b;
	}

	output->ResetPixel(pixel);
	delete [] pixel;

}

Blender::Blender(){
	GetOutput()->SetSource(this);
}

void Blender::Execute()
{
	Image *output = GetOutput();
	output->ResetSize(this->img1->GetWidth(), this->img1->GetHeight());
	Pixel * outD = output->GetPix();
	Pixel * in1D = img1->GetPix();
	Pixel * in2D = img2->GetPix();
	int outH = output->GetHeight();
	int outW = output->GetWidth();
	Pixel *pixel = new Pixel[outW*outH];

	for (int i = 0; i < outH * outW; i++)
	{
		pixel[i].r = (in1D[i].r * factor ) + (in2D[i].r * (1-factor));
		pixel[i].g = (in1D[i].g * factor ) + (in2D[i].g * (1-factor));
		pixel[i].b = (in1D[i].b * factor ) + (in2D[i].b * (1-factor));
	}
	output->ResetPixel(pixel);
	delete [] pixel;

}

//to set the blend factor since Blender::Execute takes no arguments.
void Blender::SetFactor(double fact)
{
	factor = fact;
}


