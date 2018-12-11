#include <stdlib.h>
#include <string.h>
#include <image.h>
#include <source.h>


Pixel::Pixel(void) {r = 0; g = 0; b = 0;};
Pixel::Pixel(unsigned char red, unsigned char green, unsigned char blue)
{
	r = red;
	g = green;
	b = blue;
};

//setter
void Pixel::ResetRGB(unsigned char red, unsigned char green, unsigned char blue)
{
	r = red;
	g = green;
	b = blue;
}

//getters
unsigned char Pixel::Getr()
{
	return r;
}
unsigned char Pixel::Getg()
{
	return g;
}
unsigned char Pixel::Getb()
{
	return b;
}

//Image constructors
Image::Image(void)
{
	maxval = 255;
	ResetSize(0,0);
	pixel = NULL;
};

Image::Image(Image &im)
{
	width = im.width;
	height = im.height;
	maxval = im.maxval;
	pixel = new Pixel[im.width * im.height];
	if (pixel == NULL)
	{ pixel = new Pixel[width * height];
	};
}

Image::Image(Pixel *p, int w, int h, int max)
{
	width = w;
	height = h;
	maxval = max;
	pixel = new Pixel[width * height];
};

//destructor
Image::~Image()
{
	if (pixel != NULL){
	    delete [] pixel;
	};
}
//setters
void Image::ResetSize(int wid, int hei)
{
	width = wid;
	height = hei;
};

void Image::ResetPixel(Pixel *pix)
{
	if (pixel==NULL)
	{ pixel = new Pixel[width * height];
	}
	memcpy(pixel, pix, sizeof(Pixel) * width * height);
}

void Image::ResetMax(int maxv)
{
	maxval = maxv;
}

//getters
Pixel* Image::GetPix()
{
	return pixel;
}

int Image::GetWidth()
{
	return width;
}

int Image::GetHeight()
{
	return height;
}

int Image::GetMaxval()
{
	return maxval;
}

void Image::SetSource(Source *s)
{
	sour = s;
}

void Image::Update()
{
	sour->Update();
}

