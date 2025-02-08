package main

import (
	"fmt"
	"math"
	"os"
	"time"
)

func isPrime(n int) bool {
	if n < 2 {
		return false
	}
	if n == 2 {
		return true
	}
	if n%2 == 0 {
		return false
	}
	sqrtN := int(math.Sqrt(float64(n)))
	for i := 3; i <= sqrtN; i += 2 {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func sumFirstNPrimes(n int) int {
	count := 0
	num := 2
	total := 0
	for count < n {
		if isPrime(num) {
			total += num
			count++
		}
		num++
	}
	return total
}

func main() {
	start := time.Now()
	total := sumFirstNPrimes(10000)
	elapsed := time.Since(start)

	// Escribir el resultado en /output/result.txt
	f, err := os.Create("/output/result.txt")
	if err == nil {
		f.WriteString(fmt.Sprintf("%d", total))
		f.Close()
	}

	// Imprimir solo el tiempo de ejecución en milisegundos
	fmt.Println(elapsed.Milliseconds(), "ms")
}
