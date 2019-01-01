# Automated-Evaluation-of-Programming-Assignments

This repo contains the code for the Automated-Evaluation-of-Programming-Assignments project.

## Installation

### Requirements
+ os, sys, glob, pickle, random
+ warnings, netwowrkx(1.11), [igraph(0.7.1)](http://igraph.org/python/ "python-igraph"), [dot_tools](https://github.com/timtadh/dot_tools.git "Dot Parser Tool in Python")
+ community(python-louvain), itertools, collection
+ numpy, sklearn, nltk
+ matplotlib

A [script](./Code/Class/script.sh) is included to download most of the packages

## DataSet Generation

Dataset is downloaded from [CodeForces](codeforces.com "CodeForces"), a platform for competitive programming.

Given a contest id, this script downloads all correct and incorrect  _Java_ solutions.

### Execution
```
 python cf_script.py
```

Solutions will be downloaded in a CodeForces folder in the same directory in which the code is run.

_Contest ID_  
   -  _Correct_  
      - A1.c  
      - A2.c  
   -  _Incorrect_  
      - A1.c  
      - A2.c 

### Requirements

+ urllib  
+ json   


## Execution

```
 python eval.py <folder-name>

```
