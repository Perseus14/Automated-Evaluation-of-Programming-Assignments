from igraph import *
a = Graph(4, directed = True)
a.add_edges([ (0,1), (1,2), (2,3), (0,2),(2,0), (1,3),(3,1)])
b = Graph(2, directed = True)
b.add_edges([(0,1),(1,0)])
t = a.subisomorphic_lad(b)
