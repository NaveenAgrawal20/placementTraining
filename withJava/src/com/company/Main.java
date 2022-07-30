package com.company;

class MyHashMap {

    // Direct chaining
    static class ListNode {
        int key, value;
        ListNode next;

        ListNode(int key, int val) {
            this.key = key;
            this.value = val;
        }
    }

    ListNode[] nodes;

    private int getHashCode(int key) {
        return key % size;
    }

    private final int size = 10000;

    public MyHashMap() {
        nodes = new ListNode[size];
        for (int i = 0; i < size; ++i) {
            nodes[i] = new ListNode(-1, -1); // dummy head;
        }
    }

    public void put(int key, int value) {
        int idx = getHashCode(key);

        ListNode previousNode = find(nodes[idx], key);
        if (previousNode.next == null) {
            previousNode.next = new ListNode(key, value);
        }
        // for updating existing node
        previousNode.next.value = value;
    }

    private ListNode find(ListNode node, int key) {
        ListNode crawl = node, prev = null;
        while (crawl != null && crawl.key != key) {
            prev = crawl;
            crawl = crawl.next;
        }
        return prev;
    }

    public int get(int key) {
        int idx = getHashCode(key);
        if (nodes[idx] == null)
            return -1;
        ListNode prev = find(nodes[idx], key);
        if (prev.next == null)
            return -1;
        return prev.next.value;
    }

    public void remove(int key) {
        int idx = getHashCode(key);
        if (nodes[idx] == null)
            return;
        ListNode prev = find(nodes[idx], key);
        if (prev.next != null)
            prev.next = prev.next.next;
    }

    public static void main(String[] args) {
        MyHashMap mp = new MyHashMap();
        mp.put(1, 1);
        mp.put(2, 2);
        System.out.println(mp.get(1));
        mp.put(2, 1);

    }
}