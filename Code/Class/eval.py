import os
import sys
import glob
import pickle
import numpy as np
from random import randint
from nltk import agreement

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
		os.system("gcc -w -std=c11 -o a.out " + files + " -lm")
		if os.path.isfile("a.out"):
			temp_files.append(files)
			os.system("rm a.out")
	corr_files = temp_files

	temp_files = []	
	for files in incorr_files:
		os.system("gcc -w -std=c11 -o a.out " + files + " -lm")
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
	
def printClusterGraph(cluster_set, name):
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
	
def cluster_purity(cluster_set, corr_files, filename):
	pred_cluster = []
	act_cluster = []
	for sol in corr_files:
		for cluster_id in xrange(len(cluster_set)):	
			if(sol in cluster_set[cluster_id]):
				pred_cluster.append(cluster_id)
				break
	cluster_dict = {}
	with open(filename,'r') as fin:
		for line in fin.readlines():
			line = line.strip('\n')
			[sol, cluster_val] = line.split()
			cluster_dict[sol] = int(cluster_val)
	
	for sol in corr_files:
		act_cluster.append(cluster_dict[sol.split('/')[-1]])
		
	##Calculate purity
	clusters = np.array(pred_cluster)
	classes = np.array(act_cluster)
	A = np.c_[(clusters,classes)]

	n_accurate = 0.

	for j in np.unique(A[:,0]):
		z = A[A[:,0] == j, 1]
		x = np.argmax(np.bincount(z))
		n_accurate += len(z[z == x])

	purity = n_accurate / A.shape[0]
	print "\nPurity of clusters: ", purity
	return purity
	
def rater_score(filename, marks, corr_files):
	human_raters = [] 
	auto_rate = []
	marks_dict = {}
	for (sol,mark) in marks:
		marks_dict[sol] = mark
		
	cluster_dict = {}
	with open(filename,'r') as fin:
		for line in fin.readlines():
			line = line.strip('\n')
			vals = line.split()
			sol = vals[0]
			cluster_vals = vals[1:] 
			cluster_dict[sol] = map(int,cluster_vals)
			n_humans = len(cluster_vals)
	
	for x in xrange(n_humans):
		human_raters.append([])
			
	for sol in corr_files:
		vals = cluster_dict[sol.split('/')[-1]]
		for x in xrange(n_humans):
			human_raters[x].append(vals[x])
		auto_rate.append(marks_dict[sol])	
	
	##Calculating Score
	tasks_humans = [[[j,str(i),str(human_raters[j][i])] for i in range(len(human_raters[0]))] for j in xrange(len(human_raters))]

	tasks_humans = [item for sublist in tasks_humans for item in sublist]

	#print tasks_humans

	total_raters = human_raters + [auto_rate]
	tasks_auto = [[[j,str(i),str(total_raters[j][i])] for i in range(len(total_raters[0]))] for j in xrange(len(total_raters))]

	tasks_auto = [item for sublist in tasks_auto for item in sublist]


	print "\n\nAgreement Rate with only human ratings\n"

	ratingtask_humans = agreement.AnnotationTask(data=tasks_humans)
	print("kappa " +str(ratingtask_humans.kappa()))
	print("fleiss " + str(ratingtask_humans.multi_kappa()))
	print("alpha " +str(ratingtask_humans.alpha()))
	print("scotts " + str(ratingtask_humans.pi()))
	
	
	print "\n\nAgreement Rate with our ratings included \n"
	
	ratingtask_auto = agreement.AnnotationTask(data=tasks_auto)
	print("kappa " +str(ratingtask_auto.kappa()))
	print("fleiss " + str(ratingtask_auto.multi_kappa()))
	print("alpha " +str(ratingtask_auto.alpha()))
	print("scotts " + str(ratingtask_auto.pi()))
	
				
def similarityPhase(corrFileList):
	S = Similarity("_corr")
	similarity_measure_list = S.getSimilarityFromFilesList(corrFileList)	
	return similarity_measure_list
					
def clusteringPhase(similarity_measure_list):
	C = Cluster()
	cluster_set_louv = C.cluster_louvian(similarity_measure_list)
	cluster_set_ipca = C.cluster_ipca(similarity_measure_list)
	cluster_set_spectral = C.cluster_spectral(similarity_measure_list, len(cluster_set_louv))
	#C.printCluster()
	return cluster_set_louv, cluster_set_ipca, cluster_set_spectral 

def markingPhase(cluster_set, incorrFileList):
	M = Marking("mix")
	cluster_set_rep = M.getSetRepresentative(cluster_set)
	marks = M.grading(incorrFileList)
	M.printMarks()
	return marks
	
folder = sys.argv[1]

print("Compiling C solution programs.....................")

corr_files, incorr_files = get_cfiles(folder)
os.system("rm -rf PDG")
os.system("mkdir PDG")

print("Generating PDGs for correct solutions.....................")

computePDG(True,corr_files)
os.system("mkdir PDG/Main")
os.system("mv PDG/*.main.dot PDG/Main/")
os.system("rm PDG/*.*.dot")
os.system("mv PDG/Main/* PDG/")
os.system("rm -rf PDG/Main")

print("Calculating Similarity Measurements.....................")

similarity_measure_list = similarityPhase(corr_files)

#printSimilarityGraph(similarity_measure_list)

print("Clustering the programs.....................")

cluster_set_louvian, cluster_set_ipca, cluster_set_spectral = clusteringPhase(similarity_measure_list)

#printClusterGraph(cluster_set_louvian,"Louvian")

#printClusterGraph(cluster_set_ipca,"IPCA")

print("Generating PDGs for incorrect solutions.....................")

computePDG(False,incorr_files)

print("Grading the programs.....................")

marks = markingPhase(cluster_set_louvian, incorr_files)

human_clustering_filepath = DATA_PATH + folder + '/clustering_human'
human_marking_filepath = DATA_PATH + folder + '/marks'

purity1 = cluster_purity(cluster_set_louvian, corr_files, human_clustering_filepath)

purity2 = cluster_purity(cluster_set_spectral, corr_files, human_clustering_filepath)

rater_score(human_marking_filepath, marks, incorr_files)

