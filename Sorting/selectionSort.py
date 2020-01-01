def main():
    vet = [5, 4, 8, 3, 1, 0, 2]

    print("SELECTION SORT em Python")

    print("Antes de ordenar: {}".format(vet))

    sort(vet, len(vet))

    print("Apos de ordenar: {}".format(vet))

def sort(vector, length):
    # Percorrendo vetor
    for i in range(length):
        indexVMin = i # index do menor valor atualmente

        # Buscando o menor valor no intervalor entre a parte já ordenada e o fim da lista
        for j in range(i + 1, length):
            if(vector[j] < vector[indexVMin]):
                indexVMin = j

        # Efetuando a troca
        [vector[indexVMin], vector[i]] = [vector[i], vector[indexVMin]]

main()
