similarity:
	python /home/perseus/Sem-9/Thesis/Code/PDG_Similarity/run.py /home/perseus/Sem-9/Thesis/Code/c_file_correct_list /home/perseus/Sem-9/Thesis/Code/similarity_measure_file

cluster:
	python /home/perseus/Sem-9/Thesis/Code/Clustering/cluster.py /home/perseus/Sem-9/Thesis/Code/similarity_measure_file

marking:
	python /home/perseus/Sem-9/Thesis/Code/Marking/similarity_incorr_cluster.py /home/perseus/Sem-9/Thesis/Code/c_file_incorrect_list

marking1:
	python /home/perseus/Sem-9/Thesis/Code/Marking/run.py /home/perseus/Sem-9/Thesis/Code/c_file_correct_list /home/perseus/Sem-9/Thesis/Code/c_file_incorrect_list /home/perseus/Sem-9/Thesis/Code/similarity_measure_file_incorrect

marking2:
	python /home/perseus/Sem-9/Thesis/Code/Marking/cluster_incorrect.py /home/perseus/Sem-9/Thesis/Code/similarity_measure_file_incorrect 

clean:
	rm -f ref.* test.*
delete:
	rm -f c_file_* similarity_measure_file* cluster.pickle cluster_w_incorrect.pickle
