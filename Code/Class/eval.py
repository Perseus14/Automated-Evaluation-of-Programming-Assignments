import os
import sys
import glob
import pickle
from random import randint

from phases.similarity import Similarity
from phases.cluster import Cluster
from phases.marking import Marking

DATA_PATH = "/home/perseus/Academics/Sem-9/Thesis/Data/CodeForces/"
CODE_PATH = "/home/perseus/Academics/Sem-9/Thesis/Code/Class/"

def get_cfiles(folder):
	corr_files = glob.glob(DATA_PATH+folder+"/Correct/*.c")
	incorr_files = glob.glob(DATA_PATH+folder+"/Incorrect/*.c")
	temp_files = []
	for files in corr_files:
		os.system("gcc -std=c11 -o a.out " + files)
		if os.path.isfile("a.out"):
			temp_files.append(files)
			os.system("rm a.out")
	corr_files = temp_files

	temp_files = []	
	for files in incorr_files:
		os.system("gcc -std=c11 -o a.out " + files)
		if os.path.isfile("a.out"):
			temp_files.append(files)
			os.system("rm a.out")
	incorr_files = temp_files
	return corr_files, incorr_files


def computePDG(corr,FileList):
		if(corr):
			file_ext = "_corr"
		else:
			file_ext = "_incorr"	
		for file in FileList:
				#~/.opam/4.05.0/bin/
				os.system("frama-c -pdg -pdg-dot PDG/"+ file.split("/")[-1].split('.')[0][1:] + file_ext + " " + file)
				
def printSimilarityGraph(sim_list):
	import matplotlib.pyplot as plt
	import networkx as nx
	edge_list = []
	edge_labels = {}
	width = []
	nodelist = set()
	for n1,n2,val in sim_list:
		n1 = n1.split("/")[-1].split('.')[0][1:]
		n2 = n2.split("/")[-1].split('.')[0][1:]
		nodelist.add(n1)
		nodelist.add(n2)
		val = float(val)
		val = float("{0:.2f}".format(val))
		if(val>0):
			edge_list.append((n1,n2,val))
			edge_labels[(n1,n2)] = val
			width.append(2*val)
	G = nx.Graph()
	G.add_nodes_from(list(nodelist))		
	G.add_weighted_edges_from(edge_list)
	pos=nx.spring_layout(G) 			#Define positions of nodes
	edges=nx.draw_networkx_edges(G,pos,edgelist=edge_list,width=width) #Draw edges
	nodes=nx.draw_networkx_nodes(G,pos,nodelist = list(nodelist),node_color='g')	#Draw nodes
	labels=nx.draw_networkx_labels(G,pos) #Draw Labels
	#edge_labels=nx.draw_networkx_edge_labels(G,pos,edge_labels = edge_labels,font_size = 6)
	plt.draw()
	plt.title("Similarity Measurement Graph") 
	plt.show()
	
def printClusterGraph(cluster_set,name):
	import matplotlib.pyplot as plt
	import networkx as nx
	edge_list = []
	node_set = []
	for cluster in cluster_set:
		node_set.append([node.split("/")[-1].split('.')[0][1:] for node in cluster])
		for node_id1 in xrange(len(cluster)-1):
			 	node1 = cluster[node_id1].split("/")[-1].split('.')[0][1:]
	 			for node_id2 in xrange(node_id1+1, len(cluster)):
	 				node2 = cluster[node_id2].split("/")[-1].split('.')[0][1:]
	 				edge_list.append((node1,node2,1.0))
	G = nx.Graph()
	G.add_nodes_from([n for node in node_set for n in node])		
	G.add_weighted_edges_from(edge_list)
	pos=nx.spring_layout(G) 			#Define positions of nodes
	edges=nx.draw_networkx_edges(G,pos) #Draw edges
	color_count = ['b', 'g', 'c', 'm', 'y']
	for node_id in xrange(len(node_set)):
		color = color_count[node_id%len(color_count)]
		if(len(node_set[node_id])==1):
			nodes=nx.draw_networkx_nodes(G,pos,nodelist = node_set[node_id],node_color = 'r')
		else:
			nodes=nx.draw_networkx_nodes(G,pos,nodelist = node_set[node_id],node_color = color)	
	labels=nx.draw_networkx_labels(G,pos) #Draw Labels
	#edge_labels=nx.draw_networkx_edge_labels(G,pos,edge_labels = edge_labels,font_size = 6)
	plt.draw()
	plt.title("Graph Clusters using " + name + " clustering")
	plt.show()

def similarityPhase(corrFileList):
	S = Similarity("_corr")
	similarity_measure_list = S.getSimilarityFromFilesList(corrFileList)	
	return similarity_measure_list
					
def clusteringPhase(similarity_measure_list):
	C = Cluster()
	cluster_set_louv = C.cluster_louvian(similarity_measure_list)
	cluster_set_ipca = C.cluster_ipca(similarity_measure_list)
	#C.printCluster()
	return cluster_set_louv, cluster_set_ipca

def markingPhase(cluster_set, incorrFileList):
	M = Marking("_incorr")
	cluster_set_rep = M.getSetRepresentative(cluster_set)
	marks = M.grading(incorrFileList)
	M.printMarks()
	return marks
	
folder = sys.argv[1]
corr_files, incorr_files = get_cfiles(folder)
os.system("rm -rf PDG")
os.system("mkdir PDG")
computePDG(True,corr_files)
os.system("mkdir PDG/Main")
os.system("mv PDG/*.main.dot PDG/Main/")
os.system("rm PDG/*.*.dot")
os.system("mv PDG/Main/* PDG/")
os.system("rm -rf PDG/Main")
similarity_measure_list = similarityPhase(corr_files)

printSimilarityGraph(similarity_measure_list)

cluster_set_louvian, cluster_set_ipca = clusteringPhase(similarity_measure_list)

printClusterGraph(cluster_set_louvian,"Louvian")
printClusterGraph(cluster_set_ipca,"IPCA")
computePDG(False,incorr_files)
marks = markingPhase(cluster_set_louvian, incorr_files)
'''
with open("grades/"+folder+"_values.pickle","wb") as fin:
	pickle.dump(similarity_measure_list,fin)
	pickle.dump(cluster_set,fin)
	pickle.dump(marks,fin)
'''
