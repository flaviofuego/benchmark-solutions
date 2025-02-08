FROM gcc:latest

WORKDIR /app

COPY solution.cpp .

RUN g++ -O2 -o solution solution.cpp

RUN mkdir -p /output

CMD ["./solution"]
