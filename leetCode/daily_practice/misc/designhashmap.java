class MyHashMap {

    class ListNode{
        int key,value;
        ListNode(int key,int val){
            this.key = key;
            this.value = val;
        }
    }
    ListNode[] nodes;
    public MyHashMap() {
        nodes = new ListNode[10000];
    }
    
    public void put(int key, int value) {
        int idx = key % nodes.length;

    }
    
    public int get(int key) {
        
    }
    
    public void remove(int key) {
        
    }

    public static void main(String[] args) {
        System.out.println("Hello");
    }
}