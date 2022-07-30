//package com.company;
//
//class MyHashMap {
//
//    static class ListNode {
//        int key, value;
//        ListNode next; // Direct chaining
//
//        ListNode(int key, int val) {
//            this.key = key;
//            this.value = val;
//        }
//    }
//
//    static class HashIndexList {
//        ListNode head, tail;
//    }
//
//    private int getHashCode(int key) {
//        return key % size;
//    }
//
//    private final int size = 10000;
//
//    HashIndexList[] hashlist = new HashIndexList[size];
//    public MyHashMap() {
//        for (int i = 0;i<size;++i) {
//            hashlist[i] = new HashIndexList();
//            hashlist[i].head = null;
//            hashlist[i].tail = null;
//        }
//    }
//
//    public void put(int key, int value) {
//        int idx = getHashCode(key);
//        ListNode node = new ListNode(key,value);
//        ListNode list = hashlist[idx].head;
//        if(list == null)
//        {
//            hashlist[idx].head = node;
//            hashlist[idx].tail = node;
//        }else{
//            node.next = hashlist[idx].head;
//            hashlist[idx].head = node;
//        }
//    }
//
//    ListNode find(ListNode node, int key) {
//        return null;
//    }
//
//    public int get(int key) {
//        return key;
//    }
//
//    public void remove(int key) {
//
//    }
//
//    public static void main(String[] args) {
//        MyHashMap map = new MyHashMap();
//    }
//}