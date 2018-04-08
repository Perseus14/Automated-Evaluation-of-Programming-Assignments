# Automated-Evaluation-of-Programming-Assignments

This repo contains the code for the Automated-Evaluation-of-Programming-Assignments project.

## Installation

###Requirements
+ os, sys, glob, pickle, random
+ warnings, netwowrkx(1.11), igraph(0.7.1), dot_tools
+ community(python-louvain), itertools, collection
+ numpy, sklearn, nltk
+ matplotlib
+ Boost Libraries with Threads (1.65.1) 

A [script](../blob/master/Code/Class/script.sh) is included to download most of the packages, Boost needs to be separately installed.

##DataSet Generation

Dataset is downloaded from [CodeForces](codeforces.com "CodeForces"), a platform for competitive programming.

Given a contest id, this script downloads all correct and incorrect  _Java_ solutions.

###Execution
```
 python cf_script.py
```

Solutions will be downloaded in a CodeForces folder in the same directory in which the code is run.

###Requirements

+ urllib  
+ json   


## Execution

python eval.py <folder name of solution>

Solution
   - Correct
      - 1.c
      - 2.c
   - Incorrect
      - 1.c
      - 2.cc