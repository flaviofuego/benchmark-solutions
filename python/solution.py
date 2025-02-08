#!/usr/bin/env python3
import time

C_ncacheparentesis = {
    0: [""],
    1: ["()"],
    2: ["()()", "(())"]
}

def recursiva(n):
    if n == 0:
        return [""]
    elif n == 1:
        return ["()"]
    elif n == 2:
        return ["()()", "(())"]
    else:
        if n not in C_ncacheparentesis:
            C_ncacheparentesis[n] = []        
            for m in range(n):
                for p in recursiva(m):
                    for q in recursiva(n-m):
                        C_ncacheparentesis[n].append(p+q)
                        C_ncacheparentesis[n].append(q+p)
                        C_ncacheparentesis[n].append(p[0:int(len(p)/2)] + q + p[int(len(p)/2):int(len(p))]   )
            C_ncacheparentesis[n] = list(set(C_ncacheparentesis[n]))
        return C_ncacheparentesis[n]
    
if __name__ == "__main__":
    start_time = time.time()
    result = recursiva(12)
    end_time = time.time()
    exec_time_ms = int((end_time - start_time) * 1000)
    
    # Escribir el resultado en /output/result_python.txt
    with open("/output/result_python.txt", "w") as f:
        for r in result:
            f.write(r + "\n")
    
    # Imprimir únicamente el tiempo de ejecución en ms
    print(exec_time_ms)
