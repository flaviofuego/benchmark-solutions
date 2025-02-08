#!/usr/bin/env python3
import time
import math

def is_prime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    r = int(math.sqrt(n)) + 1
    for i in range(3, r, 2):
        if n % i == 0:
            return False
    return True

def sum_first_n_primes(n):
    count = 0
    num = 2
    total = 0
    while count < n:
        if is_prime(num):
            total += num
            count += 1
        num += 1
    return total

if __name__ == "__main__":
    start_time = time.time()
    total = sum_first_n_primes(10000)
    end_time = time.time()
    exec_time_ms = int((end_time - start_time) * 1000)
    
    # Escribir el resultado en /output/result_python.txt
    with open("/output/result_python.txt", "w") as f:
        f.write(str(total))
    
    # Imprimir únicamente el tiempo de ejecución en ms
    print(exec_time_ms)
