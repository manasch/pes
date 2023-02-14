FROM ubuntu:18.04
RUN apt-get update
RUN apt-get install gcc -y
COPY program.c program.c
RUN gcc program.c
CMD ["./a.out"]