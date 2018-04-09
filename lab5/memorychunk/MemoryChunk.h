//
// Created by giersand on 27.03.18.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H

#include <cstdint>
#include <algorithm>

class MemoryChunk {
public:
    MemoryChunk();
    ~MemoryChunk();
    MemoryChunk(MemoryChunk &other);
    MemoryChunk(size_t sz);

    MemoryChunk & operator=(MemoryChunk &&other);

    int8_t *MemoryAt(size_t offset) const;
    size_t ChunkSize() const;
private:
    int8_t* pointer_;
};

#endif //JIMP_EXERCISES_MEMORYCHUNK_H
