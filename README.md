# Breadth First Search

The algorithm for Breadth First Traversal along with the applications to find shortest path and computing undirected connectivity.

Traversal Algorithm :-

1.  mark start vertex s as explored and insert it in a Queue. initialize a list of booleans to mark if a node is visited.
2.  while the Queue is not empty:-
3.    remove the 1st node in the queue, call it v.
4.    for each edge in nodes adjacent to q (v, w)
5.      if w is unexplored
6.        mark w as explored and add it to the queue.

Application 1, distance information :-

1.  Compute dist(v) i.e. fewest no of edges on a path from s to v.
2.  intialize dist(v) = 0 if v = s, infinity otherwise.
3.  Traverse graph from s as above. While considering edges(v,w)
4.  if w is unexplored, then set dist(w) = dist(v) + 1

At termination, dist(v) = k <=> v is in kth layer i.e. shortest path from s to v has k edges.

Application 2, undirected connectivity :-

1.  mark all nodes unexplored
2.  for i = 1 to n
3.    if i is not yet explored
4.      traverse(i) remembering all the nodes and marking all the visited nodes.