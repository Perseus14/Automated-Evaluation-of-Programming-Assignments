import sys
import pickle

cluster_set_elements = []

with open(sys.argv[1],"rb") as fin:
	cluster_set_elements = pickle.load(fin)

for cluster_id in xrange(len(cluster_set_elements)):
	#print cluster_id, dict_incorr_val[incorr_files]
	print "Cluster ID:",cluster_id, cluster_set_elements[cluster_id],"\n"

