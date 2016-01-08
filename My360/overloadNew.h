#ifndef __OVERLOADNEW_H__
#define __OVERLOADNEW_H__
void * operator new(unsigned int size, const char *file, int line);
void operator delete(void *p);
#define new new(__FILE__, __LINE__)
#endif
