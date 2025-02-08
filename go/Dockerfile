FROM golang:alpine3.21

WORKDIR /app

COPY solution.go .

# Compilar el binario
RUN go build -o solution solution.go

# Crear el directorio de salida
RUN mkdir -p /output

CMD ["./solution"]
