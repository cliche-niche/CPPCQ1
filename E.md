**Themes:** Dp, brute force, dfs.
<br>
<br>
Let us convert the problem into formal terms first. These are the correspondences:
+ Student: _Node_
+ Group: _Tree_
+ Friendship: _Edge_ connecting two _nodes_.
<br>

We propose to solve this problem using "depth first search" (_dfs_). For reasons that will become clear later, the choice of _root_ node can be taken to be arbitrary, so, _WLOG_, we take _1_ as the _root_ node, and start _dfs_ from this node.
<br>

During the _dfs_, let _p_ be the parent of _i<sup>th</sup>_ node and _c_ be a child of _i_. We will store the maximum sum obtainable from _i_ and the subtree rooted at node _i(1<i&le; n)_, subject to _j<sub>p</sub><sup>th</sup>_ choice of question by _p_ and _j<sub>i</sub><sup>th</sup>(&ne;j<sub>p</sub><sup>th</sup>)_ by _i_, and denote this by _s[i][j<sub>p</sub>][j<sub>i</sub>]_. Here is how to compute _s[i][j<sub>p</sub>][j<sub>i</sub>]_:
+ If node _i_ has no children, then initialise _s[i][j<sub>p</sub>][j]=w[j]_ &forall; _1&le;j<sub>p</sub>&ne;j&le;k_.
+ If node _i_ does have children, then recursively use this _dfs_ on all its children. After each child has been visited, update _s[i]_ by brute force, _s[i][j<sub>p</sub>][j<sub>i</sub>] = w[j<sub>i</sub>] + max (&Sigma; s[c][j<sub>i</sub>][j<sub>c</sub>])_, where:
    * _c_ iterates over the children of i.
    * _j<sub>c</sub>_ represents choice of child _c_.
    * _1&le;j<sub>c</sub> , j<sub>i</sub> , j<sub>p</sub>&le; k_ and no two of them are equal.
    * _j'<sub>c<sub>1</sub></sub> &ne; j'<sub>c<sub>2</sub></sub>_ for different _c<sub>1</sub>, c<sub>2</sub>_.

Since, _j<sub>p</sub>_ was used as a dummy in _s[i][j<sub>p</sub>][j<sub>i</sub>]_ and node _1_ is assumed to have no parents (_root_ node), we may update _s[1]_ as such, _s[1][j][j] = w[j] + max (&Sigma; s[c][j][j<sub>c</sub>])_.

At the end of _dfs_, _max (S[1][j][j], 1 &le; j &le; k)_ is the required answer.
<br>
<br>
**Time complexity:** The time complexity for each node is _O(k<sup>f+1</sup>)_ due to brute force, so overall complexity is _O(n&sdot; k<sup>f+1</sup>)_.