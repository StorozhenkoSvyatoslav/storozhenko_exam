FROM ubuntu:latest

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
    build-essential \
    g++ \
    cmake \
    && rm -rf /var/lib/apt/lists/*

COPY MemoryCache.h MemoryCache.cpp main.cpp ./

RUN g++ -o exam_Program MemoryCache.cpp main.cpp

ENV DEFAULT_VALUE="Hello Docker"

CMD ["./exam_Program"]