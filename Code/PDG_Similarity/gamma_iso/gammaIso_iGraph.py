import networkx as nx
import pickle
from networkx.algorithms import isomorphism
import sys
import igraph as ig

def InitGraph(nodes, edges):
	G = nx.DiGraph()

	for node in nodes:
		G.add_node(node)
		#print node
	for edge in edges:
		G.add_edge(edge[0],edge[1])	
		#print edge
	return G

def KFilter(ig1,ig2,K=10,gamma = 0.7):
	#Size-Filter
	if(len(ig1.vs) > K and len(ig2.vs) > K):
		#Filter based on gamma isomorphism criterion
		if(len(ig2.vs) >= gamma*(len(ig1.vs))):
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

ig1 = ig.Graph(len(G1),  [ (int(x),int(y)) for x,y in zip(*zip(*nx.to_edgelist(G1))[:2])])                            

ig2 = ig.Graph(len(G2),  [ (int(x),int(y)) for x,y in zip(*zip(*nx.to_edgelist(G1))[:2])]) 

if(KFilter(ig1, ig2, K=10)):
	
	'''
	print DiGM1.subgraph_is_isomorphic()
	print DiGM1.mapping
	print "\n\n----------------DIGM2------------------------\n\n"
	print DiGM2.subgraph_is_isomorphic()
	print DiGM2.mapping
	'''
	sim1 = 0
	sim2 = 0
	res1 = ig1.subisomorphic_vf2(ig2,return_mapping_12=True)
	res2 = ig2.subisomorphic_vf2(ig1,return_mapping_12=True)
	if(res1[0]):
		sim1 = (max(res1[1])+1)/float(len(ig1.vs)) 	
	if(res2[0]):
		sim2 = (max(res2[1])+1)/float(len(ig2.vs))
	else:
		print 0
		exit() 
	if(sim1 > sim2):
		print sim1
	else:
		print sim2
else:
	print 0
