FROM openjdk:11-jdk-slim

WORKDIR /app

COPY Solution.java .

RUN javac Solution.java

RUN mkdir -p /output

CMD ["java", "Solution"]
