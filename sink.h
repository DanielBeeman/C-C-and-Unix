#ifndef SINK_H
#define SINK_H
#include <image.h>

struct Sink
{
protected:
	Image *img1;
	Image *img2;
public:
	Sink();
	void SetInput(Image *);
	void SetInput2(Image *);

};
#endif
