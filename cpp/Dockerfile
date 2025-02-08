FROM gcc:latest

WORKDIR /app

COPY solution.cpp .

# Compilar el código (con optimización)
RUN g++ -O2 -o solution solution.cpp

# Crear el directorio de salida
RUN mkdir -p /output

CMD ["./solution"]
