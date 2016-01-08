#ifndef TRACER_H
#define TRACER_H

#include <string>
#include <map>
#include <iostream>

class Tracer;
class Tracer
{
public:
    static Tracer &getTracer(){
        static Tracer *tracer = NULL;
        if (tracer == NULL)
            tracer = new Tracer;
        return *tracer;
    }
    void logAdd(unsigned int addr, std::string logs);
    void logRemove(unsigned add);
    void print(void)
    {
        for (std::map<unsigned int, std::string>::iterator pos = log.begin();
                                                            pos != log.end(); ++pos)
            std::cout << (*pos).first << "  " << (*pos).second << std::endl;
    }
private:
    Tracer();
    Tracer(const Tracer &);
     std::map<unsigned int , std::string>  log;
};

#endif // TRACER_H
