#include <sink.h>

Sink::Sink(void)
{
	img1 = NULL;
	img2 = NULL;
}


void Sink::SetInput(Image *img)
{
	img1 = img;
}

void Sink::SetInput2(Image *img)
{
	img2 = img;
}

