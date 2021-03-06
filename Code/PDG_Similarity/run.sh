soln="$1"
ref="$2"
simfilename="$3"
cflow $soln > /home/perseus/Sem-9/Thesis/Code/PDG_Similarity/fun_call_list
python -W ignore /home/perseus/Sem-9/Thesis/Code/PDG_Similarity/FunctionCall/pythonParserCflow.py /home/perseus/Sem-9/Thesis/Code/PDG_Similarity/fun_call_list > /home/perseus/Sem-9/Thesis/Code/PDG_Similarity/parsed_fun_call_list
frama-c -pdg -pdg-dot test $soln
frama-c -pdg -pdg-dot ref $ref
sudo python -W ignore /home/perseus/Sem-9/Thesis/Code/PDG_Similarity/dot_graph/ASTFromDOT.py /home/perseus/Sem-9/Thesis/Code/test.main.dot
sudo python -W ignore /home/perseus/Sem-9/Thesis/Code/PDG_Similarity/dot_graph/ASTFromDOT.py /home/perseus/Sem-9/Thesis/Code/ref.main.dot
python -W ignore /home/perseus/Sem-9/Thesis/Code/PDG_Similarity/gamma_iso/gammaIso_iGraph.py /home/perseus/Sem-9/Thesis/Code/test.pickle /home/perseus/Sem-9/Thesis/Code/ref.pickle > /home/perseus/Sem-9/Thesis/Code/PDG_Similarity/similarity
filename="/home/perseus/Sem-9/Thesis/Code/PDG_Similarity/similarity"
while read -r line
do
    val="$line"
    echo $soln $ref $val >> $simfilename
done < "$filename"

