#include "tracer.h"
#include <memory>
#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include <stdio.h>

void Tracer::logAdd(unsigned int addr, std::string logs)
{
        log[addr] = logs;
}

void Tracer::logRemove(unsigned add)
{
    log.erase(add);
}

Tracer::Tracer()
{

}

void * operator new(unsigned int size, const char *file, int line)
{
     void *tmp = malloc(size);
     char buf[100];
     sprintf(buf, "%d", line);
     std::string lineStr(buf);
     std::string logStr = std::string(file)+ "  " + lineStr;
     Tracer::getTracer().logAdd((unsigned int)(tmp), logStr);

     return tmp;
}

void operator delete(void *p)
{
    free(p);
    Tracer::getTracer().logRemove((unsigned int)p);
}
