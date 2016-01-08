#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include <stdio.h>

class Tracer{
 public:
     static Tracer &getTracer(){
         if (tracer == NULL){
             tracer = new Tracer;
         }
         return *tracer;
     }

     void logAdd(unsigned int addr, const std::string& log);
     void logRemove(unsigned int addr, const std::string& msg);
 private:
     Tracer *tracer;
     Tracer();
     Tracer(const Tracer &);
     std::map<unsigned int, std::string>  log;
};



void Tracer::logAdd(unsigned int addr, const std::string &log)
{
    log[addr] = log;
}

void Tracer::logRemove(unsigned int addr, const std::string &msg)
{
    std::string &str = log[addr];
    std::cout << "alloc "  << addr << " in " << str << "free in " << msg << std::endl;
    log.erase(addr);
}

void *operator new(unsigned int size, const char *file, int line)
{
    void *tmp = ::operator new(size);
    char buf[100];
    sprintf(buf, "%d", line);
    std::string lineStr(buf);
    std::string logStr = std::string(file) + lineStr;
    Tracer &tracer = Tracer::getTracer();
    tracer.logAdd(tmp, logStr);

    return tmp;
}

void operator delete(void *p, const char *file, int line)
{
    ::operator delete(p);
    char buf[100];
    sprintf(buf, "%d", line);
    std::string lineStr(buf);
    std::string logStr = std::string(file) + lineStr;
    Tracer &tracer = Tracer::getTracer();
    tracer.logRemove(p, logStr);
}
