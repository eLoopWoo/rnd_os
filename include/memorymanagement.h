#ifndef __RND_OS__MEMORYMANAGEMENT_H
#define __RND_OS__MEMORYMANAGEMENT_H

#include <common/types.h>

namespace rnd_os{
    
    struct MemoryChunk{
        MemoryChunk *next;
        MemoryChunk *prev;
        
        bool allocated;
        common::size_t size;
    };
    
    class MemoryManager{
        MemoryChunk* first;
    public:
        
        static MemoryManager *activeMemoryManager;
        
        MemoryManager(common::size_t first, common::size_t size);
        ~MemoryManager();
        
        void* malloc(common::size_t size);
        void free(void* ptr);
        
    };
}

#endif
