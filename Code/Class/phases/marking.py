from similarity import Similarity
from random import randint

class Marking(Similarity):
	def __init__(self,ext):
		self.ext = ext
		self.marks = []
		self.cluster_set_rep = []
 
	def getSetRepresentative(self, cluster_set):
		#Randomly select one from each set
		for cluster in cluster_set:
			self.cluster_set_rep.append(cluster[randint(0,len(cluster)-1)])
		return self.cluster_set_rep

	def grading(self, incorrFileList):
		for line1_ind in xrange(len(incorrFileList)):
			file1 = incorrFileList[line1_ind]
			sim_val_list = [] 
			for set_rep in self.cluster_set_rep:
				sim_val_list.append(self.getSimilarity(file1, set_rep))
			max_val = max(sim_val_list)
			self.marks.append((file1, max_val*100))
		return self.marks
	def printMarks(self):
		for mark in self.marks:
			print "Grade of %s is %f"%(mark[0], mark[1])
	
