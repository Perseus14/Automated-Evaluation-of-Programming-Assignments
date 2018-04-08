import os
import sys
import subprocess32

test_set = []
code_answer_set = []
actual_answer_set = []

with open("input.in",'r') as fin:
	lines = fin.readlines()
	for line in lines:
		test_set.append(line[:-1])

with open("output.out",'r') as fin:
	lines = fin.readlines()
	for line in lines:
		actual_answer_set.append(line[:-1])
		
with open("program_output.out",'w') as fin:
	os.system("gcc -std=c11 -o a.out " + sys.argv[1] + " -lm")
	for test_case in test_set:
		os.system("echo " + test_case + " > test.test")
		cmd = ["bash","-c","./a.out < test.test > result.result"]
		try:
			subprocess32.call(cmd, timeout = 5)
		except subprocess32.TimeoutExpired:
			code_answer_set.append("Timeout")
			continue	
		with open("result.result",'r') as fout:
			result = fout.readline()
			code_answer_set.append(result.split("\n")[0])
		fin.write("%s"%result)
	os.system("rm -rf test.test result.result")


count=0

for i in xrange(len(test_set)):
	if(code_answer_set[i]==actual_answer_set[i]):
		count+=1

print("Accuracy: %d"%(float(count*100)/len(test_set)))		
