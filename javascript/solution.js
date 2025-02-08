const fs = require('fs');

function isPrime(n) {
    if (n < 2) return false;
    if (n === 2) return true;
    if (n % 2 === 0) return false;
    let sqrt = Math.sqrt(n);
    for (let i = 3; i <= sqrt; i += 2) {
        if (n % i === 0)
            return false;
    }
    return true;
}

function sumFirstNPrimes(n) {
    let count = 0;
    let num = 2;
    let total = 0;
    while (count < n) {
        if (isPrime(num)) {
            total += num;
            count++;
        }
        num++;
    }
    return total;
}

const startTime = Date.now();
const total = sumFirstNPrimes(10000);
const endTime = Date.now();
const execTimeMs = endTime - startTime;

// Escribir el resultado en /output/result_javascript.txt
fs.writeFileSync('/output/result_javascript.txt', total.toString());

// Imprimir solo el tiempo de ejecución
console.log(execTimeMs);
