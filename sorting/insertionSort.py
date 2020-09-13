def main():
    vet = [5, 4, 8, 3, 1, 0, 2]

    print("INSERTION SORT em Python")

    print("Antes de ordenar: {}".format(vet))

    sort(vet, len(vet))

    print("Apos de ordenar: {}".format(vet))


def sort(vector, length):

    # Percorrendo o vetor
    for i in range(length):
        value = vector[i]
        j = i - 1

        # Enquanto o valor atual for menor que o anterior empurre o anterio para a frente
        while j >= 0 and value < vector[j]:
            vector[j + 1] = vector[j]
            j -= 1

        # Colocando o menor valor em sua posição correta
        vector[j + 1] = value

main()
