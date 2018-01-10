import os
import sys
import glob

folder = sys.argv[1]
os.system("ls /home/perseus/Sem-9/Thesis/Data/CodeForces/"+folder+"/Correct/*.c > /home/perseus/Sem-9/Thesis/Code/c_file_correct_list") 
os.system("ls /home/perseus/Sem-9/Thesis/Data/CodeForces/"+folder+"/Incorrect/*.c > /home/perseus/Sem-9/Thesis/Code/c_file_incorrect_list") 
#os.system("touch correct_mod_list")
 
with open("/home/perseus/Sem-9/Thesis/Code/c_file_correct_list","rb") as f:
	for line in f.readlines():
		os.system("gcc -std=c11 -o /home/perseus/Sem-9/Thesis/Code/a.out " + line)
		if os.path.isfile("/home/perseus/Sem-9/Thesis/Code/a.out"):
			#print "True", line
			os.system("echo " + line[:-1] + " >> /home/perseus/Sem-9/Thesis/Code/correct_mod_list")
			os.system("rm /home/perseus/Sem-9/Thesis/Code/a.out")	
os.system("mv /home/perseus/Sem-9/Thesis/Code/correct_mod_list /home/perseus/Sem-9/Thesis/Code/c_file_correct_list ")

with open("/home/perseus/Sem-9/Thesis/Code/c_file_incorrect_list","rb") as f:
	for line in f.readlines():
		os.system("gcc -std=c11 -o /home/perseus/Sem-9/Thesis/Code/a.out " + line)
		if os.path.isfile("/home/perseus/Sem-9/Thesis/Code/a.out"):
			#print "True", line
			os.system("echo " + line[:-1] + " >> /home/perseus/Sem-9/Thesis/Code/incorrect_mod_list")
			os.system("rm /home/perseus/Sem-9/Thesis/Code/a.out")	
os.system("mv /home/perseus/Sem-9/Thesis/Code/incorrect_mod_list /home/perseus/Sem-9/Thesis/Code/c_file_incorrect_list ")


