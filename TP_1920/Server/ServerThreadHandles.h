#ifndef SERVERTHREADHANDLES_H
#define SERVERTHREADHANDLES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "serverHeader.h"

    void ThreadKill(int);
    void* newClientThreadHandle(void*);
    
#ifdef __cplusplus
}
#endif

#endif