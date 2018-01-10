import glob
import os

DATA_PATH = "/home/perseus/Academics/Sem-9/Thesis/Data/CodeForces/"

def get_cfiles():
	files = glob.glob(DATA_PATH+"*/*/*.c")
	temp_files = []
	for file in files:
		os.system("gcc -std=c11 -o a.out " + file)
		if os.path.isfile("a.out"):
			temp_files.append(file)
			os.system("rm a.out")
	files = temp_files

	temp_files = []	
	for file in files:
		os.system("~/.opam/4.05.0/bin/frama-c -machdep x86_64 -cpp-command 'gcc -C -E -std=c99 -I. ' -pdg -pdg-dot file1 " + file)
		if os.path.isfile("file1.main.dot"):
			temp_files.append(file)
			os.system("rm *.dot")
	files = temp_files
	return files


