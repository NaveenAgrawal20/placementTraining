package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;

/*
 ** Created on 4/27/2022 by Naveen
 */
public class Dijkstra {
    static class Edge implements Comparable<Edge>{
        int v,wt;
        Edge(int v,int wt)
        {
            this.v = v;
            this.wt = wt;
        }

        @Override
        public int compareTo(Edge o) {
            return this.wt - o.wt;
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int vtces = Integer.parseInt(br.readLine());
        ArrayList<Edge>[] graph = new ArrayList[vtces];
        for(int i = 0;i<vtces;i++)
            graph[i] = new ArrayList<>();

        int edges = Integer.parseInt(br.readLine());
        for(int i = 0;i<edges;++i)
        {
            String[] parts = br.readLine().split(" ");
            int v1 = Integer.parseInt(parts[0]);
            int v2 = Integer.parseInt(parts[1]);
            int wt = Integer.parseInt(parts[2]);
            graph[v1].add(new Edge(v2,wt));
            graph[v2].add(new Edge(v1,wt));
        }
        
        int src = Integer.parseInt(br.readLine());
        /*------------- Input Completed------------------------*/

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(src,0));

        boolean[] visited = new boolean[vtces];
        int[] dist = new int[vtces];
        for (int i = 0;i<vtces;++i)
            dist[i] = Integer.MAX_VALUE;

        dist[src] = 0;
        while(!pq.isEmpty())
        {
            Edge edge = pq.remove();
            if(visited[edge.v])
                continue;
            visited[edge.v] = true;

            for(Edge e:graph[edge.v])
            {
                int newDist = e.wt + dist[edge.v];
                if(!visited[e.v] && newDist < dist[e.v]){
                    pq.add(new Edge(e.v,newDist));
                }
            }
        }
        for (int i = 0;i<vtces;++i)
        {
            System.out.println(src+" to "+i+" :"+dist[i]);
        }
    }
}
