package main

import (
	"fmt"
	"os"
    "time"
)

var C_ncacheparentesis = map[int][]string{
	0: {""},
	1: {"()"},
	2: {"()()", "(())"},
}

func recursiva(n int) []string {
	if n == 0 {
		return []string{""}
	} else if n == 1 {
		return []string{"()"}
	} else if n == 2 {
		return []string{"()()", "(())"}
	} else {
		if _, exists := C_ncacheparentesis[n]; !exists {
			C_ncacheparentesis[n] = []string{}
			for m := 0; m < n; m++ {
				for _, p := range recursiva(m) {
					for _, q := range recursiva(n - m) {
						C_ncacheparentesis[n] = append(C_ncacheparentesis[n], p+q)
						C_ncacheparentesis[n] = append(C_ncacheparentesis[n], q+p)
						C_ncacheparentesis[n] = append(C_ncacheparentesis[n], p[:len(p)/2]+q+p[len(p)/2:])
					}
				}
			}
			unique := make(map[string]struct{})
			for _, v := range C_ncacheparentesis[n] {
				unique[v] = struct{}{}
			}
			C_ncacheparentesis[n] = []string{}
			for k := range unique {
				C_ncacheparentesis[n] = append(C_ncacheparentesis[n], k)
			}
		}
		return C_ncacheparentesis[n]
	}
}

func main() {
    start := time.Now()
    result := recursiva(12)
    elapsed := time.Since(start)

    // Escribir el resultado en /output/result_go.txt
    f, err := os.Create("/output/result_go.txt")
    if err == nil {
        for _, r := range result {
            f.WriteString(r + "\n")
        }
        f.Close()
    }

    // Imprimir solo el tiempo de ejecución en milisegundos
    fmt.Println(elapsed.Milliseconds())
}
