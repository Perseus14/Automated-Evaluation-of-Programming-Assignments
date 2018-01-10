import os
import sys

if(len(sys.argv)!=4):
	print "Usage python run.py <c_correct_file> <c_incorrect_file> <similarity_measure_outputfile>"
	exit()

lines_correct = []
lines_incorrect = []

with open(sys.argv[1],"rb") as fin:
	lines_correct = fin.readlines()

with open(sys.argv[2],"rb") as fin:
	lines_incorrect = fin.readlines()

for line_incorrect_ind in xrange(len(lines_incorrect)):
	for line_correct_ind in xrange(len(lines_correct)):
		#print line[:-1] + ref
		#print line[-1]=="\n"
		os.system("/home/perseus/Sem-9/Thesis/Code/Marking/./run.sh " + lines_incorrect[line_incorrect_ind][:-1] + " " + lines_correct[line_correct_ind][:-1] + " " + sys.argv[3]) 
		#os.system("make clean")
