FROM openjdk:11-jdk-slim

WORKDIR /app

COPY Solution.java .

# Compilar el código Java
RUN javac Solution.java

# Crear el directorio de salida
RUN mkdir -p /output

CMD ["java", "Solution"]
