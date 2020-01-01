def main():
    vet = [5, 4, 8, 3, 1, 0, 2]

    print("BUBBLE SORT em Python")

    print("Antes de ordenar: {}".format(vet))

    sort(vet, len(vet))

    print("Apos de ordenar: {}".format(vet))

def sort(vector, length):
    # Percorrendo vetor
    for i in range(length):
        
        # percorrendo a parte da lista que não "está ordenada"(tamanhoTotal - (quantiJaOrdenada + 1)) e empurrando o maior valor para o fim
        for j in range(length - (i + 1)):
            if(vector[j] > vector[j + 1]):
                [vector[j], vector[j + 1]] = [vector[j + 1], vector[j]]


main()
