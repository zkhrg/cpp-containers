FROM ubuntu

RUN apt-get update && apt-get install -y \ 
    gcc \
    valgrind \
    make \
    vim \
    check \
    clang-format \
    lcov \
    g++ \
    libgtest-dev


COPY . /project
