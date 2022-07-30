class Edge:
    def __init__(self,src,dest,wt):
        self.src = src
        self.dest = dest
        self.wt = wt

class Krushkal:
    def getSet(self,node,vertexSet):
        if node == vertexSet[node]:
            return node
        return self.getSet(vertexSet[node],vertexSet)

    def solution(self,graph,n):
        graph.sort(key = lambda ed:ed.wt)

        vertexSet = [x for x in range(n)]
        result = []
        count = 0
        i = 0
        while count < n-1:
            currentEdge = graph[i]
            uSet = self.getSet(currentEdge.src,vertexSet)
            vSet = self.getSet(currentEdge.dest,vertexSet)
            if uSet != vSet:
                result.append(currentEdge)
                count+=1
                vertexSet[vSet] = uSet
            
            i+=1
        return result

graph = []
n,e = [int(x) for x in input().split()]
for i in range(e):
    src,dest,wt = [int(x) for x in input().split()]
    graph.append(Edge(src,dest,wt))

krushkal = Krushkal()
res = krushkal.solution(graph,n)
for ed in res:
    print(ed.src,"->",ed.dest," = ",ed.wt)
"""
7 9
0 5 10
5 4 15
4 3 12
3 2 2
2 1 6
1 0 18
1 6 4
6 3 8
6 4 14
"""