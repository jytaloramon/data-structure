#
# @author Ytalo Ramon
# @date   23/01/2022
#

import os
from random import random


def main():

    os.chdir('./sort')

    if (not('dataset' in os.listdir())):
        os.mkdir('dataset')

    confs = [
        ['desc', 10000, create_dataset_desc],
        ['desc', 100000, create_dataset_desc],
        ['desc', 1000000, create_dataset_desc],
        ['desc', 10000000, create_dataset_desc],
        ['asc', 10000, create_dataset_asc],
        ['asc', 100000, create_dataset_asc],
        ['asc', 1000000, create_dataset_asc],
        ['asc', 10000000, create_dataset_asc],
        ['random', 10000, create_dataset_random],
        ['random', 100000, create_dataset_random],
        ['random', 1000000, create_dataset_random],
        ['random', 10000000, create_dataset_random],
        ['sectioned', 10000, create_dataset_sectioned],
        ['sectioned', 100000, create_dataset_sectioned],
        ['sectioned', 1000000, create_dataset_sectioned],
        ['sectioned', 10000000, create_dataset_sectioned]]

    for c in confs:
        generate_dataset(f'dataset/{c[0]}_{c[1]}.txt', c[1], c[2])


def generate_dataset(filemane, size, func_conf):

    save_dataset(func_conf(size), filemane)


def save_dataset(arr, filename):

    f = open(filename, 'w+')
    save_file_dataset(arr, f)


def save_file_dataset(arr, f):
    f.write(f'{len(arr)}\n' + ' '.join(list(map(str, arr))))


def create_dataset_desc(size):

    return [i for i in range(size, 0, -1)]


def create_dataset_asc(size):

    return [i for i in range(size)]


def create_dataset_random(size):

    return [int(random() * size * 100) for i in range(size)]


def create_dataset_sectioned(size):

    arr = []
    dataset_type = [create_dataset_desc,
                    create_dataset_asc, create_dataset_random]
    seq_max = 64

    while len(arr) < size:
        i, s = int(random() * 10) % 3, int(random() * 1000) % seq_max
        arr.extend((dataset_type[i])(s))

    return arr[:size]


if __name__ == '__main__':
    main()
