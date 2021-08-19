**Themes:** Dp, brute force, dfs.

Let us convert the problem into formal terms first. These are the correspondences:
+ Student: $Node$
+ Group: $Tree$
+ Friendship: $Edge$ connecting two $nodes$.

We propose to solve this problem using "depth first search" ($dfs$). For reasons that will become clear later, the choice of root node can be taken to be arbitrary, so, $WLOG$, we take $1$ as the root node, and start the $dfs$ from this node. 
<br>

We will be storing the maximum sum obtainable from the subtree rooted at node $i (1\leq i\leq n)$ for the $j^{th}$ choice of question made at node $i$ in a 2D array $s$, and denote this sum by $s[i][j]$. Denote marks scored for the $j^{th}$ question by $k[j]$.
While traversing, here is what we will do:
+ If node $i$ has no children, then initialise $s[i][j]=k[j]$. 
+ If node $i$ does have children, then recursively use this $dfs$ on all its children. After this update $s[i]$ by brute force, $s[i][j] = \max\sum s[c][j']$, under the constraint that $c$ is a child of $i$ and $j'_{c_1}\neq j'_{c_2}$ for different $c1, c2$ and $j'_c\neq j$ $\forall$ $c$.

At the end of $dfs$, $\max_{j\in k} S[1][j]$ is the required answer.

**Time complexity:** The time complexity for each node is $O(k^f)$ due to brute force, so overall complexity is $O(n\cdot k^f)$.