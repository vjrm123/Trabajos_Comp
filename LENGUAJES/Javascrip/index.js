// Obtén los elementos de los botones y la ventana de visualización
const valorAnterior = document.getElementById("valor_anterior");
const valorActual = document.getElementById("valor_actual");
const botonesNumeros = document.querySelectorAll(".numero");
const botonesOperadores = document.querySelectorAll(".operador" );
const botonIgual = document.querySelector(".operador");
const botonBorrarTodo = document.querySelector(".col_dos");
const botonBorrarUltimo = document.querySelector(".borrar-ultimo"); 

// Inicializa los valores
let operacion = "";
let numeroAnterior = "";
let numeroActual = "";

// Función para actualizar la ventana de visualización
function actualizarVisualizacion() {
    valorActual.innerText = numeroActual;
    valorAnterior.innerText = numeroAnterior + " " + operacion;
}

// Manejador de eventos para los botones de números
botonesNumeros.forEach((boton) => {
    boton.addEventListener("click", () => {
        numeroActual += boton.innerText;
        actualizarVisualizacion();
    });
});

// Manejador de eventos para los botones de operadores
botonesOperadores.forEach((boton) => {
    boton.addEventListener("click", () => {
        if (numeroActual === "") return;
        if (numeroAnterior !== "") {
            calcular();
        }
        operacion = boton.innerText;
        numeroAnterior = numeroActual;
        numeroActual = "";
        actualizarVisualizacion();
    });
});

// Función para realizar el cálculo
function calcular() {
    let resultado;
    const anterior = parseFloat(numeroAnterior);
    const actual = parseFloat(numeroActual);
    switch (operacion) {
        case "+":
            resultado = anterior + actual;
            break;
        case "-":
            resultado = anterior - actual;
            break;
        case "X":
            resultado = anterior * actual;
            break;
        case "%":
            resultado = actual * (anterior /100) ;
            break;
        case "÷":
            if (anterior === 0) {
                return;
            } else {
                resultado = (anterior  / actual);
                break;
            }
        default:
            return;
    }
    numeroActual = resultado.toString();
    operacion = "";
    numeroAnterior = "";
    actualizarVisualizacion();
}

// Manejador de eventos para el botón de igual
botonIgual.addEventListener("click", () => {
    calcular();
});

// Manejador de eventos para el botón de borrar
botonBorrarTodo.addEventListener("click", () => {
    numeroActual = " ";
    actualizarVisualizacion();
});

// Manejador de eventos para el botón de borrar último dígito
botonBorrarUltimo.addEventListener("click", () => {
    numeroActual = numeroActual.slice(0, -1);
    actualizarVisualizacion();
});
