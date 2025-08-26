#file [[Cây B]]

## **Pseudo code**
```
1: procedure B-Tree-Insert (Node x, Key k)  
2: find i such that x:keys[i] > k or i >=numkeys(x)  
3: if x is a leaf then  
4: Insert k into x.keys at i  
5: else  
6: if x:child[i] is full then  
7: Split x:child[i]  
8: if k > x:key[i] then  
9: i = i + 1  
10: end if  
11: end if  
12: B-Tree-Insert(x:child[i]; k)  
13: end if  
14: end procedure
```

## **Thực hiện thuật toán**
``` cpp

```