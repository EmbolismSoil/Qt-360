#ifndef OVERLOADNEW_H
#define OVERLOADNEW_H
extern void *operator new(unsigned int size, const char *file, int line);
extern void operator delete(void *p, const char *file, int line);

#define new new(__FILE__, __LINE__)

#endif // OVERLOADNEW_H
