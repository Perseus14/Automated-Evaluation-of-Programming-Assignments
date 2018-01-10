import networkx as nx
import pickle
from networkx.algorithms import isomorphism
import sys
import itertools


def InitGraph(nodes, edges):
	G = nx.DiGraph()

	for node in nodes:
		G.add_node(node)
		#print node
	for edge in edges:
		G.add_edge(edge[0],edge[1])	
		#print edge
	return G

def KFilter(G1,G2,K=10,gamma = 0.7):
	#Size-Filter
	if(len(G1.nodes()) > K and len(G2.nodes()) > K):
		#Filter based on gamma isomorphism criterion
		if(len(G2.nodes()) >= gamma*(len(G1.nodes())) and len(G2.nodes()) <= (1/gamma)*(len(G1.nodes()))):
			return True
	return False 
		
with open(sys.argv[1],"rb") as fin:
		nodes_graph1 = pickle.load(fin)
		edges_graph1 = pickle.load(fin)

with open(sys.argv[2],"rb") as fin:
		nodes_graph2 = pickle.load(fin)
		edges_graph2 = pickle.load(fin)

		
G1 = InitGraph(nodes_graph1,edges_graph1)
G2 = InitGraph(nodes_graph2,edges_graph2)

'''
print G1.nodes()
print G2.nodes()
print G1.edges()
print G2.edges()
'''
print "\n\n\n"

gamma = 0.7
if(KFilter(G1, G2, K=10, gamma=0.7)):
	vertex_length = len(nodes_graph1)
	flag = False
	while(vertex_length > gamma*len(nodes_graph1)):
		list_l_vertex_subset = map(list,list(itertools.combinations(nodes_graph1, vertex_length)))
		for vertex_set in list_l_vertex_subset:
			Gv = G1.subgraph(vertex_set)
			DiGMv = isomorphism.DiGraphMatcher(Gv,G2)
			if(DiGMv.subgraph_is_isomorphic()):
				count = len(DiGMv.mapping)
				print DiGMv.mapping	
				flag = True
				break
		if(flag):
			break
		vertex_length-=1
	if(vertex_length <= gamma*len(nodes_graph1)):
		print "Not isomorphic"
	else:
		similarity = 2*count/(nodes_graph1 + nodes_graph2)
		print similarity
else:
	print "KFilter Failed"
