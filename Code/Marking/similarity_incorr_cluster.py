import sys
import os
import pickle

cluster_set_elements = []
similarity_measure = []

dict_incorr_val = {}
dict_incorr_val_list = {}

def get_similarity(file1, file2):
	os.system("frama-c -pdg -pdg-dot test " + file1)
	os.system("frama-c -pdg -pdg-dot ref " + file2)
	os.system("python -W ignore /home/perseus/Sem-9/Thesis/Code/PDG_Similarity/dot_graph/ASTFromDOT.py /home/perseus/Sem-9/Thesis/Code/test.main.dot")
	os.system("python -W ignore /home/perseus/Sem-9/Thesis/Code/PDG_Similarity/dot_graph/ASTFromDOT.py /home/perseus/Sem-9/Thesis/Code/ref.main.dot")
	os.system("python -W ignore /home/perseus/Sem-9/Thesis/Code/PDG_Similarity/gamma_iso/gammaIso_iGraph.py /home/perseus/Sem-9/Thesis/Code/test.pickle /home/perseus/Sem-9/Thesis/Code/ref.pickle > /home/perseus/Sem-9/Thesis/Code/Marking/similarity")
	val = 0	
	with open("/home/perseus/Sem-9/Thesis/Code/Marking/similarity","rb") as fin:
		for line in fin.readlines():
			val = float(line)
	return val

with open("/home/perseus/Sem-9/Thesis/Code/cluster.pickle","rb") as fin:
	cluster_set_elements = pickle.load(fin)

with open(sys.argv[1],"rb") as fin:
	for line in fin.readlines():
		incorr_file = line[:-1]
		sim_measure = []
		for sets in cluster_set_elements:
			corr_file = sets[0] #Get set representative
			sim_measure.append(get_similarity(corr_file, incorr_file))
		ans_id = -1	
		max_val = max(sim_measure)
		for id1 in xrange(len(sim_measure)): 
			if(sim_measure[id1]==max_val):
				ans_id = id1				
				break
		cluster_set_elements[ans_id].append(incorr_file)
		print ans_id, incorr_file			

with open("/home/perseus/Sem-9/Thesis/Code/cluster_w_incorrect.pickle","wb") as fin:
	pickle.dump(cluster_set_elements,fin)		
