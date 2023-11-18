FROM quay.io/school21/alpine:3.16

RUN apk update
RUN apk --no-cache --upgrade add \
    git \
    git-lfs \
    curl \
    jq \
    bash \
    build-base \
    python3 \
    valgrind \
    cppcheck \
    alpine-sdk \
    pcre-dev \
    clang-extra-tools \
    check-dev \
    check \
    subunit-dev

# Install CMake
RUN apk add --no-cache cmake

# Install Google Test Framework
RUN git clone https://github.com/google/googletest.git && \
    cd googletest && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make -j$(nproc) && \
    make install && \
    cd ../.. && \
    rm -rf googletest

RUN mkdir /test 
COPY . /project
WORKDIR "/project"
