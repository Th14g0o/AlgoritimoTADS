function calc() {
    const exprInput = document.getElementById("exprCalc").value;
    const respostaP = document.getElementById("resposta");

    if (!exprInput.trim()) {
        respostaP.innerHTML = "Digite uma expressão.";
        return;
    }

    const exprStr = exprInput.replace(/\*\*/g, '^');

    let result;
    try {
        result = math.evaluate(exprStr);
    } catch (e) {
        respostaP.innerHTML = "Expressão inválida.";
        return;
    }

    respostaP.innerHTML = `Resultado: <strong>${result}</strong>`;
}
