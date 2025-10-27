let chart;

function plot() {
    const exprInput = document.getElementById("expression").value;
    const xmin = parseFloat(document.getElementById("xmin").value);
    const xmax = parseFloat(document.getElementById("xmax").value);
    const step = parseFloat(document.getElementById("step").value);

    // Transfora n em x e ** para ^ 
    const exprStr = exprInput != "" ? exprInput.replace(/\*\*/g, "\^").replace(/n/g, "x") : "x";

    let expr;
    try {
        expr = math.compile(exprStr);
    } catch (e) {
        return;
    }

    const xs = [];
    const ys = [];

    for (let x = xmin; x <= xmax; x += step) {
        xs.push(x);
        try {
            const y = expr.evaluate({ x });
            ys.push(y);
        } catch (e) {
            ys.push(NaN);
        }
    }

    const ctx = document.getElementById("chart").getContext("2d");

    if (chart) chart.destroy();

    chart = new Chart(ctx, {
        type: "line",
        data: {
            labels: xs,
            datasets: [{
                label: "f(x)",
                data: ys,
                borderColor: "deepskyblue",
                borderWidth: 2,
                pointRadius: 0,
                fill: false,
                tension: 0.1
            }]
        },
        options: {
            responsive: true,
            plugins: {
                legend: {
                    labels: {
                        color: "deepskyblue",        // Cor da legenda
                        font: {
                            size: 14,              // Tamanho da fonte
                            weight: "bold",        // Negrito
                            style: "italic"        // *Itálico* (opcional)
                        }
                    },
                    position: "bottom"            // Posição da legenda (top, bottom, left, right)
                }
            },
            scales: {
                x: {
                    title: {
                        display: true,
                        text: "x",
                        color: "#fff" // Cor do título do eixo x
                    },
                    ticks: {
                        color: "#fff" // Cor dos números do eixo x
                    },
                    grid: {
                        color: "#fff" // Cor da grade do eixo x
                    }
                },
                y: {
                    title: {
                        display: true,
                        text: "f(x)",
                        color: "#fff" // Cor do título do eixo y
                    },
                    ticks: {
                        color: "#fff" // Cor dos números do eixo y
                    },
                    grid: {
                        color: "#fff" // Cor da grade do eixo y
                    }
                }
            }
        }
    });
}

let chartList; // para guardar o gráfico da lista

function plotList() {
    const xInput = document.getElementById("xvalues").value;
    const yInput = document.getElementById("yvalues").value;

    // transforma as strings em arrays numéricos
    const xs = xInput.split(",").map(v => parseFloat(v.trim()));
    const ys = yInput.split(",").map(v => parseFloat(v.trim()));

    // validação básica
    if (xs.length !== ys.length || xs.length === 0) {
        alert("As listas de X e Y devem ter o mesmo tamanho e não podem estar vazias.");
        return;
    }

    // pega o contexto do canvas
    const ctx = document.getElementById("chartList").getContext("2d");

    // destrói gráfico anterior, se existir
    if (chartList) chartList.destroy();

    // cria novo gráfico
    chartList = new Chart(ctx, {
        type: "line",
        data: {
            labels: xs,
            datasets: [{
                label: "Valores da Lista",
                data: ys,
                borderColor: "lime",
                borderWidth: 2,
                pointRadius: 4,
                pointBackgroundColor: "white",
                fill: false,
                tension: 0.2
            }]
        },
        options: {
            responsive: true,
            plugins: {
                legend: {
                    labels: {
                        color: "lime",
                        font: {
                            size: 14,
                            weight: "bold"
                        }
                    },
                    position: "bottom"
                }
            },
            scales: {
                x: {
                    title: {
                        display: true,
                        text: "X",
                        color: "#fff"
                    },
                    ticks: {
                        color: "#fff"
                    },
                    grid: {
                        color: "rgba(255,255,255,0.1)"
                    }
                },
                y: {
                    title: {
                        display: true,
                        text: "Y",
                        color: "#fff"
                    },
                    ticks: {
                        color: "#fff"
                    },
                    grid: {
                        color: "rgba(255,255,255,0.1)"
                    }
                }
            }
        }
    });
}