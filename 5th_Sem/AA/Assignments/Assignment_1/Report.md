# Turing Machines

A Turing machine is a simple model which accepts and rejects languages. It consists of an infinite tape or memory divided into sections that have symbols that can be manipulated according to rules defined by a table. These symbols are called the alphabet of the language. It has a head positioned over one of the sections, the head can read the symbol from the section it is over. Based on the symbol as well as the current state of the system, the machine will decide what to do according to the rules defined in the table.
A Turing machine will accept when the state reaches the final state, and reject when it reaches any other state or goes into an infinite loop, hence any algorithm can be run on a Turing machine and decided whether it is plausible.


# Polynomial and Non-Deterministic Polynomial Class

A Class P or Polynomial Time is a set of decision problems that can be solved in polynomial time. This set is also known as tractable problems.
A Class NP or Non-Deterministic Time is a set of decision problems whose correctness can be verified in polynomial time. A solution to this problem can be verified in polynomial time. The Non-Deterministic term comes from the fact that the input to this set of problems is randomized, and hence the solution to the problem can't be determined. This set is also known as non-tractable problems.


# NP-Completeness

NP-Complete (Non-Deterministic Polynomial Complete) is a collection of problems that belong to the NP Class, whose correctness can be verified in polynomial time, and any other NP problem can be used to solve the given problem with different/modified inputs (Other NP problems can be reduced to this problem in polynomial time). Then the problem is NP-Complete.

# SAT

The SAT or Boolean Satisfiability problem or SATISFIABILITY problem is a problem that determines whether the set of values of a Boolean relation satisfies the Boolean formula. The Boolean formula consists of variables that can take either a TRUE or FALSE value, the SAT problem deals with the value these variables have to take such that the formula evaluates to TRUE after performing all the logical operations.
SAT can be proven to be an NP problem by satisfying the following conditions:

1)	The Boolean formula has randomized inputs for the value of the variables, hence satisfying the non-deterministic nature of NP Class problems.

2)	For a given input, we know that the number of variables in the given formula will be linear. Therefore, evaluating the Boolean formula will require us to find out the answer to every Boolean relation, and as there are n (linear) such relations, it will take linear time to evaluate the given relation, hence satisfying the second condition that the problem should be able to verify in polynomial time.



# Chromatic Numbering

Chromatic numbering is a subproblem of the Graph Coloring problem. A graph coloring problem is a problem of assigning colors to the nodes of a graph such that no two adjacent nodes have the same color. The chromatic number of graph G is the minimum number of colors required to satisfy the Graph Coloring problem. Let's define a number K (< V number of vertices of the graph), K has to be the smallest number possible such that no two adjacent vertices of the graph have the same color.

To prove that a given problem X is NP-Complete, it is required that the X belongs to the NP Class and that any other problem in NP can be reduced to X by modifying the inputs. We know that Chromatic number belongs to NP Class as deciding the value of K is non-deterministic but verifying the same is as simple as running through each node and checking if the adjacent node has a different color which can be done in many ways, hence Chromatic number is NP.

A problem in the same class would be the K-Coloring, which is similar to the Chromatic Number with the difference being that the number of colors is known prior. We can prove that the K-Coloring problem is an NP problem as the time required to verify the given instance is proportional to the number of nodes and the edges in the graph, but allocating the K colors to the graph is not straightforward, and the only possible way to verify the K colors is by randomly assigning a node color and checking whether it satisfies the required conditions.
With this, we can conclude that K-Coloring is NP-Complete.

By choosing K-coloring as the problem which is reduced to a chromatic number, the selection of k for chromatic number can be done in ascending order such that K >= 1

(minimum number of nodes), the non-deterministic nature of the problem is still preserved as for any given k, the assignment of the colors cannot be decided directly, and therefore the first k to satisfy the K-Coloring will be the answer to Chromatic number. We can form a mapping for K-coloring to Chromatic number such that the value K is decided by the randomized selection of colors under Chromatic coloring, since K-coloring is proven to be NP-Complete, we can state that Chromatic number is also NP-Complete.
