import os
from dot_tools import parse
from dot_tools.dot_graph import SimpleGraph
import warnings
import networkx as nx
from networkx.algorithms import isomorphism
import igraph as ig

warnings.filterwarnings("ignore")

PDG_PATH = "/home/perseus/Academics/Sem-9/Thesis/Code/Class/PDG/"

class Similarity:
	def __init__(self, ext):
		self.ext = ext
		
	def gammaIsomorphism(self, file1, file2):
		def callIsoLad(G1, G2):
			def pathLAD():
				os.system("isoAlgos/./pathLAD -p pattern_file1.txt -t pattern_file2.txt -s 1 -v -f > solution_txt")
				num_lines = sum(1 for line in open('solution_txt'))
				return max(num_lines-2,0)
				
			def VFLib():
				os.system("isoAlgos/./solve_vf pattern_file1.txt pattern_file2.txt 1 > solution_txt")	
				with open("solution_txt",'r') as fin:
					first_line = fin.readline()
					second_line = fin.readline()
				vals = first_line[:-1]
				if(vals=="false" or vals=="aborted"):
					return 0
				else:
					return int(second_line[:-1])		
			
			def glasgow1():
				os.system("isoAlgos/./glasgow glasgow1 pattern_file1.txt pattern_file2.txt --timeout 1 > solution_txt")
				with open("solution_txt",'r') as fin:
					first_line = fin.readline()
					second_line = fin.readline()
				vals = first_line[:-1].split()
				if(vals[0]=="false"):
					return 0
				else:
					count = 0
					for char in second_line:
						if(char == '('):
							count+=1
					return count		

			def glasgow2():
				os.system("isoAlgos/./glasgow glasgow2 pattern_file1.txt pattern_file2.txt --timeout 1 > solution_txt")
				with open("solution_txt",'r') as fin:
					first_line = fin.readline()
					second_line = fin.readline()
				vals = first_line[:-1].split()
				if(vals[0]=="false"):
					return 0
				else:
					count = 0
					for char in second_line:
						if(char == '('):
							count+=1
					return count		

			def glasgow3():
				os.system("isoAlgos/./glasgow glasgow3 pattern_file1.txt pattern_file2.txt --timeout 1 > solution_txt")
				with open("solution_txt",'r') as fin:
					first_line = fin.readline()
					second_line = fin.readline()
				vals = first_line[:-1].split()
				if(vals[0]=="false"):
					return 0
				else:
					count = 0
					for char in second_line:
						if(char == '('):
							count+=1
					return count			
					
			def glasgow4():
				os.system("isoAlgos/./glasgow glasgow4 pattern_file1.txt pattern_file2.txt --timeout 1 > solution_txt")
				with open("solution_txt",'r') as fin:
					first_line = fin.readline()
					second_line = fin.readline()
				vals = first_line[:-1].split()
				if(vals[0]=="false"):
					return 0
				else:
					count = 0
					for char in second_line:
						if(char == '('):
							count+=1
					return count			
	
			def convert_InputFormat(G1, G2):
				#G1 = G1.to_undirected()
				#G2 = G2.to_undirected() #pathLAD seems to work only on undirected graph so converting	
				dict_orig_fake = {}
				dict_fake_orig = {}
				count = 0
				for node in G1.node:
					dict_orig_fake[node] = count
					dict_fake_orig[count] = node
					count+=1
				new_edge_list = {}
				for id1 in xrange(count):
					new_edge_list[id1] = [dict_orig_fake[int(val)] for val in list(G1.edge[dict_fake_orig[id1]])]		
	
				val = max(dict_fake_orig)
				with open("pattern_file1.txt","w") as fin:	
					fin.write("%d\n"%(val+1))
					for x in xrange(count):          
						fin.write("%d %s\n"%(len(new_edge_list[x]), " ".join([str(int(y)) for y in new_edge_list[x]])))

				dict_orig_fake = {}
				dict_fake_orig = {}
				count = 0
				for node in G2.node:
					dict_orig_fake[node] = count
					dict_fake_orig[count] = node
					count+=1
				new_edge_list = {}
				for id1 in xrange(count):
					new_edge_list[id1] = [dict_orig_fake[int(val)] for val in list(G2.edge[dict_fake_orig[id1]])]		
	
				val = max(dict_fake_orig)
				with open("pattern_file2.txt","w") as fin:	
					fin.write("%d\n"%(val+1))
					for x in xrange(count):          
						fin.write("%d %s\n"%(len(new_edge_list[x]), " ".join([str(int(y)) for y in new_edge_list[x]])))
			convert_InputFormat(G1, G2)
			g1 = g2 = g3 = g4 = vf = 0
			p1 = pathLAD()
			if(p1==0):
				g1 = glasgow1()
				if(g1==0):	
					g2 = glasgow2()
					if(g2==0):	
						g3 = glasgow3()
						if(g3==0):	
							g4 = glasgow4()
							if(g4==0):
								vf = VFLib()	
			return max(p1,g1,g2,g3,g4,vf,0)
			
		def genPDG(file1, file2):
			os.system("~/.opam/4.05.0/bin/frama-c -pdg -pdg-dot file1 " + file1)
			os.system("~/.opam/4.05.0/bin/frama-c -pdg -pdg-dot file2 " + file2)
		
		def DOTParser(pdgfile):
			with open(pdgfile,"r") as fin:
				dotStr = fin.read()
				tree = parse(dotStr)
				graph = SimpleGraph.build(tree.kid('Graph'))
			return graph

		def gammaIso(graph1, graph2):
			def InitGraph(nodes, edges):
				G = nx.DiGraph()
				for node in nodes:
					G.add_node(node)
				for edge in edges:
					G.add_edge(edge[0],edge[1])	
				return G
			
			def KFilter(ig1,ig2,K=10,gamma = 0.3):
				#Size-Filter
				if(len(ig1.vs) > K and len(ig2.vs) > K):
					#Filter based on gamma isomorphism criterion
					if((len(ig2.vs) >= gamma*(len(ig1.vs))) and (len(ig1.vs) >= gamma*(len(ig2.vs)))):
						return True
				return False 

			nodes_graph1 = graph1.nodes.keys()
			edges_graph1 = graph1.edges

			nodes_graph2 = graph2.nodes.keys()
			edges_graph2 = graph2.edges
			
			G1 = InitGraph(nodes_graph1,edges_graph1)
			G2 = InitGraph(nodes_graph2,edges_graph2)

			G1.remove_nodes_from(nx.isolates(G1)) #Drop Isolates (Commenting it out as doing it is done in igraph) 
			G2.remove_nodes_from(nx.isolates(G2)) #Drop Isolates

			#Remove self loops
			self_edge_list = G1.selfloop_edges()
			for e in self_edge_list:
				G1.remove_edge(*e)

			self_edge_list = G2.selfloop_edges()
			for e in self_edge_list:
				G2.remove_edge(*e)

			ig1 = ig.Graph(len(G1), [ (int(x),int(y)) for x,y in zip(*zip(*nx.to_edgelist(G1))[:2])], directed=True)                            
			ig2 = ig.Graph(len(G2), [ (int(x),int(y)) for x,y in zip(*zip(*nx.to_edgelist(G2))[:2])], directed=True) 

			ig1.vs.select(_degree = 0).delete() #Drop Isolates
			ig2.vs.select(_degree = 0).delete() #Drop Isolates
			'''
			if(KFilter(ig1, ig2, K=10)):
				sim = 0
				if(len(ig1.vs) > len(ig2.vs)):
					res = ig1.subisomorphic_lad(ig2,return_mapping=True)
				else:
					res = ig2.subisomorphic_lad(ig1,return_mapping=True)	
				if(res[0]):
					sim = (len(res[1]))/float(max(len(ig1.vs), len(ig2.vs))) 	
				return sim
			else:
				return 0
			'''
			if(KFilter(ig1, ig2, K=10)):
				sim = 0
				if(len(ig1.vs) > len(ig2.vs)):
					res = callIsoLad(G2, G1) #pattern < target
				else:
					res = callIsoLad(G1, G2)	
				sim = (res)/float(max(len(ig1.vs), len(ig2.vs))) 	
				return sim
			else:
				return 0
			
		#genPDG(file1, file2)
		similarityValue = 0
		file1_PDG = PDG_PATH + file1.split("/")[-1].split('.')[0][1:] + self.ext + ".main.dot"
		file2_PDG = PDG_PATH + file2.split("/")[-1].split('.')[0][1:] + self.ext + ".main.dot"
		if(os.path.isfile(file1_PDG) and os.path.isfile(file2_PDG)): 
			graph1 = DOTParser(file1_PDG)
			print file1_PDG
			graph2 = DOTParser(file2_PDG)
			print file2_PDG
			similarityValue = gammaIso(graph1, graph2)
			#os.system("rm -f file1.* file2.*")
		return similarityValue		

	def getSimilarity(self, file1, file2):
		return self.gammaIsomorphism(file1, file2)	#Call one similarity measure algo
	
	def getSimilarityFromFilesList(self, file_list):
		similarity_measure_list = []
		for line1_ind in xrange(len(file_list)-1):
			for line2_ind in xrange(line1_ind+1,len(file_list)):
				file1 = file_list[line1_ind]
				file2 = file_list[line2_ind]
				sim_val = self.getSimilarity(file1, file2) 
				similarity_measure_list.append((file1, file2, sim_val)) 
		return similarity_measure_list	#List of Tuples(file1, file2, similarity measure)
