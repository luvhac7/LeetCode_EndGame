topological sort:
->use to solve dag
->use in course seduler
Algorithm

1.Start with an empty list to store the topological order.
2.Pick any unvisited node and perform a DFS from that node.
3.During the DFS traversal, if you encounter a node with node unvisited neighbours, add it to the topological order list.
4.Repeat this process for all unvisited nodes in the graph.

O(V + E)
<img width="1681" height="936" alt="ChatGPT Image Jun 22, 2026, 10_13_56 AM" src="https://github.com/user-attachments/assets/884bbf37-88fb-41d3-813f-e5dddf658711" />
