#ifndef PNMREADER_H
#define PNMREADER_H
#include <source.h>
#include <string.h>
#include <cstring>


//inherits publicly from source, has a private variable filename which is 
//passed into execute via the contsructor. 
class PNMreader : public Source {
private:
	char *filename;
public:	
	PNMreader(char *f);
	~PNMreader();
	virtual void Execute();
	virtual void Update();
};

#endif
