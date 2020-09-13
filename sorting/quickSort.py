def main():
    vet = [5, 4, 8, 3, 1, 0, 2]

    print("QUICK SORT em Python")

    print("Antes de ordenar: {}".format(vet))

    sort(vet, 0, len(vet))

    print("Apos de ordenar: {}".format(vet))

def sort(vector, startInterv, endInterv):
    if(startInterv >= endInterv - 1):
        return

    posiPivot = partition(vector, startInterv, endInterv)

    sort(vector, startInterv, posiPivot)
    sort(vector, posiPivot + 1, endInterv)

def partition(vector, startInterv, endInterv):
    down = startInterv
    up = endInterv - 1
    middle = (down + up) // 2
    vPivot = vector[middle]

    while down < up:
        while vector[down] <= vPivot and down < up:
            down += 1

        while vector[up] >= vPivot and down < up:
            up -= 1

        if(down < up):
            [vector[down], vector[up]] = [vector[up], vector[down]]
            down += 1
            up -= 1

    [vector[middle], vector[up]] = [vector[up], vector[middle]]

    return up

main()
