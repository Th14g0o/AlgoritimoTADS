import os
import matplotlib.pyplot as plt
import pandas as pd

class gera_grafico:
    def __init__(self, caminho = ""):
        self.pasta = caminho
        self.tipos = ['i', 'm', 's']

    def gerar(self, caminho = "", titulo = "Grafico"):
        if (caminho != ""):
            self.pasta = caminho
        # Inicializar dicionário para guardar dados
        dados = {t: [] for t in self.tipos}

        # Percorrer todos os arquivos da pasta
        for arquivo in os.listdir(self.pasta):
            if arquivo.endswith(".txt"):
                # Extrair o tipo do algoritmo pelo sufixo
                for t in self.tipos:
                    if arquivo.endswith(f"{t}.txt"):
                        caminho = os.path.join(self.pasta, arquivo)
                        
                        with open(caminho, "r") as f:
                            for linha in f:
                                linha = linha.strip()
                                if not linha:
                                    continue
                                partes = linha.split(" ")

                                tamanho = int(partes[0])
                                tempo = int(partes[4])
                                dados[t].append((tamanho, tempo))

        # Transformar em DataFrame para cada tipo e ordenar por tamanho
        dfs = {}
        for t in self.tipos:
            df = pd.DataFrame(dados[t], columns=["Tamanho", "Tempo (μs)"])
            df = df.sort_values("Tamanho")
            dfs[t] = df

        # Plotar todos no mesmo gráfico
        plt.figure(figsize=(10,6))
        cores = {'i':'blue', 'm':'green', 's':'red'}
        labels = {'i':'Inserção', 'm':'Merge', 's':'Seleção'}

        for t in self.tipos:
            plt.plot(dfs[t]["Tamanho"], dfs[t]["Tempo (μs)"], marker='o', linestyle='-', color=cores[t], 
                    label=labels[t])

        plt.title(titulo)
        plt.xlabel("Tamanho do Array")
        plt.ylabel("Tempo de Ordenação (μs)")
        plt.legend(title="Algoritmo TADS")
        plt.grid(True)
        plt.show()


# Pasta onde estão os arquivos
pastas = ["008-ordenacao/saidas/caso1/", "008-ordenacao/saidas/caso2/", 
          "008-ordenacao/saidas/caso3/", "008-ordenacao/saidas/caso4/",
          "008-ordenacao/saidas/caso5/"]

gg = gera_grafico()
a = 1
for caminho in pastas:
    gg.gerar(caminho, "Comparação de Algoritmos de Ordenação Caso: " + str(a))
    a += 1

