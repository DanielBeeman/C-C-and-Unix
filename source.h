#ifndef SOURCE_H
#define SOURCE_H
#include <image.h>

class Source
{
protected:
	Image output;

public:
	Source();
	virtual void Execute(void) =0;
	Image*  GetOutput();
	virtual void Update(void) = 0;
};

#endif
