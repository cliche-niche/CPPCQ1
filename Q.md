## **Take Home**
Professor MA being a maverick has given your class a take home end-semester examination. There are _k_ questions in the end-semester exam and they are worth different marks. There are _n_ students in the class, with each person having at least _1_ friend (if _n>1_) and at most _f_ friends.

Prof. MA knows about this, and makes a couple of assumptions. He assumes that if _A_ and _B_ are friends, and _A_ and _C_ are friends, then none of them do the same question, and _B_ and _C_ are not friends. He also assumes that each student will attempt to solve only one question, because they know everyone is getting an `A` grade anyway.

Under these assumptions, he wants to know the maximum cumulative score the class can get, but since he is so busy, he asks for your help. Can you help him?

### **Input**
The first line contains three integers, _n_, _f_, and _k_ (_1 &le; n &le; 5&sdot;10<sup>3</sup>_, _2 &le; f &le; 4_, _f < k &le; 10_), the number of students, maximum number of friends one can have, and the total number of questions, respectively.

The next _n-1_ lines contain two integers _u_ and _v_ (_1 &le; u, v &le; n_), meaning that students with these roll numbers are friends.

The last line of the input contains _k_ integers _m<sub>1</sub>, m<sub>2</sub>, ..., m<sub>k</sub>_ (_1 &le; m<sub>i</sub> &le; 1000_) where _m<sub>i</sub>_ is the marks for the _i<sup>th</sup>_ question.

### **Output**
Output a single integer, the maximum sum of marks the class can score.

### **Example**

| Input |
---
```
4 3 5
1 2
1 3
1 4
1 2 3 4 5
```
| Output |
---
```
14
```
<br>
<br>

| Input |
---
```
1 3 4
1 4 10 64
```
| Output |
---
```
64
```

### **Explanation**
In sample input #1, the friend group looks like this-

![Friend group](./Ex.png)

Students _1, 2, 3, 4_ can solve questions worth _5, 4, 3,_ and _2_ respectively, to get a cumulative score of _5+4+3+2=14_ marks