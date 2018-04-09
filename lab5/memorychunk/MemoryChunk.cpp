//
// Created by giersand on 27.03.18.
//

#include "MemoryChunk.h"

MemoryChunk::MemoryChunk() {
    //
}

MemoryChunk::~MemoryChunk(){
//
}

MemoryChunk::MemoryChunk(MemoryChunk &other){
//
}

MemoryChunk::MemoryChunk(size_t sz) {
    pointer_ = new int8_t[sz];
}

int8_t* MemoryChunk::MemoryAt(size_t offset) const {
//
}

size_t MemoryChunk::ChunkSize() const {
//
}