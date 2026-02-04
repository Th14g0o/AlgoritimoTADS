import os
import matplotlib.pyplot as plt
import pandas as pd

# Pasta onde estão os arquivos
pasta = "008-ordenacao/saidas/caso1/"

# Tipos de ordenação
tipos = ['i', 'm', 's']

# Inicializar dicionário para guardar dados
dados = {t: [] for t in tipos}

# Percorrer todos os arquivos da pasta
for arquivo in os.listdir(pasta):
    if arquivo.endswith(".txt"):
        # Extrair o tipo do algoritmo pelo sufixo
        for t in tipos:
            if arquivo.endswith(f"{t}.txt"):
                caminho = os.path.join(pasta, arquivo)
                
                with open(caminho, "r") as f:
                    for linha in f:
                        linha = linha.strip()
                        if not linha:
                            continue
                        partes = linha.split(" Tempo de ordenação: ")
                        tamanho = int(partes[0])
                        tempo = int(partes[1].split(" ")[0])
                        dados[t].append((tamanho, tempo))

# Transformar em DataFrame para cada tipo e ordenar por tamanho
dfs = {}
for t in tipos:
    df = pd.DataFrame(dados[t], columns=["Tamanho", "Tempo (μs)"])
    df = df.sort_values("Tamanho")
    dfs[t] = df

# Plotar todos no mesmo gráfico
plt.figure(figsize=(10,6))
cores = {'i':'blue', 'm':'green', 's':'red'}

for t in tipos:
    plt.plot(dfs[t]["Tamanho"], dfs[t]["Tempo (μs)"], marker='o', linestyle='-', color=cores[t], label=t)

plt.title("Comparação de Algoritmos de Ordenação")
plt.xlabel("Tamanho do Array")
plt.ylabel("Tempo de Ordenação (μs)")
plt.legend(title="Algoritmo")
plt.grid(True)
plt.show()
