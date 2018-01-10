import csv
from matplotlib import pyplot as plt
import glob

for folder in glob.glob('simulate-csv/dim2/output-t4-d2_*.csv'): #"output_test.csv"):#
	L=[]
	print folder
	with open(folder, 'rb') as csvfile:
		spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
		for row in spamreader:
			L.append([','.join(row)])

	new_L=[]
	for x in L:
		new_L.append([map(float,z.split('/')) for z in x[0].split(',')[1:]])

	new_x=[]
	for x in L:
		new_x.append(x[0].split(',')[0])

	legends=['']*len(new_L)
	if(len(new_L[0][0])==2):
		for x in xrange(len(new_L)):
			xplt = [z[0] for z in new_L[x]]
			yplt = [z[1] for z in new_L[x]]
			legends[x],=plt.plot(xplt, yplt, label = new_x[x])
			plt.plot(xplt[0],yplt[0], marker='x', markersize=15,color="black")
			plt.plot(xplt[-1],yplt[-1], marker='o', markersize=3,color="black")	
		plt.xlabel('X position')
		plt.ylabel('Y Position')
	else:
		for x in xrange(len(new_L)):
			xplt = [z[0] for z in new_L[x]]
			legends[x],=plt.plot(xplt,label = new_x[x])
			plt.plot(xplt[0],marker='x', markersize=15,color="black")
			plt.plot(xplt[-1], marker='o', markersize=3,color="black")	
		plt.xlabel('Simulation')
		plt.ylabel('Position') 
	plt.legend(legends,new_x,bbox_to_anchor=(1.15, 1))
	#plt.show()
	r = folder.split('.csv')[0].split('_')[1]
	a = folder.split('.csv')[0].split('_')[2]
	f = folder.split('.csv')[0].split('_')[3]
	
	if(len(new_L[0][0])==2):
		plt.title('Simulations of Forces between 7 nodes in 2D with r = '+str(r)+' a = '+str(a)+' f = '+str(f))
	else:
		plt.title('Simulations of Forces between 7 nodes in 1D with r = '+str(r)+' a = '+str(a)+' f = '+str(f))	
	
	plt.savefig("simulate-png/dim2/"+folder.split('.csv')[0].split('/')[-1]+'.png')
	plt.close()
	print folder.split('.csv')[0]
	print "Finished " + folder.split('/')[1].split('.')[0]
