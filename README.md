# D-spectrum-NDCindex
Software for computing network D-spectrum and NDC index of vertices

This is an instruction on using our softwares for computations related to graph invariants: D-spectrum and NDC indices,
where the former was introduced by Ricky Chen, Andrei Bura and Christian Reidys while the latter was recently introduced by
Ricky Chen and Xin-Yu Liu.

1. In order for obtaining the infection rate (spreading power) of every vertex, one
has to run the code "SIR simulation.exe". The inputs of this software
are the file name specifying one's intested network and one's interested transmission probabilities.
The file name is usually in the form of "xxx_output.txt" (the appearence of "output" is due to some "historic reason"),
listing the edges of the network; the transmission probabilities are in terms of scaling factors of the epidemic
threshold, e.g., one could input 1 2x, meaning the transmission probabilities are set to
1 beta, 2 beta. Note: the scaling factors are separated by spaces and end with 'x' (no space in front of 'x').
The epidemic threshold is read from the file "xxx_output infection threshold.txt".
It produces a file "xxx_output vertex infection rates p(the used transmission probability).txt" listing the spreading power of all vertices for a transmission probability.
Vertices are ordered in the same way for all output files.
Please also refer to the formats of our used networks in the paper.

2. The software "compute NDC index.exe" produces the D-spectra of all vertices, one file for a value of the order t (-maxdegree<= t <=0),
and also produces the DC_t(v) values and NDC_t(v) values (see the paper for definition) of all vertices,
one file for a value of t. Vertices are ordered in the same way for all output files.
The input of this software is the file name of the interested network "xxx_output.txt".

3. The software "compute D-spe.exe" merely produces the D-spectra of all vertices for  -maxdegree <= t <=0, written
into a single file "xxx_output D spe all.txt": a row is for the D-spectra of vertices for a fixed t, and the first row is for t=0, the second row is for t=-1, 
until t=-maxdegree. Vertices are ordered in the same way in all rows.
The input of this software is the file name of the interested network "xxx_output.txt".

4. The software "compute Kendall Tau.cpp" is for computing the Kendall Tau value of a selected index (read from a file "xxx_output index to compare.txt")
and the spreading power of vertices under a transmission probability.



5. The software "comput H-index.exe" is for computing the H-index of all vertices.
The input of this software is the file name of the interested network "xxx_output.txt".

Note 1: for the same network, vertices are ordered in the same way in different softwares.
Note 2: if you use our used networks, please also cite the original sources.
