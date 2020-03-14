import math

from aco import ACO, Graph
from plot import plot
import time


def distance(city1: dict, city2: dict):
    return math.sqrt((city1['x'] - city2['x']) ** 2 + (city1['y'] - city2['y']) ** 2)


def main():
    start = time.time()
    cities = []
    points = []
    value = input('Input a file:')
    with open(value) as f:
        for line in f.readlines():
            line = line.strip();
            #city = line.split(' ')
            city = line.split()
            #print (city)
            cities.append(dict(index=int(city[0]), x=int(city[1]), y=int(city[2])))
            points.append((int(city[1]), int(city[2])))
    cost_matrix = []
    rank = len(cities)
    for i in range(rank):
        row = []
        for j in range(rank):
            row.append(distance(cities[i], cities[j]))
        cost_matrix.append(row)
    aco = ACO(3, 5, 1.0, 10.0, 0.5, 10, 2)
    graph = Graph(cost_matrix, rank)
    path, cost = aco.solve(graph)
    #print('cost: {}, path: {}'.format(cost, path))
    print('cost: {}'.format(cost))
    end = ( time.time()-start)
    print ('running time= '+str(end)+' seconds')

    #plot(points, path)

if __name__ == '__main__':
    main()
