# Utilizar la imagen base más ligera con soporte para C++
FROM alpine:3.21

# Instalar las herramientas necesarias para compilar y ejecutar C++ en Alpine
RUN apk add --no-cache g++ libc-dev

WORKDIR /app

COPY solution.cpp .

RUN g++ -O2 -o solution solution.cpp

RUN mkdir -p /output

CMD ["./solution"]
