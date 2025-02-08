FROM openjdk:17-alpine

WORKDIR /app

COPY Solution.java .

RUN javac Solution.java

RUN mkdir -p /output

CMD ["java", "Solution"]
