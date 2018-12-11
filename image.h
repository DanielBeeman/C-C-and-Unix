#ifndef IMAGE_H
#define IMAGE_H
#include <stdlib.h>

class Source;

class Pixel
{
private:
public:
	unsigned char r;
        unsigned char g;
        unsigned char b;
	Pixel(Pixel &); //copy constructor

	Pixel(void); //default constructor
	Pixel(unsigned char r, unsigned char g, unsigned char b); //parameterized constructor
	void ResetRGB (unsigned char r, unsigned char g, unsigned char b);
	
	//getters
	unsigned char Getr();
	unsigned char Getg();
	unsigned char Getb();
};
class Image
{
private:
public:
        Pixel *pixel;
	int width;
        int height;
        int maxval;
	Source * sour;

	

	Image(Image &); //copy constructor


 	Image(void); //default constructor
	Image(Pixel *pixel, int width, int height, int maxval); //parameterized constructor
	~Image();

	//setters
	void ResetSize(int width, int height);
	void ResetPixel(Pixel *pixel);
	void ResetMax(int maxval);

	//getters	
	Pixel* GetPix();
	int GetWidth();
	int GetHeight();
	int GetMaxval();
	
	
	void SetSource(Source *);
	void virtual Update();
};


#endif

