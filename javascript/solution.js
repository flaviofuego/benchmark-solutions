const fs = require('fs');

const C_ncacheparentesis = {
    0: [""],
    1: ["()"],
    2: ["()()", "(())"]
};

function recursiva(n) {
    if (n === 0) {
        return [""];
    } else if (n === 1) {
        return ["()"];
    } else if (n === 2) {
        return ["()()", "(())"];
    } else {
        if (!C_ncacheparentesis[n]) {
            C_ncacheparentesis[n] = [];
            for (let m = 0; m < n; m++) {
                for (const p of recursiva(m)) {
                    for (const q of recursiva(n - m)) {
                        C_ncacheparentesis[n].push(p + q);
                        C_ncacheparentesis[n].push(q + p);
                        C_ncacheparentesis[n].push(p.slice(0, p.length / 2) + q + p.slice(p.length / 2));
                    }
                }
            }
            C_ncacheparentesis[n] = [...new Set(C_ncacheparentesis[n])];
        }
        return C_ncacheparentesis[n];
    }
}

const startTime = Date.now();
const result = recursiva(12);
const endTime = Date.now();
const execTimeMs = endTime - startTime;

// Escribir el resultado en /output/result_javascript.txt
fs.writeFileSync('/output/result_javascript.txt', result.join("\n"));

// Imprimir solo el tiempo de ejecución
console.log(execTimeMs);
