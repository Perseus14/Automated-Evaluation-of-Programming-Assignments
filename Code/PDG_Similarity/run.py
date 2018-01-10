import os
import sys

with open(sys.argv[1],"rb") as fin:
	lines = fin.readlines()
	for line1_ind in xrange(len(lines)-1):
		for line2_ind in xrange(line1_ind+1,len(lines)):
		#print line[:-1] + ref
		#print line[-1]=="\n"
			os.system("/home/perseus/Sem-9/Thesis/Code/PDG_Similarity/./run.sh " + lines[line1_ind][:-1] + " " + lines[line2_ind][:-1] + " " + sys.argv[2]) 
			#os.system("make clean")
