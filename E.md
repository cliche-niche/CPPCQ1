**Themes:** Dp, brute force, dfs.

Let us convert the problem into formal terms first. These are the correspondences:
+ Student: _Node_
+ Group: _Tree_
+ Friendship: _Edge_ connecting two _nodes_.

We propose to solve this problem using "depth first search" (_dfs_). For reasons that will become clear later, the choice of root node can be taken to be arbitrary, so, _WLOG_, we take _1_ as the root node, and start _dfs_ from this node. 
<br>

We will be storing the maximum sum obtainable from the subtree rooted at node _i (1 &le; i &le; n)_ for the _j<sup>th</sup>_ choice of question made at node _i_ in a 2D array _s_, and denote this sum by _s[i][j]_. Denote marks scored for the _j<sup>th</sup>_ question by _m[j]_.
While traversing, here is what we will do:
+ If node _i_ has no children, then initialise _s[i][j]=w[j]_. 
+ If node _i_ does have children, then recursively use this _dfs_ on all its children. After this, update _s[i]_ by brute force, _s[i][j] = max (&Sigma; s[c][j'])_, under the constraint that _c_ is a child of _i_ and _j'<sub>c<sub>1</sub></sub> &ne; j'<sub>c<sub>2</sub></sub>_ for different _c<sub>1</sub>, c<sub>2</sub>_ and _j'<sub>c</sub>&ne; j_ &forall; _c_.

At the end of _dfs_, _max (S[1][j], 1 &le; j &le; k)_ is the required answer.

**Time complexity:** The time complexity for each node is _O(k<sup>f</sup>)_ due to brute force, so overall complexity is _O(n k<sup>f</sup>)_.