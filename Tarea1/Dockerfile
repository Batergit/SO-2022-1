FROM alpine

RUN apk update
RUN apk add --no-cache bash

RUN apk add build-base

COPY hola.c ./
COPY hola2.c ./

ENTRYPOINT [ "bash" ]