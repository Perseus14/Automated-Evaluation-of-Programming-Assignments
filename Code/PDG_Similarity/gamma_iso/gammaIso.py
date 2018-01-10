import networkx as nx
import pickle
from networkx.algorithms import isomorphism
import sys


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
if(KFilter(G1, G2, K=10)):
	DiGM1 = isomorphism.DiGraphMatcher(G1,G2)
	DiGM2 = isomorphism.DiGraphMatcher(G2,G1)
	'''
	print DiGM1.subgraph_is_isomorphic()
	print DiGM1.mapping
	print "\n\n----------------DIGM2------------------------\n\n"
	print DiGM2.subgraph_is_isomorphic()
	print DiGM2.mapping
	'''
	sim1 = -1
	sim2 = -1
	if(DiGM1.subgraph_is_isomorphic()):
		sim1 = len(DiGM1.mapping)/float(len(G2.nodes())) 	
	if(DiGM2.subgraph_is_isomorphic()):
		sim2 = len(DiGM2.mapping)/float(len(G1.nodes()))
	else:
		print 0
		exit() 
	if(sim1 > sim2):
		print sim1
	else:
		print sim2
else:
	print 0
